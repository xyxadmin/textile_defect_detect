#include "camerinfer.h"

CamerInfer::CamerInfer(QObject *parent)
    : QObject{parent}
{

    memset(&src_image, 0, sizeof(image_buffer_t));
    memset(&rknn_app_ctx, 0, sizeof(rknn_app_context_t));
    ret = init_yolov8_model(model_path, &rknn_app_ctx);
    if (ret != 0)
    {
        printf("init_yolov8_model fail! ret=%d model_path=%s\n", ret, model_path);
    }
    m_cap.open(22);
    m_timer = new QTimer(this);
    m_cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    m_cap.set(cv::CAP_PROP_FRAME_HEIGHT, 640);

    if (!m_cap.isOpened()) {
        std::cerr << "Failed to open the camera." << std::endl;
        return;
    }

    connect(m_timer, &QTimer::timeout, this, &CamerInfer::processFrame);
    m_timer->start(45);
    init_post_process();
}

void CamerInfer::processFrame()
{
    m_cap.read(src_frame);
    if (src_frame.empty()) {
        std::cerr << "Failed to grab frame from the camera." << std::endl;
        return;
    }

    cv::rotate(src_frame, src_frame, cv::ROTATE_90_COUNTERCLOCKWISE);
    src_image.height = src_frame.rows;
    src_image.width = src_frame.cols;
    src_image.width_stride = src_frame.step[0];
    src_image.virt_addr = src_frame.data;
    src_image.format = IMAGE_FORMAT_RGB888;
    src_image.size = src_frame.total() * src_frame.elemSize();


    rknn_input inputs[rknn_app_ctx.io_num.n_input];
    rknn_output outputs[rknn_app_ctx.io_num.n_output];
    memset(&od_results, 0x00, sizeof(od_results));
    memset(&letter_box, 0, sizeof(letterbox_t));
    memset(&dst_img, 0, sizeof(image_buffer_t));
    memset(inputs, 0, sizeof(inputs));
    memset(outputs, 0, sizeof(outputs));
    // Pre Process
    dst_img.width = rknn_app_ctx.model_width;
    dst_img.height = rknn_app_ctx.model_height;
    dst_img.format = IMAGE_FORMAT_RGB888;
    dst_img.size = get_image_size(&dst_img);
    dst_img.virt_addr = (unsigned char *)malloc(dst_img.size);
    if (dst_img.virt_addr == NULL)
    {
        printf("malloc buffer size:%d fail!\n", dst_img.size);
        return;
    }

    // letterbox
    ret = convert_image_with_letterbox(&src_image, &dst_img, &letter_box, bg_color);
    if (ret < 0)
    {
        printf("convert_image_with_letterbox fail! ret=%d\n", ret);
        return;
    }
    // Set Input Data
    inputs[0].index = 0;
    inputs[0].type = RKNN_TENSOR_UINT8;
    inputs[0].fmt = RKNN_TENSOR_NHWC;
    inputs[0].size = rknn_app_ctx.model_width * rknn_app_ctx.model_height * rknn_app_ctx.model_channel;
    inputs[0].buf = dst_img.virt_addr;

    ret = rknn_inputs_set(rknn_app_ctx.rknn_ctx, rknn_app_ctx.io_num.n_input, inputs);
    if (ret < 0)
    {
        printf("rknn_input_set fail! ret=%d\n", ret);
        return;
    }
    free(dst_img.virt_addr);

    // Run
    //printf("rknn_run\n");
    //ret = rknn_run(rknn_app_ctx.rknn_ctx, nullptr);
    // Run
    printf("rknn_run\n");
    ret = rknn_run(rknn_app_ctx.rknn_ctx, nullptr);
    if (ret < 0)
    {
        printf("rknn_run fail! ret=%d\n", ret);
        return;
    }

    // if (ret < 0)
    // {
    //     printf("rknn_run fail! ret=%d\n", ret);
    //     return;
    // }

    // Get Output
    memset(outputs, 0, sizeof(outputs));
    for (int i = 0; i < rknn_app_ctx.io_num.n_output; i++)
    {
        outputs[i].index = i;
        outputs[i].want_float = (!rknn_app_ctx.is_quant);
    }
    ret = rknn_outputs_get(rknn_app_ctx.rknn_ctx, rknn_app_ctx.io_num.n_output, outputs, NULL);

    // Post Process
    post_process(&rknn_app_ctx, outputs, &letter_box, box_conf_threshold, nms_threshold, &od_results);
    // Remeber to release rknn output
    rknn_outputs_release(rknn_app_ctx.rknn_ctx, rknn_app_ctx.io_num.n_output, outputs);

    // Post Process
    //post_process(&rknn_app_ctx, outputs, &letter_box, box_conf_threshold, nms_threshold, &od_results);

    // Remeber to release rknn output
    //rknn_outputs_release(rknn_app_ctx.rknn_ctx, rknn_app_ctx.io_num.n_output, outputs);

    // 画框和概率
    if(isDetection){
        // std::thread visual_draw_thread([&]{
        //     visiual_draw();
        // });
        // visual_draw_thread.join();

        visiual_draw();

    }
    fps =calculateFPS();
    emit frameProcessed(confidences,fps);
    result_mat = cv::Mat(src_image.height, src_image.width, CV_8UC3, src_image.virt_addr, src_image.width_stride);
    //cv::resize(result_mat,result_mat,cv::Size(480,640));
    cv::cvtColor(result_mat,result_mat,cv::COLOR_BGR2RGB);
    out = QImage((const uchar*)result_mat.data, result_mat.cols, result_mat.rows, result_mat.step,QImage::Format_RGB888);
    //out = QImage((const uchar*)result_mat.data, result_mat.cols, result_mat.rows, result_mat.step,QImage::Format_RGB888);
    //ui->label->setPixmap(QPixmap::fromImage(out).scaled(ui->label->size()));
    showOnLabel(out);
    //cv::putText(result_mat,std::to_string(fps),cv::Point(50,50),cv::FONT_HERSHEY_SIMPLEX,2,cv::Scalar(255,0,255))
    confidences.clear();
}

void CamerInfer::stopProcessing()
{
    //m_timer->stop();
    m_cap.release();
    deinit_post_process();
    ret = release_yolov8_model(&rknn_app_ctx);
    if (ret != 0)
    {
        printf("release_yolov8_model fail! ret=%d\n", ret);
    }

    if (src_image.virt_addr != NULL)
    {
        free(src_image.virt_addr);
    }
}

void CamerInfer::set_label(QLabel *label)
{
    this->label = label;
}

void CamerInfer::showOnLabel(QImage img)
{
    if(label && !img.isNull()){
        label->setPixmap(QPixmap::fromImage(img).scaled(label->size()));
    }
}

void CamerInfer::isOpenCap(bool flag)
{
    if(flag){

    }else{
        this->label = new QLabel();
    }
}

void CamerInfer::isOpenDetec(bool flag)
{
    this->isDetection = flag;
}

void CamerInfer::visiual_draw()
{
    char text[256];
    for (int i = 0; i < od_results.count; i++)
    {

        object_detect_result *det_result = &(od_results.results[i]);
        printf("%s @ (%d %d %d %d) %.3f\n", coco_cls_to_name(det_result->cls_id),
               det_result->box.left, det_result->box.top,
               det_result->box.right, det_result->box.bottom,
               det_result->prop);
        int x1 = det_result->box.left;
        int y1 = det_result->box.top;
        int x2 = det_result->box.right;
        int y2 = det_result->box.bottom;
        confidences.append(det_result->prop*100);
        draw_rectangle(&src_image, x1, y1, x2 - x1, y2 - y1, COLOR_RED, 4);
        sprintf(text, "%s %.1f%%", coco_cls_to_name(det_result->cls_id), det_result->prop * 100);
        draw_text(&src_image, text, x1, y1 - 20,  COLOR_BLUE, 12);
        if(det_result->cls_id == 2){
            emit get_cls_id(2);
        }
    }
}

double CamerInfer::calculateFPS() {
    static int frameCount = 0;
    static double startTime = cv::getTickCount();
    frameCount++;

    // 每100帧计算一次帧率
    if (frameCount % 1 == 0) {
        double endTime = cv::getTickCount();
        double elapsedTime = (endTime - startTime) / cv::getTickFrequency();
        double fps = 1 / elapsedTime;

        // 重置时间和帧数
        startTime = endTime;
        frameCount = 0;

        return fps;
    }

    return -1; // 未达到计算帧率的帧数，返回 -1
}

#ifndef CAMERINFER_H
#define CAMERINFER_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QImage>
#include <QLabel>
#include <QVector>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QFuture>
#include <QtConcurrent>

#include "yolov8.h"
#include "image_utils.h"
#include "file_utils.h"
#include "image_drawing.h"
#include <opencv2/opencv.hpp>

class CamerInfer : public QObject
{
    Q_OBJECT
public:
    explicit CamerInfer(QObject *parent = nullptr);
private:
    double calculateFPS();

public slots:
    void processFrame();
    void stopProcessing();
public:
    void set_label(QLabel* label);
    void showOnLabel(QImage img);
    void isOpenCap(bool flag);
    void isOpenDetec(bool flag);
signals:
    void frameProcessed(QVector<float> confidences, double fps);
    void get_cls_id(int id);
private:
    const char *model_path = "/usr/model/251015.rknn";
    cv::VideoCapture m_cap;
    bool m_stopFlag = false;
    QElapsedTimer m_fpsTimer;
    int m_frameCount = 0;
    double m_fps = 0.0;
    cv::Mat src_frame;
    image_buffer_t src_image;
    rknn_app_context_t rknn_app_ctx;
    object_detect_result_list od_results;
    int ret;
    QLabel* label;
    bool isDetection;
    image_buffer_t dst_img;
    letterbox_t letter_box;
    const float nms_threshold = NMS_THRESH;      // 默认的NMS阈值
    const float box_conf_threshold = BOX_THRESH; // 默认的置信度阈值
    int bg_color = 114;
    double fps = 0.0;
    QImage out;
    cv::Mat result_mat;
    QVector<float> confidences;

private:
    void visiual_draw();
public:
    QTimer* m_timer;

signals:
};

#endif // CAMERINFER_H

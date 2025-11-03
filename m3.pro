QT       += core gui charts network concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    3rdparty/allocator/dma/dma_alloc.cpp \
    3rdparty/allocator/drm/drm_alloc.cpp \
    camerinfer.cpp \
    chartshow.cpp \
    datetime.cpp \
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    postprocess.cpp \
    shellcontroller.cpp \
    tcpserver.cpp \
    utils/file_utils.c \
    utils/image_drawing.c \
    utils/image_utils.c \
    yolov8.cpp \

HEADERS += \
    3rdparty/allocator/dma/dma_alloc.h \
    3rdparty/allocator/dma/dma_alloc.hpp \
    camerinfer.h \
    chartshow.h \
    datetime.h \
    lib/librkllm_api/include/rkllm.h \
    mainwindow.h \
    mybutton.h \
    shellcontroller.h \
    tcpserver.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



INCLUDEPATH += $$PWD/3rdparty/allocator/drm
INCLUDEPATH += $$PWD/3rdparty/stb_image
INCLUDEPATH += $$PWD/utils


unix:!macx: LIBS += -L$$PWD/3rdparty/jpeg_turbo/Linux/aarch64/ -lturbojpeg

INCLUDEPATH += $$PWD/3rdparty/jpeg_turbo/include
DEPENDPATH += $$PWD/3rdparty/jpeg_turbo/include



INCLUDEPATH += /opt/atk-dlrk3588-toolchain/aarch64-buildroot-linux-gnu/sysroot/usr/include/opencv4
LIBS += -L/opt/atk-dlrk3588-toolchain/aarch64-buildroot-linux-gnu/sysroot/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs -lopencv_dnn


unix:!macx: LIBS += -L$$PWD/3rdparty/librga/Linux/aarch64/ -lrga

INCLUDEPATH += $$PWD/3rdparty/librga/include
DEPENDPATH += $$PWD/3rdparty/librga/include

HEADERS += \
    3rdparty/allocator/dma/dma_alloc.h \
    3rdparty/allocator/dma/dma_alloc.hpp \
    3rdparty/allocator/drm/drm.h \
    3rdparty/allocator/drm/drm_alloc.h \
    3rdparty/allocator/drm/drm_alloc.hpp \
    3rdparty/allocator/drm/drm_fourcc.h \
    3rdparty/allocator/drm/drm_mode.h \
    3rdparty/allocator/drm/xf86drm.h \
    3rdparty/stb_image/stb_image.h \
    3rdparty/stb_image/stb_image_write.h \
    postprocess.h \
    utils/common.h \
    utils/file_utils.h \
    utils/font.h \
    utils/image_drawing.h \
    utils/image_utils.h \
    yolov8.h



unix:!macx: LIBS += -L$$PWD/../cpp/3rdparty/rknpu2/Linux/aarch64/ -lrknnrt

INCLUDEPATH += $$PWD/../cpp/3rdparty/rknpu2/include
DEPENDPATH += $$PWD/../cpp/3rdparty/rknpu2/include

RESOURCES += \
    Resources/Image.qrc \
    res.qrc



unix:!macx: LIBS += -L$$PWD/lib/librkllm_api/ -lrkllmrt

INCLUDEPATH += $$PWD/lib/librkllm_api/include
DEPENDPATH += $$PWD/lib/librkllm_api/include



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/libgomp/release/ -lgomp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/libgomp/debug/ -lgomp
else:unix: LIBS += -L$$PWD/lib/libgomp/ -lgomp

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

DISTFILES += \
    picture/connected.png \
    picture/disconnected.png

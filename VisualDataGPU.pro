#-------------------------------------------------
#
# Project created by QtCreator 2012-02-07T16:04:09
#
#-------------------------------------------------

QT       += core gui opengl
QT       += widgets

TARGET = VisualDataGPU
TEMPLATE = app

SOURCES +=\
    Camera.cpp \
    Light.cpp \
    Material.cpp \
    MainWindow.cpp \
    Main.cpp \
    GLWidget.cpp \
    datadialog.cpp \
    library/Common.cpp \
    objects/cara.cpp \
    objects/Object.cpp \
    objects/plane.cpp \
    scenes/Scene.cpp \
    scenes/SceneFactory.cpp \
    scenes/SceneFactoryVirtual.cpp \
    scenes/SceneFactoryData.cpp \
    scenes/DataReader.cpp \
    scenes/SceneReader.cpp \
    TG/TG.cpp \
    TG/Translate.cpp \
    animations/Animation.cpp \
    Builder.cpp \
    colormaps/ColorMapStatic.cpp

HEADERS  += \
    datadialog.h \
    library/vec.h \
    library/mat.h \
    library/Common.h \
    Camera.h \
    Light.h \
    Material.h \
    MainWindow.h \
    objects/cara.h \
    objects/Object.h \
    objects/plane.h \
    scenes/Scene.h \
    scenes/SceneFactory.h \
    scenes/SceneFactoryVirtual.h \
    scenes/SceneFactoryData.h \
    scenes/DataReader.h \
    scenes/SceneReader.h \
    GLWidget.h \
    TG/TG.h \
    TG/Translate.h \
    animations/Animation.h \
    Builder.h \
    colormaps/ColorMap.h \
    colormaps/ColorMapStatic.h

FORMS    += mainwindow.ui \
    datadialog.ui

OTHER_FILES += \
    vshader1.glsl \
    fshader1.glsl

RESOURCES += resources.qrc

DISTFILES += \
    resources/models/vFlatShading.vert


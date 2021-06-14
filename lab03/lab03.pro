QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commands/cameracommand.cpp \
    commands/modelcommand.cpp \
    commands/scenecommand.cpp \
    drawer/qtdrawer.cpp \
    drawer/qtfactory.cpp \
    facade/facade.cpp \
    load/builder/modelbuilder.cpp \
    load/loader/filemodelloader.cpp \
    load/moderator/baseloadmoderator.cpp \
    load/moderator/modelloadmoderator.cpp \
    load/moderator/modelloadmoderatorcreator.cpp \
    main.cpp \
    mainwindow.cpp \
    managers/draw/drawmanager.cpp \
    managers/draw/drawmanagercreator.cpp \
    managers/load/loadmanager.cpp \
    managers/load/loadmanagercreator.cpp \
    managers/scene/scenemanager.cpp \
    managers/scene/scenemanagercreator.cpp \
    managers/transform/transformmanager.cpp \
    managers/transform/transformmanagercreator.cpp \
    objects/camera.cpp \
    objects/composite.cpp \
    objects/link.cpp \
    objects/model.cpp \
    objects/modelstructure.cpp \
    objects/vertex.cpp \
    scene/scene.cpp

HEADERS += \
    commands/basecommand.h \
    commands/cameracommand.h \
    commands/modelcommand.h \
    commands/scenecommand.h \
    drawer/basedrawer.h \
    drawer/drawerfactory.h \
    drawer/qtdrawer.h \
    drawer/qtfactory.h \
    exceptions/exceptions.h \
    facade/facade.h \
    load/builder/basebuilder.h \
    load/builder/modelbuilder.h \
    load/loader/baseloader.h \
    load/loader/basemodelloader.h \
    load/loader/filemodelloader.h \
    load/moderator/baseloadmoderator.h \
    load/moderator/modelloadmoderator.h \
    load/moderator/modelloadmoderatorcreator.h \
    mainwindow.h \
    managers/basemanager.h \
    managers/draw/drawmanager.h \
    managers/draw/drawmanagercreator.h \
    managers/draw/visitor.h \
    managers/load/loadmanager.h \
    managers/load/loadmanagercreator.h \
    managers/scene/scenemanager.h \
    managers/scene/scenemanagercreator.h \
    managers/transform/transformmanager.h \
    managers/transform/transformmanagercreator.h \
    objects/camera.h \
    objects/composite.h \
    objects/link.h \
    objects/model.h \
    objects/modelstructure.h \
    objects/object.h \
    objects/vertex.h \
    scene/scene.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += \
    commands/ \
    objects/ \
    managers/ \
    managers/draw/ \
    managers/load/ \
    managers/scene/ \
    managers/transform/ \
    drawer/ \
    facade/ \
    load/builder/ \
    load/loader/ \
    load/moderator/ \
    exceptions/ \
    scene/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tests/tst_size.h \
        tst_size.h

SOURCES += \
        main.cpp

INCLUDEPATH += \
        tests/

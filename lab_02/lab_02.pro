include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tests/tst_vector.hpp \
        vector/inc/base_container.h \
        vector/inc/vector.h

SOURCES += \
        main.cpp \
        vector/src/base_container.cpp \
        vector/src/vector.cpp

INCLUDEPATH += \
        tests/ \
        vector/inc/

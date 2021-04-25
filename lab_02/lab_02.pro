include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tests/tst_size.h \
        tests/tst_vector.hpp \
        tst_size.h \
        vector/base_container.h

SOURCES += \
        main.cpp

INCLUDEPATH += \
        tests/

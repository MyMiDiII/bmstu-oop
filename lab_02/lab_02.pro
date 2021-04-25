include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tests/tst_constructor.hpp \
        tests/tst_vector.hpp \
        vector/inc/base_container.h \
        vector/inc/base_excepton.h \
        vector/inc/iterator.h \
        vector/inc/vector.h \
        vector/src/inc/iterator.h

SOURCES += \
        main.cpp \
        vector/src/base_container.cpp \
        vector/src/base_excepton.cpp \
        vector/src/iterator.cpp \
        vector/src/src/iterator.cpp \
        vector/src/vector.cpp

INCLUDEPATH += \
        tests/ \
        vector/inc/

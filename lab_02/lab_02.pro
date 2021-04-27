include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tests/tst_binary.hpp \
        tests/tst_comparison.hpp \
        tests/tst_constructor.hpp \
        tests/tst_unary.hpp \
        tests/tst_vector.hpp \
        vector/inc/base_container.h \
        vector/inc/base_exception.h \
        vector/inc/const_iterator.h \
        vector/inc/exceptions.h \
        vector/inc/iterator.h \
        vector/inc/vector.h \
        vector/src/base_container.hpp \
        vector/src/base_exception.hpp \
        vector/src/const_iterator.hpp \
        vector/src/iterator.hpp \
        vector/src/vector.hpp

SOURCES += \
        main.cpp \

INCLUDEPATH += \
        tests/ \
        vector/inc/ \
        vector/src/

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

gcc {
    DESTDIR = ../../SimpleXOR/_builds/gcc/
}

clang {
    DESTDIR = ../../SimpleXOR/_builds/clang/
}

mingw {
    DESTDIR = ../../SimpleXOR/_builds/mingw/
}

SOURCES += main.c \
    xor.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    xor.h


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    xor.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    xor.h


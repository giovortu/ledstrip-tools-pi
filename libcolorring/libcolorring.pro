######################################################################
# Libcolorring : 
# V 0.1
# Created : ven set 25 10:23:11 2015
# Author : Giovanni Ortu
# Email : giovortu@gmail.com
######################################################################

INCLUDEPATH += . src

exists( $$PWD../../config/config.pri ) {
include( $$PWD../../config/config.pri )
DESTDIR=$$PWD/../Firmware/libs/
} else {
CONFIG += debug_and_release
DEFINES+=DYNAMIC
DEFINES+=RPI
DESTDIR=$$PWD/../libs
}

!contains(DEFINES,DYNAMIC ) {
CONFIG+=staticlib
}

isEmpty( PREFIX ) {
PREFIX=/usr/local/
}

# Input
HEADERS += src/clk.h   \
           src/dma.h \
           src/gpio.h \
           src/pwm.h \
           src/ws2811.h \
	   src/board_info.h \
	   src/mailbox.h \
           src/NeoRingManager.h
           
SOURCES += src/dma.c \
           src/pwm.c \
           src/ws2811.c \
           src/board_info.c \
	   src/mailbox.c \
           src/NeoRingManager.cpp


TARGET = colorring

TEMPLATE = lib


OBJECTS_DIR=obj
MOC_DIR=moc
RCC_DIR=rcc


unix{
    CONFIG += create_pc create_prl no_install_prl
    libraries.path = $$PREFIX/lib
    libraries.files = $$DESTDIR/*
    header_files.files = $$HEADERS
    header_files.path = $$PREFIX/include/wiringpi
    
    QMAKE_PKGCONFIG_NAME = $$TARGET
    QMAKE_PKGCONFIG_DESCRIPTION=Qt5 wrapper library for wiringPI
    QMAKE_PKGCONFIG_PREFIX=$$PREFIX
    QMAKE_PKGCONFIG_LIBDIR=$$libraries.path
    QMAKE_PKGCONFIG_INCDIR=$$header_files.path
    QMAKE_PKGCONFIG_VERSION=$$VERSION
    QMAKE_PKGCONFIG_DESTDIR=pkgconfig
    
    INSTALLS += header_files libraries
}
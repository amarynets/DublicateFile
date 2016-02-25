#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T22:06:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = DuplicateFile
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    scaner.cpp \
    processor.cpp \
    builder.cpp \
    printer.cpp

HEADERS += \
    scaner.h \
    processor.h \
    builder.h \
    filehash.h \
    printer.h

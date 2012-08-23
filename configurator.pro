QT += core
QT -= gui

TARGET = configurator
TEMPLATE = app


SOURCES += \
    main.cpp \
    dynamicbinding.cpp \
    finitestatebinding.cpp \
    bindingstate.cpp \
    bindingset.cpp \
    binding.cpp \
    directbinding.cpp

HEADERS  += \
    dynamicbinding.h \
    finitestatebinding.h \
    bindingstate.h \
    bindingset.h \
    binding.h \
    directbinding.h

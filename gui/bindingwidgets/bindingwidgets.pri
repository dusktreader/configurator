!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    HEADERS += \
        $$PWD/bindingwidget.h

    SOURCES += \
        $$PWD/bindingwidget.cpp
}

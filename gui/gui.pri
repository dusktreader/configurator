!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    include( $$PWD/bindingwidgets/bindingwidgets.pri )

    HEADERS += \
        $$PWD/mainwindow.h

    SOURCES += \
        $$PWD/mainwindow.cpp

    FORMS += \
        $$PWD/mainwindow.ui

}

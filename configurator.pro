gui_target {

    message( "Building GUI target" )

    QT += core xml gui

    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

    TARGET = configurator_gui
    TEMPLATE = app

    INCLUDEPATH += $$PWD/src
    include( $$PWD/src/src.pri )
    include( $$PWD/gui/gui.pri )
}

cli_target {

    message( "Building CLI target" )

    QT += core xml
    QT -= gui

    TARGET = configurator_cli
    TEMPLATE = app

    INCLUDEPATH += $$PWD/src
    include( $$PWD/src/src.pri )
    include( $$PWD/cli/cli.pri )

}

!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    HEADERS += \
        $$PWD/mainwindow.h

    SOURCES += \
        $$PWD/mainwindow.cpp

    FORMS += \
        $$PWD/mainwindow.ui

}

HEADERS += \
    gui/finitestatebindingdialog.h \
    gui/bindingwizard.h \
    gui/bindingwizardintropage.h \
    gui/bindingwizardtypeselectpage.h \
    gui/bindingwizarddirectpage.h \
    gui/bindingwizardfinitepage.h \
    gui/bindingwizardnumericalpage.h

SOURCES += \
    gui/finitestatebindingdialog.cpp \
    gui/bindingwizard.cpp \
    gui/bindingwizardintropage.cpp \
    gui/bindingwizardtypeselectpage.cpp \
    gui/bindingwizarddirectpage.cpp \
    gui/bindingwizardfinitepage.cpp \
    gui/bindingwizardnumericalpage.cpp

FORMS += \
    gui/finitestatebindingdialog.ui \
    gui/bindingwizard.ui \
    gui/bindingwizardintropage.ui \
    gui/bindingwizardtypeselectpage.ui \
    gui/bindingwizarddirectpage.ui \
    gui/bindingwizardfinitepage.ui \
    gui/bindingwizardnumericalpage.ui

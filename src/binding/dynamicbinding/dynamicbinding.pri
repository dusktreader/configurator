!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    include( $$PWD/dynamicbinding/dynamicbinding.pri )

    HEADERS += \
        $$PWD/bindingset.h \
        $$PWD/binding.h \
        $$PWD/directbinding.h \
        
    SOURCES += \
        $$PWD/bindingset.cpp \
        $$PWD/binding.cpp \
        $$PWD/directbinding.cpp \
}

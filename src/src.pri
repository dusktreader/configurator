!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    include( $$PWD/binding/binding.pri )

    SOURCES += \
        $$PWD/main.cpp \
}

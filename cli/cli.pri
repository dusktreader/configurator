!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    SOURCES += \
        $$PWD/main.cpp \
}

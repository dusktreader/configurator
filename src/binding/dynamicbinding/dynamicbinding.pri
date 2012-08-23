!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    HEADERS += \
        $$PWD/dynamicbinding.h \
        $$PWD/finitestatebinding.h \
        $$PWD/dynamicstate.h \
        $$PWD/numericrangebinding.h \

    SOURCES += \
        $$PWD/dynamicbinding.cpp \
        $$PWD/finitestatebinding.cpp \
        $$PWD/dynamicstate.cpp \
        $$PWD/numericrangebinding.cpp \
}

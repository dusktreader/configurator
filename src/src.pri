!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    include( $$PWD/computeworker/computeworker.pri )
    include( $$PWD/errors/errors.pri )
    include( $$PWD/geometry/geometry.pri )
    include( $$PWD/models/models.pri )
    include( $$PWD/serializable/serializable.pri )
    #include( $$PWD/utility/utility.pri )
    include( $$PWD/video/video.pri )

    HEADERS += \
        $$PWD/trackpath.h \

    SOURCES += \
        $$PWD/trackpath.cpp \


}

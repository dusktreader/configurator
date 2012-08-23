#pragma once

#include <QMap>
#include <QFile>
#include <QString>
#include <QFileInfo>
#include <QFile>
#include <QtXml/QDomDocument>

#include "binding/binding.h"
#include "binding/directbinding.h"
#include "binding/dynamicbinding/dynamicbinding.h"
#include "binding/dynamicbinding/finitestatebinding.h"
#include "binding/dynamicbinding/numericrangebinding.h"

class BindingSet
{

private:

    QMap< QString, BindingPtr > _bindingMap;
    QSet< BindingPtr > _resetGroup;

public:

    BindingSet();

    void addBinding( QString key, BindingPtr binding );
    void print( QTextStream& out );

    void read( QDomElement element );
    void write( QDomElement& element );

    void dump( QString fileName );
    void save( QString fileName );
    void load( QString fileName );
};

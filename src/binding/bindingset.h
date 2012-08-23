#pragma once

#include "binding/binding.h"
#include "binding/dynamicbinding/dynamicbinding.h"

class BindingSet
{

private:

    QMap< QString, BindingPtr > _bindingMap;

public:

    BindingSet();

    void addBinding( QString key, BindingPtr binding );
    void print( QTextStream& out );
};

#pragma once

#include <QSharedPointer>

#include "binding/dynamicbinding/dynamicbinding.h"

class FiniteStateBinding : public DynamicBinding
{

public:

    FiniteStateBinding();

    void addState( QString name, QString value);

    virtual BindingPtr manufacture();
    virtual QString className();

    virtual void read( QDomElement element );
    virtual void write( QDomElement element );
};

typedef QSharedPointer< FiniteStateBinding > FiniteStateBindingPtr;

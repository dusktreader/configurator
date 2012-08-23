#pragma once

#include "binding/binding.h"

class DirectBinding : public Binding
{

protected:

    QString _value;

public:

    DirectBinding();

    void setValue( QString value );
    QString value();

    virtual void print( QTextStream &out, QString key );
    virtual void read( QDomElement element );
    virtual void write( QDomElement element );

    virtual BindingPtr manufacture();
    virtual QString className();
};

typedef QSharedPointer< DirectBinding > DirectBindingPtr;

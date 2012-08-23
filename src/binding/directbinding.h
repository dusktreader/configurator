#pragma once

#include "binding/binding.h"

class DirectBinding : public Binding
{

protected:

    QString _value;

public:

    DirectBinding( QString var, QString name, QString description );

    virtual void print( QTextStream &out, QString key );
};

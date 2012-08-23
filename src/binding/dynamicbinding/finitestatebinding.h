#pragma once

#include <QSharedPointer>

#include "binding/dynamicbinding/dynamicbinding.h"

class FiniteStateBinding : public DynamicBinding
{

public:

    FiniteStateBinding( QString var, QString name, QString description );

    void addState( QString name, QString value);
};

typedef QSharedPointer< FiniteStateBinding > FiniteStateBindingPtr;

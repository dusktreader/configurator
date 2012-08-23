#pragma once

#include <QString>
#include <QSharedPointer>

#include "binding/dynamicbinding/dynamicbinding.h"

class NumericRangeBinding : public DynamicBinding
{

protected:

    double _lo;
    double _hi;
    double _step;

public:

    NumericRangeBinding( QString var, QString name, QString description );

    void setRangeBySubdivision( double lo, double hi, int subdivisions );
    void setRangeByStep( double lo, double hi, double step );
};

typedef QSharedPointer< NumericRangeBinding > NumericRangeBindingPtr;

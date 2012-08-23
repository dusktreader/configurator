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

    NumericRangeBinding();

    void setRangeBySubdivision( double lo, double hi, int subdivisions );
    void setRangeByStep( double lo, double hi, double step );


    virtual void read( QDomElement element );
    virtual void write( QDomElement element );

    virtual BindingPtr manufacture();
    virtual QString className();
};

typedef QSharedPointer< NumericRangeBinding > NumericRangeBindingPtr;

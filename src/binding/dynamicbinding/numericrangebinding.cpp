#include "numericrangebinding.h"

NumericRangeBinding::NumericRangeBinding()
    : DynamicBinding()
{
    _lo = 0.0;
    _hi = 0.0;
    _step = 0.0;
}

void NumericRangeBinding::setRangeBySubdivision( double lo, double hi, int subdivisions )
{
    double diff = _hi - _lo;
    double step = diff / subdivisions;

    setRangeByStep( lo, hi, step );
}

void NumericRangeBinding::setRangeByStep( double lo, double hi, double step )
{
    _stateList.clear();

    /// @todo add custom error

    _lo = lo;
    _hi = hi;
    _step = step;

    for( double val = _lo; val < _hi; val += _step )
    {
        /// @todo check precision for numeric bindings
        QString name = QString( "%1 %2" ).arg( _name ).arg( val );
        QString value = QString::number( val, 'f', 4 );
        DynamicStatePtr state( new DynamicState() );
        state->setName( name );
        state->setValue( value );
        addState( state );
    }
}

void NumericRangeBinding::read( QDomElement element )
{
    DynamicBinding::read( element );
    /// @todo check bad values
    double lo = element.attribute( "lo" ).toDouble();
    double hi = element.attribute( "hi" ).toDouble();
    double step = element.attribute( "step" ).toDouble();
    setRangeByStep( lo, hi, step );
}

void NumericRangeBinding::write( QDomElement element )
{
    element.setAttribute( "lo", _lo );
    element.setAttribute( "hi", _hi );
    element.setAttribute( "step", _step );
    DynamicBinding::write( element );
}



BindingPtr NumericRangeBinding::manufacture()
{
    return BindingPtr( new NumericRangeBinding() );
}

QString NumericRangeBinding::className()
{
    return "NumericRangeBinding";
}

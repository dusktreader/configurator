#include "numericrangebinding.h"

NumericRangeBinding::NumericRangeBinding( QString var, QString name, QString description )
    : DynamicBinding( var, name, description ), _lo(0), _hi(0), _step(0)
{}

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
        DynamicStatePtr state( new DynamicState( name, value ) );
        addState( state );
    }
}



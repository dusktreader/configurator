#include "finitestatebinding.h"

FiniteStateBinding::FiniteStateBinding( QString var, QString name, QString description )
    : DynamicBinding( var, name, description )
{}

void FiniteStateBinding::addState( QString name, QString value )
{
    _stateList << DynamicStatePtr( new DynamicState( name, value ) );
}

#include "bindingstate.h"

BindingState::BindingState( QString name, QString value )
    : _name( name ), _value( value )
{}

QString BindingState::name()
{
    return _name;
}

QString BindingState::value()
{
    return _value;
}

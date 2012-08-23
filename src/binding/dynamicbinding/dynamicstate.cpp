#include "dynamicstate.h"

DynamicState::DynamicState( QString name, QString value )
    : _name( name ), _value( value )
{}

QString DynamicState::name()
{
    return _name;
}

QString DynamicState::value()
{
    return _value;
}

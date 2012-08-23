#include "dynamicstate.h"

DynamicState::DynamicState()
{
    _name = "###INVALID_NAME###";
    _value = "###INVALID_VALUE###";
}

void DynamicState::setName( QString name )
{
    _name = name;
}

QString DynamicState::name()
{
    return _name;
}

void DynamicState::setValue( QString value )
{
    _value = value;
}

QString DynamicState::value()
{
    return _value;
}

void DynamicState::read( QDomElement element )
{
    /// @todo  bad values
    _name = element.attribute( "name" );
    _value = element.attribute( "value" );
}

void DynamicState::write( QDomElement element )
{
    element.setAttribute( "name", _name );
    element.setAttribute( "value", _value );
}

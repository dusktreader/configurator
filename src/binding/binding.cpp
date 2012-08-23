#include "binding.h"

Binding::Binding()
{
    _var = "###INVALID VARIABLE###";
    _name = "###UNNAMED BINDING###";
    _description = "###NO DESCRIPTION PROVIDED###";
    _resetable = false;
}

void Binding::setVar( QString var )
{
    _var = var;
}

QString Binding::var()
{
    return _var;
}

void Binding::setName( QString name )
{
    _name = name;
}

QString Binding::name()
{
    return _name;
}

void Binding::setDescription( QString description )
{
    _description = description;
}

QString Binding::description()
{
    return _description;
}

void Binding::setResetable( bool resetable )
{
    _resetable = resetable;
}

bool Binding::resetable()
{
    return _resetable;
}

void Binding::read( QDomElement element )
{
    _name = element.attribute( "name" );
    _var = element.attribute( "var" );
    _description = element.attribute( "description" );
    _resetable = element.attribute( "resetable" ) == "true";
}

void Binding::write( QDomElement element )
{
    element.setAttribute( "name", _name );
    element.setAttribute( "var", _var );
    element.setAttribute( "description", _description );
    element.setAttribute( "resetable", _resetable ? "true" : "false" );
}



QMap< QString, BindingPtr > Binding::_factoryMap;

BindingPtr Binding::manufacture( QString className )
{
    /// @todo checks
    return _factoryMap[ className ]->manufacture();
}

void Binding::registerFactory( BindingPtr factory )
{
    _factoryMap[ factory->className() ] = factory;
}

#include "directbinding.h"

DirectBinding::DirectBinding()
    : Binding()
{
    _value = "###INVALID VALUE###";
}

void DirectBinding::setValue( QString value )
{
    /// @todo  Make sure a directbinding with that name doesn't already appear.
    _value = value;
}

QString DirectBinding::value()
{
    return _value;
}

void DirectBinding::print( QTextStream &out, QString key )
{
    out << _description << endl;
    out << "bind " << key << " \"" << _value << "\";" << endl;
}

void DirectBinding::read( QDomElement element )
{
    _value = element.attribute( "value" );
    Binding::read( element );
}

void DirectBinding::write( QDomElement element )
{
    element.setAttribute( "value", _value );
    Binding::write( element );
}



BindingPtr DirectBinding::manufacture()
{
    return BindingPtr( new DirectBinding() );
}

QString DirectBinding::className()
{
    return "DirectBinding";
}

#include "directbinding.h"

DirectBinding::DirectBinding( QString var, QString name, QString description )
    : Binding( var, name, description ), _value( "" )
{
    /// @todo  Make sure a directbinding with that name doesn't already appear.

}

void DirectBinding::print( QTextStream &out, QString key )
{
    out << _description << endl;
    out << "bind " << key << " \"" << _value << "\";" << endl;
}

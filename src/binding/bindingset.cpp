#include "bindingset.h"

BindingSet::BindingSet()
{}

void BindingSet::addBinding( QString key, BindingPtr binding )
{
    _bindingMap[key] = binding;
}

void BindingSet::print( QTextStream& out )
{
    out << "set no_action \"ut_echo No adjustment selected\";" << endl;
    out << "set no_back \"ut_echo No back adjustment\";" << endl;
    out << "set no_next \"ut_echo No next adjustment\";" << endl;
    out << endl;
    out << "set back \"vstr no_back\";" << endl;
    out << "set next \"vstr no_next\";" << endl;
    out << "set action \"vstr no_action\";" << endl;
    out << endl;
    out << "bind PGUP \"vstr next\";" << endl;
    out << "bind PGDN \"vstr back\";" << endl;
    out << "bind ENTER \"vstr action\";" << endl;
    out << endl << endl << endl;

    foreach( QString key, _bindingMap.keys() )
        _bindingMap[key]->print( out, key );
        out << endl << endl << endl;

    out << "set initialize_all \"";
    foreach( QString name, DynamicBinding::dynamicBindingSet() )
        out << "vstr " << name << "_initial;";
    out << "\";" << endl;
    out << "vstr initialze_all;" << endl;

    /// @todo bind resetAll!
}

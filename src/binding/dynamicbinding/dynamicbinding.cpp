#include "dynamicbinding.h"

 QSet<QString> DynamicBinding::_dynamicBindingSet = QSet<QString>();

QSet< QString > DynamicBinding::dynamicBindingSet()
{
    return _dynamicBindingSet;
}

DynamicBinding::DynamicBinding( QString var, QString name, QString description )
    : Binding( var, name, description ), _initialIndex( 0 )
{
    _dynamicBindingSet << name;
    /// @todo check that no other exists
}

void DynamicBinding::addState( DynamicStatePtr state )
{
    _stateList << state;
}

void DynamicBinding::setInitialIndex( int initialIndex )
{
    _initialIndex = initialIndex;
}

void DynamicBinding::printState( QTextStream& out, int stateIndex )
{
    DynamicStatePtr statePtr = _stateList[ stateIndex ];
    int backIndex = stateIndex == 0 ? _stateList.size() - 1 : stateIndex - 1;
    int nextIndex = stateIndex == _stateList.size() - 1 ? 0 : stateIndex + 1;

    /// @todo add state coloring (with color enum/mapping to ^ codes
    /// @todo add state resetting for conditional states

    // Add the state action
    QString action = "set %1_action_%2 \"seta %3 %4; ut_echo %5 activated\";";
    action = action
            .arg( _name )
            .arg( stateIndex )
            .arg( _var )
            .arg( statePtr->value() )
            .arg( statePtr->name() );

    QString message = "set %1_message_%2 \"ut_echo %3 selected\";";
    message = message
            .arg( _name )
            .arg( stateIndex )
            .arg( statePtr->name() );

    QString state = "set %1_state_%2 \"set %1_back vstr %1_state_%3;set %1_next vstr %1_state_%4;set %1_action vstr %1_action_%2;vstr %1_message_%2\";";
    state = state
            .arg( _name )
            .arg( stateIndex )
            .arg( backIndex )
            .arg( nextIndex );

    out << action << endl;
    out << message << endl;
    out << state << endl;
}

void DynamicBinding::print( QTextStream &out, QString key )
{
    QString initial = "set %1_initial \"vstr %1_state_%2;vstr %1_select;vstr %1_action\";";
    initial = initial.arg( _name ).arg( _initialIndex );

    QString select = "set %1_select \"set action vstr %1_action;set back vstr %1_back;set next vstr %1_next; ut_echo Selected %1 adjustment\";";
    select = select.arg( _name );

    QString binding = "bind %2 \"vstr %1_select\";";
    binding = binding.arg( _name ).arg( key );

    out << "// Begin " << _description << endl;
    out << endl;
    for( int i = 0; i < _stateList.size(); i++ )
    {
        printState( out, i );
        out << endl;
    }
    out << initial << endl;
    out << select << endl;
    out << endl;
    out << binding << endl;
    out << endl;
    out << "// Finish " << _description << endl;
}

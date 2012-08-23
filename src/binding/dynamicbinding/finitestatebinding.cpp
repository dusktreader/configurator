#include "finitestatebinding.h"

FiniteStateBinding::FiniteStateBinding()
    : DynamicBinding()
{}

void FiniteStateBinding::addState( QString name, QString value )
{
    DynamicStatePtr state( new DynamicState() );
    state->setName( name );
    state->setValue( value );
    _stateList << state;
}



BindingPtr FiniteStateBinding::manufacture()
{
    return BindingPtr( new FiniteStateBinding() );
}

QString FiniteStateBinding::className()
{
    return "FiniteStateBinding";
}

void FiniteStateBinding::read( QDomElement element )
{
    DynamicBinding::read( element );
    _stateList.clear();
    QDomNode node = element.firstChild();
    while( !node.isNull() )
    {
        QDomElement stateElement = node.toElement();
        DynamicStatePtr state( new DynamicState() );
        state->read( stateElement );
        _stateList << state;
        node = node.nextSibling();
    }
}

void FiniteStateBinding::write( QDomElement element )
{
    /// @todo element.clear();
    foreach( DynamicStatePtr state, _stateList )
    {
        QDomElement stateElement = element.ownerDocument().createElement( "state" );
        state->write( stateElement );
        element.appendChild( stateElement );
    }
    DynamicBinding::write( element );
}

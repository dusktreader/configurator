#include "bindingset.h"

BindingSet::BindingSet()
{}

void BindingSet::addBinding( QString key, BindingPtr binding )
{
    _bindingMap[key] = binding;
    /// @todo push this down to the binding object?
    if( binding->resetable() )
        _resetGroup.insert( binding );
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
    {
        _bindingMap[key]->print( out, key );
        out << endl << endl << endl;
    }

    out << "set initialize_all \"";
    foreach( BindingPtr binding, _resetGroup )
        out << "vstr " << binding->name() << "_initial;";
    out << "\";" << endl;
    out << "vstr initialze_all;" << endl;

    /// @todo bind resetAll!
}

void BindingSet::read( QDomElement element )
{
    _bindingMap.clear();
    _resetGroup.clear();

    /// @todo assert validation

    QDomNode node = element.firstChild();
    while( !node.isNull() )
    {
        QDomElement bindElement = node.toElement();
        QString key  = bindElement.attribute( "key" );
        QString type = bindElement.attribute( "type" );

        /// @todo verify that biding is in the factory map
        BindingPtr binding = Binding::manufacture( type );
        binding->read( bindElement );
        addBinding( key, binding );
        if( binding->resetable() )
            _resetGroup.insert( binding );

        node = node.nextSibling();
    }
}

void BindingSet::write( QDomElement& element )
{
    foreach( QString key, _bindingMap.keys() )
    {
        BindingPtr binding = _bindingMap[ key ];
        QDomElement childElement = element.ownerDocument().createElement( "binding" );
        childElement.setAttribute( "key", key );
        childElement.setAttribute( "type", binding->className() );
        binding->write( childElement );
        element.appendChild( childElement );
    }
}

void BindingSet::dump( QString fileName )
{
    QFileInfo fileInfo( fileName );
    /// @todo checks

    QFile dumpFile( fileInfo.absoluteFilePath() );
    dumpFile.open( QIODevice::WriteOnly | QIODevice::Text );
    QTextStream out( &dumpFile );
    print( out );
}


void BindingSet::load( QString fileName )
{
    QFileInfo fileInfo( fileName );
    /// @todo checks

    QFile loadFile( fileInfo.absoluteFilePath() );
    loadFile.open( QIODevice::ReadOnly | QIODevice::Text );
    QDomDocument doc( "binding_doc" );
    doc.setContent( &loadFile );
    QDomElement rootElement = doc.firstChildElement();
    read( rootElement );
}

void BindingSet::save( QString fileName )
{
    QDomDocument doc( "binding_doc" );
    QDomElement rootElement = doc.createElement( "root" );
    write( rootElement );
    doc.appendChild( rootElement );

    /// @todo checks
    QFileInfo fileInfo( fileName );
    QFile saveFile( fileInfo.absoluteFilePath() );
    saveFile.open( QIODevice::WriteOnly | QIODevice::Text );
    QTextStream out( &saveFile );
    out << doc.toString() << endl;
}

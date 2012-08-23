#pragma once

#include <QVector>
#include <QString>
#include <QTextStream>
#include <QSet>

#include "binding/binding.h"
#include "binding/dynamicbinding/dynamicstate.h"

class DynamicBinding : public Binding
{

protected:

    QVector< DynamicStatePtr > _stateList;
    int _initialIndex;

    void printState( QTextStream& out, int stateIndex );

public:

    DynamicBinding();

    void addState( DynamicStatePtr state );
    void setInitialIndex( int initialIndex );

    virtual void print( QTextStream& out, QString key );
    virtual void read( QDomElement element );
    virtual void write( QDomElement element );
};

typedef QSharedPointer< DynamicBinding > DynamicBindingPtr;

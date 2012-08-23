#pragma once

#include <QVector>
#include <QString>
#include <QTextStream>
#include <QSet>

#include "binding.h"
#include "bindingstate.h"

class DynamicBinding : public Binding
{

private:

    static QSet<QString> _dynamicBindingSet;

protected:

    QVector< BindingStatePtr > _stateList;
    int _initialIndex;

    void printState( QTextStream& out, int stateIndex );

public:

    static QSet<QString> dynamicBindingSet();

    DynamicBinding( QString var, QString name, QString description );
    void addState( BindingStatePtr state );
    void setInitialIndex( int initialIndex );
    virtual void print( QTextStream& out, QString key );
};

typedef QSharedPointer< DynamicBinding > DynamicBindingPtr;

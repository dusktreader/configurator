#pragma once

#include <QString>
#include <QTextStream>
#include <QSharedPointer>

class Binding
{

protected:

    QString _var;
    QString _name;
    QString _description;

public:

    Binding( QString var, QString name, QString description );
    virtual void print( QTextStream& out, QString key ) = 0;
};

typedef QSharedPointer<Binding> BindingPtr;


#pragma once

#include <QString>
#include <QSharedPointer>
#include <QtXml/QDomElement>

class DynamicState
{

private:

    QString _name;
    QString _value;

public:

    DynamicState();

    void setName( QString name );
    QString name();

    void setValue( QString value );
    QString value();

    void read( QDomElement element );
    void write( QDomElement element );
};

typedef QSharedPointer< DynamicState > DynamicStatePtr;

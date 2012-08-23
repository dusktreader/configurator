#pragma once

#include <QString>
#include <QSharedPointer>

class DynamicState
{

private:

    QString _name;
    QString _value;

public:

    DynamicState( QString name, QString value );
    QString name();
    QString value();
};

typedef QSharedPointer< DynamicState > DynamicStatePtr;

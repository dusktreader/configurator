#pragma once

#include <QString>
#include <QSharedPointer>

class BindingState
{

private:

    QString _name;
    QString _value;

public:

    BindingState( QString name, QString value );
    QString name();
    QString value();
};

typedef QSharedPointer< BindingState > BindingStatePtr;

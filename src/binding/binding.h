#pragma once

#include <QString>
#include <QTextStream>
#include <QSharedPointer>

#include <QtXml/QDomElement>

class Binding
{

private:

    static QMap< QString, QSharedPointer< Binding > > _factoryMap;


protected:

    QString _var;
    QString _name;
    QString _description;
    bool _resetable;

public:

    Binding();

    virtual void setVar( QString var );
    virtual QString var();

    virtual void setName( QString name );
    virtual QString name();

    virtual void setDescription( QString description );
    virtual QString description();

    virtual void setResetable( bool resetable );
    virtual bool resetable();

    virtual void print( QTextStream& out, QString key ) = 0;
    virtual void read( QDomElement element );
    virtual void write( QDomElement element );



    static void registerFactory( QSharedPointer< Binding > factory );
    static QSharedPointer< Binding > manufacture( QString className );
    virtual QSharedPointer< Binding > manufacture() = 0;
    virtual QString className() = 0;
};

typedef QSharedPointer<Binding> BindingPtr;


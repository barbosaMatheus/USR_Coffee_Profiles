#ifndef ROASTGRAPH_H
#define ROASTGRAPH_H

#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include <QtCharts>
#include "coffeeroastingprofile.h"

class RoastGraph
{
public:
    RoastGraph();
    RoastGraph( QString title, int size );
    void fromJSON( QJsonObject json );
    void toJSON( QJsonObject &json );
    int get_size( );
    QString get_title( );
    int get_data( int index );
    void set_title( QString title );
    void set_data( int index, int val );
    void set_size( unsigned int size = 0 );
    void append( int val );

private:
    QString title;
    int size;
    QVector<int> data;
};

#endif // ROASTGRAPH_H

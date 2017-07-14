#ifndef ROASTGRAPH_H
#define ROASTGRAPH_H

#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include <QtCharts>

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
    void set_size( int size );
    void append( int val );
private:
    QString title;
    int size;
    QVector<int> data;
};

#endif // ROASTGRAPH_H
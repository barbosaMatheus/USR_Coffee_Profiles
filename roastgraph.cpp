#include "roastgraph.h"

RoastGraph::RoastGraph( ) {

}

RoastGraph::RoastGraph( QString title, int size ) {
    this->title = title;
    this->size = size;
}

int RoastGraph::get_size( ) { return this->size; }

QString RoastGraph::get_title( ) { return this->title; }

int RoastGraph::get_data( int index ) {
    if( index >= this->size ) return -1;
    else return this->data[index];
}

void RoastGraph::set_data( int index, int val ) {
    if( index >= this->size ) return;
    else this->data[index] = val;
}

void RoastGraph::set_title( QString title ) { this->title = title; }

void RoastGraph::fromJSON( QJsonObject json ) {
    this->title = json["title"].toString( );
    this->size = json["size"].toInt( );

    for( int i = 0; i < size; ++i )
        data.append( ( json["data"].toArray( ) )[i].toInt( ) );
}

void RoastGraph::toJSON( QJsonObject &json ) {
    json["title"] = this->title;
    json["size"] = this->size;
    QJsonArray array;
    for( int i = 0; i < this->size; ++i ) {
        array.push_back( QJsonValue( this->data[i] ) );
    }
    json["data"] = array;
}

void RoastGraph::append( int val ) {
    this->data.push_back( val );
    this->size = data.size( );
}

void RoastGraph::append( int val, int n ) {
    for( int i = 0; i < n; ++i ) this->append( val  );
}

void RoastGraph::set_size( unsigned int size ) {
    if( size == 0 ) this->size = data.size( );
    else this->size = size;
}

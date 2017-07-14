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

void RoastGraph::append( int val ) { this->data.push_back( val ); }

void RoastGraph::set_size( int size ) { this->size = size; }

CoffeeRoastingProfile* RoastGraph::to_profile( void ) {
    CoffeeRoastingProfile *p = new CoffeeRoastingProfile( title, data.size( )/15 );
    for( int i = 0; i < data.size( ); i += 15 )
        p->set_data( -1, {500,data[i],100,100,100} );  //-1 does an append
    return p;
}

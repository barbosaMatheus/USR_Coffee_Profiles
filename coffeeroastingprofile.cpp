#include "coffeeroastingprofile.h"

CoffeeRoastingProfile::CoffeeRoastingProfile( QString title , int mins, uint8_t list_id, int main_id ) {
    this->title = title;
    this->minutes = mins;
    this->list_id = list_id;
    this->main_id = main_id;
}

CoffeeRoastingProfile::CoffeeRoastingProfile( ) { }

int CoffeeRoastingProfile::get( Index index, int time ) const {
    if( time >= data.size( ) ) return -1;
    auto dat = data.at( time );
    switch( index ) {
        case Index::CAT_SET_PT:
            return dat.cat_sp;
        case Index::DRUM_SET_PT:
            return dat.drum_sp;
        case Index::CAT_HEAT:
            return dat.cat_heat;
        case Index::DRUM_HEAT:
            return dat.drum_heat;
        case Index::FAN_SPEED:
            return dat.fan_speed;
        default: return -1;
    }
}


QString CoffeeRoastingProfile::get_title( ) const {
    return title;
}


int CoffeeRoastingProfile::get_mins( ) const {
    return minutes;
}


void CoffeeRoastingProfile::set( Index index, int time, int val ) {
    switch( index ) {
        case Index::CAT_SET_PT:
            data[time].cat_sp = val; break;
        case Index::DRUM_SET_PT:
            data[time].drum_sp = val; break;
        case Index::CAT_HEAT:
            data[time].cat_heat = val; break;
        case Index::DRUM_HEAT:
            data[time].drum_heat = val; break;
        case Index::FAN_SPEED:
            data[time].fan_speed = val; break;
        default: return;
    }
}


void CoffeeRoastingProfile::set_mins( int mins ) {
    if( mins == -1 ) this->minutes = data.size( )/4 ;
    else this->minutes = mins;
}

void CoffeeRoastingProfile::clear_all( void ) {
    data.clear( );
}


void CoffeeRoastingProfile::set_title( QString title ) {
    this->title = title;
}


QString CoffeeRoastingProfile::read( QJsonObject json ) {
    title = json["title"].toString( );
    minutes = json["mins"].toInt( );
    QJsonValue list_id_json = json["list"];
    if( list_id_json.isUndefined( ) ) list_id = 0;
    else list_id = list_id_json.toInt( );
    const int num_data_pts = 4*minutes;

    for( int i = 0; i < num_data_pts; ++i ) {
        const QString json_key = "data_" + QString::number( i );
        QJsonObject data_pt = json[json_key].toObject( );
        if( data_pt.isEmpty( ) ) data.push_back( {0,0,0,0,0} );
        else {
            const int cat_sp = data_pt["cat_sp"].toInt( );
            const int drum_sp = data_pt["drum_sp"].toInt( );
            const int cat_heat = data_pt["cat_heat"].toInt( );
            const int drum_heat = data_pt["drum_heat"].toInt( );
            const int fan_speed = data_pt["fan_speed"].toInt( );
            data.push_back( {cat_sp, drum_sp, cat_heat, drum_heat, fan_speed} );
        }
    }

    return title;
}


void CoffeeRoastingProfile::write( QJsonObject &json ) {
    json["title"] = title;
    json["mins"] = minutes;
    json["list"] = list_id;
    for( int i = 0; i < data.size( ); ++i ) {
        const QString key = "data_" + QString::number( i );
        QJsonObject data_pt;
        data_pt["cat_sp"] = data[i].cat_sp;
        data_pt["drum_sp"] = data[i].drum_sp;
        data_pt["cat_heat"] = data[i].cat_heat;
        data_pt["drum_heat"] = data[i].drum_heat;
        data_pt["fan_speed"] = data[i].fan_speed;
        json[key] = data_pt;
    }
}


QByteArray CoffeeRoastingProfile::to_byte_array( int time ) {
    ProfileDataPoint pt = data.at( time );
    char csp = pt.cat_sp / 6;
    char dsp = pt.drum_sp / 6;
    char cpc = pt.cat_heat;
    char dpc = pt.drum_heat;
    char fsp = pt.fan_speed;

    QByteArray arr;
    arr.append( csp ).append( dsp ).append( cpc ).append( dpc ).append( fsp );
    return arr;
}


CoffeeRoastingProfile::ProfileDataPoint CoffeeRoastingProfile::get_data( int time ) {
    CoffeeRoastingProfile::ProfileDataPoint pt = data.at( time );
    return pt;
}


void CoffeeRoastingProfile::set_data( int time, ProfileDataPoint p ) {
    if( time == -1 || time >= data.size( ) ) this->data.push_back( p );
    else this->data[time] = p;
}

uint8_t CoffeeRoastingProfile::get_list_id( void ) {
    return this->list_id;
}

void CoffeeRoastingProfile::set_list_id( uint8_t list_id ) {
    this->list_id = list_id;
}

int CoffeeRoastingProfile::get_main_id( void ) { return this->main_id; }

void CoffeeRoastingProfile::set_main_id( int main_id ) { this->main_id = main_id; }

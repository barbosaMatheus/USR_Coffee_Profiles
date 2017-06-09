#include "coffeeroastingprofile.h"

CoffeeRoastingProfile::CoffeeRoastingProfile( QString title , int mins ) {
    this->title = title;
    this->minutes = mins;
    const int rows = mins*4;
    //fill up data with zeros at the start
    for( int i = 0; i < rows; ++i ) data.push_back( {0,0,0,0,0} );
}

CoffeeRoastingProfile::CoffeeRoastingProfile( ) {}

int CoffeeRoastingProfile::get( Index index, int time ) const {
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
    this->minutes = mins;
}


void CoffeeRoastingProfile::set_title( QString title ) {
    this->title = title;
}


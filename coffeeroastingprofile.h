#ifndef COFFEEROASTINGPROFILE_H
#define COFFEEROASTINGPROFILE_H

#include <QString>
#include <QVector>
#include <QJsonObject>
#include <QDebug>

class CoffeeRoastingProfile {
public:
    CoffeeRoastingProfile( QString title, int mins );
    CoffeeRoastingProfile( );
    struct ProfileDataPoint {
        int cat_sp;       //set point (temp)
        int drum_sp;      //set point (temp)
        uint8_t cat_heat;     //0 to 100%
        uint8_t drum_heat;    //0 to 100%
        uint8_t fan_speed;    //0 to 100%
    };

    enum Index {
        CAT_SET_PT = 0,
        DRUM_SET_PT = 1,
        CAT_HEAT = 2,
        DRUM_HEAT = 3,
        FAN_SPEED = 4
    };

    int get( Index index, int time ) const;
    QString get_title( ) const;
    int get_mins( ) const;
    ProfileDataPoint get_data( int time );
    void set_data( int time, ProfileDataPoint p );
    void set( Index index, int time, int val );
    void set_title( QString title );
    void set_mins( int mins = -1 );
    QString read( QJsonObject json );
    void write( QJsonObject &json );
    QByteArray to_byte_array( int time );
    int num_data_points( void ) const { return this->data.size( ); }

private:
    QString title;                      //profile title
    int minutes;                        //length of roast in minutes
    QVector<ProfileDataPoint> data;     //roasting data
};

#endif // COFFEEROASTINGPROFILE_H

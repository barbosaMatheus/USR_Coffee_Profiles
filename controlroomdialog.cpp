#include "controlroomdialog.h"
#include "ui_controlroomdialog.h"
using namespace QtCharts;

ControlRoomDialog::ControlRoomDialog( CoffeeRoastingProfile *pro, QWidget *parent ) :
    QDialog(parent),
    ui( new Ui::ControlRoomDialog ) {
    ui->setupUi(this);
    this->profile = pro;
    beautify( );
    make_graph( );
}

ControlRoomDialog::~ControlRoomDialog( ) {
    delete ui;
}


void ControlRoomDialog::beautify( ) {
    this->setWindowTitle( "Control Room" );
    this->setWindowFlags( this->windowFlags( ) & ~Qt::WindowContextHelpButtonHint );
    ui->stir_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->door_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->cooler_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->ex_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->dmp3_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->dmp4_button->setStyleSheet( "color: white; background-color: #7a7940" );

}


void ControlRoomDialog::on_dsp_dial_valueChanged( int value ) {
    const QString str = "Drum Set Point: " + QString::number( value ) + "F";
    ui->dsp_label->setText( str );
}


void ControlRoomDialog::on_dh_dial_valueChanged( int value ) {
    const QString str = "Drum Heat: " + QString::number( value ) + "%";
    ui->dh_label->setText( str );
}


void ControlRoomDialog::on_csp_dial_valueChanged( int value ) {
    const QString str = "Cat Set Point: " + QString::number( value ) + "F";
    ui->csp_label->setText( str );
}


void ControlRoomDialog::on_ch_dial_valueChanged( int value ) {
    const QString str = "Cat Heat: " + QString::number( value ) + "%";
    ui->ch_label->setText( str );
}


void ControlRoomDialog::on_fs_dial_valueChanged( int value ) {
    const QString str = "Fan Speed: " + QString::number( value ) + "%";
    ui->fs_label->setText( str );
}


void ControlRoomDialog::on_ds_dial_valueChanged( int value ) {
    const QString str = "Drum Speed: " + QString::number( value ) + "%";
    ui->ds_label->setText( str );
}


void ControlRoomDialog::make_graph( ) {
    series = new QLineSeries( );
    const int pts = ( profile->get_mins( ) ) * 4;
    for( int i = 0; i < pts; ++i ) {
        const int temp = profile->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, i );
        series->append( i*15, temp );
    }
    chart = new QChart( );
    chart->legend( )->hide( );
    chart->addSeries( series );
    chart->createDefaultAxes( );
    const QString title = "Profile Graph: " + profile->get_title( ) + ", " +
            QString::number( profile->get_mins( ) ) + " minutes";
    QFont font = chart->titleFont( );
    font.setBold( true );
    font.setPointSize( 13 );
    chart->setTitleFont( font );
    chart->setTitle( title );
    chart->axisX( )->setTitleText( "Seconds" );
    chart->axisY( )->setTitleText( "Drum Set Point (F)" );
    chart_view = new QChartView( chart, ui->graph_widget );
    chart_view->setContentsMargins( 0, 0, 0, 0 );
    chart_view->resize( 1000, 400 );
    chart_view->setRenderHint( QPainter::Antialiasing );
}

#include "controlroomdialog.h"
#include "ui_controlroomdialog.h"
using namespace QtCharts;

ControlRoomDialog::ControlRoomDialog( CoffeeRoastingProfile *pro, QWidget *parent ) :
    QDialog(parent),
    ui( new Ui::ControlRoomDialog ) {
    ui->setupUi(this);
    LIVE = false;
    TIMER_STARTED = false;
    this->profile = pro;
    beautify( );
    make_graph( );
    //this->setMouseTracking( true );
    //this->grabMouse( );
    //ui->graph_widget->setMouseTracking( true );
}

ControlRoomDialog::~ControlRoomDialog( ) {
    delete ui;
}

void ControlRoomDialog::beautify( ) {
    QColor color( 28, 49, 68 );
    this->setWindowTitle( "Control Room" );
    this->setWindowFlags( this->windowFlags( ) & ~Qt::WindowContextHelpButtonHint );
    ui->stir_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->door_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->cooler_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->ex_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->dmp3_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->dmp4_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->start_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->ch_dial->setStyleSheet( "color: white; background-color: #1c3144" );
    ui->csp_dial->setStyleSheet( "color: white; background-color: #1c3144" );
    ui->dh_dial->setStyleSheet( "color: white; background-color: #1c3144" );
    ui->ds_dial->setStyleSheet( "color: white; background-color: #1c3144" );
    ui->fs_dial->setStyleSheet( "color: white; background-color: #1c3144" );
    ui->dsp_dial->setStyleSheet( "color: white; background-color: #1c3144" );

    QListView *list1 = new QListView( ui->com_box );
    list1->setStyleSheet( "QListView {background-color: #c9cacc;}"
                          "QListView::item {"
                          "border-bottom: 1px solid black}"
                          "QListView::item::selected {background-color: #1c3144;"
                          "color: white;}" );
    ui->com_box->setView( list1 );
    QPalette p = ui->com_box->palette( );
    p.setColor( QPalette::Highlight, color );
    ui->com_box->setPalette( p );
    ui->com_box->addItem( "Choose a COM Port" );
    for( int i = 1; i < 8; ++i ) ui->com_box->addItem( ( "COM" + QString::number( i ) ) );
    ui->info_label->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->info_label->setAlignment( Qt::AlignLeft | Qt::AlignTop );
    ui->info_label->setHidden( true );
    ui->x_pos->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->y_pos->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->drum_sp->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->drum_heat->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->fan_sp->setStyleSheet( "color: white; background-color: #1c3144;" );
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
    series = new QSplineSeries( );
    const int pts = ( profile->get_mins( ) ) * 4;
    for( int i = 0; i < pts; ++i ) {
        const int temp = profile->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, i );
        series->append( i*15, temp );
    }
    chart = new QChart( );
    chart->addSeries( series );
    series->setName( profile->get_title( ) );
    auto s_pen = series->pen( );
    s_pen.setWidth( 3 );
    series->setPen( s_pen );
    //series->setPointLabelsVisible( true );
    chart->createDefaultAxes( );
    const QString title = "Profile Graph: " + profile->get_title( ) + ", " +
            QString::number( profile->get_mins( ) ) + " minutes";
    QFont font = chart->titleFont( );
    font.setBold( true );
    font.setPointSize( 13 );
    chart->setTitleFont( font );
    chart->setTitle( title );
    chart->axisX( )->setTitleText( "Seconds" );
    chart->axisX( )->setRange( 0, 1200 );
    chart->axisY( )->setRange( 200, 500 );
    chart->axisY( )->setTitleText( "Temperature (F)" );
    chart_view = new QChartView( chart, ui->graph_widget );
    chart_view->setContentsMargins( 0, 0, 0, 0 );
    chart_view->resize( 1021, 401 );
    chart_view->setRenderHint( QPainter::Antialiasing );
}

void ControlRoomDialog::on_start_button_clicked( ) {
    if( LIVE ) {                                                            //if we are already live
        timer->stop( );                                                     //stop the timer
        LIVE = false;                                                       //leave live
        ui->start_button->setText( "Start" );                               //set up start button
        chart->removeSeries( live );                                        //remove the live graph from the chart
        chart_view->repaint( );                                             //repaint chart view
        ui->info_label->clear( );                                           //clear label text
        live->clear( );                                                     //clear the info in the live graph
        const QString title = "Profile Graph: " + profile->get_title( ) + ", " +
                QString::number( profile->get_mins( ) ) + " minutes";
        chart->setTitle( title );
        serial->close( );                                                   //close serial port
        return;                                                             //leave
    }
    if( TIMER_STARTED ) {                                                   //if we are not live, but have an initialized timer
        if( !serial->open( QIODevice::ReadOnly ) ) {                                                 //open the serial port for read only
            QMessageBox msg;
            msg.setWindowTitle( "Cannot Communicate with Roaster" );
            QString str = "Communication with roaster has been interrupted. Either no roaster is plugged in or it has been turned off/disconnected."
                          " Please connect a roaster and try again.\n\nError: " + serial->errorString( );
            msg.setText( str );
            msg.setStandardButtons( QMessageBox::StandardButton::Ok );
            msg.exec( );
            return;
        }
        timer->start( INTERVAL );                                           //restart the timer
        time_index = 0;                                                     //restart time index
        LIVE = true;                                                        //go back to live
        ui->start_button->setText( "Stop" );                                //set up stop button
        live->clear( );
        chart->addSeries( live );                                           //add live graph to chart
        const QString title = "Profile Graph: " + profile->get_title( ) + ", " +
                QString::number( profile->get_mins( ) ) + " minutes (Live)";
        chart->setTitle( title );                                           //change title
        chart_view->repaint( );                                             //repaint chart view
        return;                                                             //leave
    }

    //if it's the first time in this instance
    serial = new QSerialPort( this );                                                           //open/setup serial port
    serial->setBaudRate( QSerialPort::Baud9600 );

    if( ( ui->com_box->currentIndex( ) > 0 ) ) {                                                //if a COM Port has been chosen
        serial->setPortName( ui->com_box->currentText( ) );
    }
    else {                                                                                      //if a COM Port has not been chosen
        QMessageBox msg;
        msg.setWindowTitle( "Action Not Permitted" );
        msg.setText( "You must choose a COM port from the drop down menu" );
        msg.addButton( QMessageBox::StandardButton::Ok );
        msg.exec( );
        const QString title = "Profile Graph: " + profile->get_title( ) + ", " +
                QString::number( profile->get_mins( ) ) + " minutes";
        chart->setTitle( title );
        return;
    }

    if( !serial->open( QIODevice::ReadOnly ) ) {                                                 //open the serial port for read only
        QMessageBox msg;
        msg.setWindowTitle( "Cannot Communicate with Roaster" );
        QString str = "Communication with roaster has been interrupted. Either no roaster is plugged in or it has been turned off/disconnected."
                      " Please connect a roaster and try again.\n\nError: " + serial->errorString( );
        msg.setText( str );
        msg.setStandardButtons( QMessageBox::StandardButton::Ok );
        msg.exec( );
        return;
    }
    live = new QSplineSeries( );
    auto l_pen = live->pen( );
    l_pen.setWidth( 3 );
    live->setPen( l_pen );
    live->setName( "Live Roast" );
    chart->addSeries( live );


    rescale( );
    timer = new QTimer( this );
    time_index = 0;
    const QString title = "Profile Graph: " + profile->get_title( ) + ", " +
            QString::number( profile->get_mins( ) ) + " minutes (Live)";
    chart->setTitle( title );
    ui->start_button->setText( "Stop" );
    connect( timer, SIGNAL( timeout( ) ), this, SLOT( update_chart( ) ) );
    timer->start( INTERVAL );
    TIMER_STARTED = true;
    LIVE = true;                                                                                //go live
}

void ControlRoomDialog::update_chart( ) {
    if( LIVE ) {
        if( serial->bytesAvailable( ) < 4 ) return;
        qDebug( ) << "HERE MOFO";
        char temp[4];
        serial->read( temp, 4 );
        serial->clear( );
        const uint8_t y_8val = ( uint8_t ) temp[0];
        const uint8_t dsp_8val = ( uint8_t ) temp[1];
        const uint8_t dh = ( uint8_t ) temp[2];
        const uint8_t fs = ( uint8_t ) temp[3];
        const int y_val = ( int )( y_8val ) * 2;
        const int dsp_val = ( int )( dsp_8val ) * 2;
        const QString str = "Current drum temperature: " + QString::number( y_val ) + "F";
        ui->info_label->setText( str );
        ui->dh_dial->setValue( dh );
        ui->dsp_dial->setValue( dsp_val );
        ui->fs_dial->setValue( fs );
        live->append( time_index, y_val );
        rescale( );
        chart_view->repaint( );
        time_index++;
        if( time_index >= profile->get_mins( ) * 60 ) {
            ui->info_label->clear( );
            //chart->removeSeries( live );
            const QString title = "Profile Graph: " + profile->get_title( ) + ", " +
                    QString::number( profile->get_mins( ) ) + " minutes";
            chart->setTitle( title );
            //chart_view->repaint( );
            ui->start_button->setText( "Start" );
            timer->stop( );
            //live->clear( );
            serial->close( );
            LIVE = false;
        }
    }
}

void ControlRoomDialog::closeEvent( QCloseEvent *event ) {
    if( TIMER_STARTED ) timer->stop( );
    if( LIVE ) serial->close( );
    event->accept( );
}

void ControlRoomDialog::on_com_box_currentTextChanged( const QString &arg1 ) {
    if( LIVE ) return;
    else if( TIMER_STARTED && ui->com_box->currentIndex( ) > 0 ) serial->setPortName( arg1 );
    else return;
}

void ControlRoomDialog::rescale( ) {
    chart->createDefaultAxes( );
    chart->axisX( )->setTitleText( "Seconds" );
    chart->axisX( )->setRange( 0, 1200 );
    chart->axisY( )->setRange( 200, 500 );
    chart->axisY( )->setTitleText( "Temperature (F)" );
    chart_view->setContentsMargins( 0, 0, 0, 0 );
    chart_view->resize( 1021, 401 );
    chart_view->setRenderHint( QPainter::Antialiasing );
}

/*void ControlRoomDialog::mouseMoveEvent( QMouseEvent *e ) {
    QPoint pos = this->mouseGrabber( )->cursor( ).pos( );
    if( pos.x( ) < 532 || pos.x( ) > 1424 || pos.y( ) < 244 || pos.y( ) > 519 ) {
        ui->x_pos->setText( "X: " );
        ui->y_pos->setText( "Y: " );
        releaseMouse( );
        e->accept( );
        grabMouse( );
    }
    else {
        QString pos_str = "X: " + QString::number( pos.x( ) );
        ui->x_pos->setText( pos_str );
        pos_str = "Y: " + QString::number( pos.y( ) );
        ui->y_pos->setText( pos_str );
    }
}*/

void ControlRoomDialog::mousePressEvent( QMouseEvent *e ) {
    if( e->pos( ).x( ) < 80 || e->pos( ).x( ) > 975 || e->pos( ).y( ) < 60 || e->pos( ).y( ) > 335 ) {
        ui->x_pos->setText( "X: " );
        ui->y_pos->setText( "Y: " );
        ui->drum_heat->setText( "Drum Heat: " );
        ui->drum_sp->setText( "Drum Set Point: " );
        ui->fan_sp->setText( "Fan: " );
        e->accept( );
    }
    else {
        const int map_x = ( ( e->pos( ).x( ) )-80 )*( 240.0/179.0 );
        QString pos = "X: " + get_time_str( map_x );
        ui->x_pos->setText( pos );
        const int map_y = ( int )( 200.0 + ( 334.0 - ( double )( e->pos( ).y( ) ) )*( 100.0/79.0 ) );
        pos = "Y: " + QString::number( map_y ) + "F";
        ui->y_pos->setText( pos );
        const int time = e->pos( ).x( ) / 15;
        const QString dh = "Drum Heat: " + QString::number( profile->get( CoffeeRoastingProfile::Index::DRUM_HEAT, time ) ) + "%";
        ui->drum_heat->setText( dh );
        const QString dsp = "Drum Set Point: " + QString::number( profile->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, time ) ) + "F";
        ui->drum_sp->setText( dsp );
        const QString fsp = "Fan: " + QString::number( profile->get( CoffeeRoastingProfile::Index::FAN_SPEED, time ) ) + "%";
        ui->fan_sp->setText( fsp );
    }
}

QString ControlRoomDialog::get_time_str( int sec ) {
    const int min = sec / 60;
    const int s = sec % 60;
    const QString time_str = ( min < 10 ? "0" : "" ) + QString::number( min ) + ":" + ( s < 10 ? "0" : "" ) + QString::number( s );
    return time_str;
}

#include "controlroomdialog.h"
#include "ui_controlroomdialog.h"
using namespace QtCharts;

ControlRoomDialog::ControlRoomDialog( CoffeeRoastingProfile *pro, QWidget *parent ) :
    QDialog(parent),
    ui( new Ui::ControlRoomDialog ) {
    ui->setupUi(this);
    LIVE = false;
    TIMER_STARTED = false;
    SAVED_LOADED = false;
    LEFT_CLICKED = false;
    CHANGED_INTERNALLY = false;
    this->profile = pro;
    beautify( );
    make_graph( );
    load_graphs( );
    ui->save_button->setEnabled( false );
    ui->clear_button->setEnabled( false );
    //this->showMaximized( );
    this->setWindowTitle( "Control Room" );
}

ControlRoomDialog::~ControlRoomDialog( ) {
    delete ui;
}

void ControlRoomDialog::beautify( ) {
    QColor color( 28, 49, 68 );
    this->setWindowTitle( "Control Room" );
    this->setWindowFlags( this->windowFlags( ) & ~Qt::WindowContextHelpButtonHint );
    ui->start_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                     "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->save_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                    "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->load_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                    "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->clear_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                     "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->delete_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                      "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");


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
    for( int i = 1; i < 20; ++i ) ui->com_box->addItem( ( "COM" + QString::number( i ) ) );
    QListView *list2 = new QListView( ui->saved_box );
    list2->setStyleSheet( "QListView {background-color: #c9cacc;}"
                          "QListView::item {"
                          "border-bottom: 1px solid black}"
                          "QListView::item::selected {background-color: #1c3144;"
                          "color: white;}" );
    ui->saved_box->setView( list2 );
    ui->saved_box->setPalette( p );
    ui->x_pos->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->y_pos->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->drum_sp->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->drum_heat->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->fan_sp->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->x_pos->setText( "X: " );
    ui->y_pos->setText( "Y: " );
    ui->drum_heat->setText( "Drum Heat: " );
    ui->drum_sp->setText( "Drum Set Point: " );
    ui->fan_sp->setText( "Fan: " );
}

/*
void ControlRoomDialog::on_dsp_dial_valueChanged( int value ) {
    const QString str = "Drum Set Point: " + QString::number( value ) + "F";
    ui->dsp_label->setText( str );
    if( LIVE ) {                                              //if the serial port is open we send stuff
        if( serial->isOpen( ) ) serial->close( );
        if( !serial->open( QIODevice::WriteOnly ) ) {                                                 //open the serial port for write only
            QMessageBox msg;
            msg.setWindowTitle( "Cannot Communicate with Roaster" );
            QString str = "Communication with roaster has been interrupted. Either no roaster is plugged in or it has been turned off/disconnected."
                          " Please connect a roaster and try again.\n\nError: " + serial->errorString( );
            msg.setText( str );
            msg.setStandardButtons( QMessageBox::StandardButton::Ok );
            msg.exec( );
            return;
        }
        const char buff[6] = {'0',( char )value/2,'1',( char )ui->fs_dial->value( ),'2',( char )ui->dh_dial->value( )};
        serial->write( buff, 6 );
        serial->waitForBytesWritten( );
        serial->close( );
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
    }
}

void ControlRoomDialog::on_dh_dial_valueChanged( int value ) {
    const QString str = "Drum Heat: " + QString::number( value ) + "%";
    ui->dh_label->setText( str );
    if( LIVE ) {                                              //if the serial port is open we send stuff
        if( serial->isOpen( ) ) serial->close( );
        if( !serial->open( QIODevice::WriteOnly ) ) {                                                 //open the serial port for read only
            QMessageBox msg;
            msg.setWindowTitle( "Cannot Communicate with Roaster" );
            QString str = "Communication with roaster has been interrupted. Either no roaster is plugged in or it has been turned off/disconnected."
                          " Please connect a roaster and try again.\n\nError: " + serial->errorString( );
            msg.setText( str );
            msg.setStandardButtons( QMessageBox::StandardButton::Ok );
            msg.exec( );
            return;
        }
        const char buff[6] = {'0',( char )ui->dsp_dial->value( ),'1',( char )ui->fs_dial->value( ),'2',( char )value};
        serial->write( buff, 6 );
        serial->close( );
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
    }
}

void ControlRoomDialog::on_fs_dial_valueChanged( int value ) {
    const QString str = "Fan Speed: " + QString::number( value ) + "%";
    ui->fs_label->setText( str );
    if( LIVE ) {                                              //if the serial port is open we send stuff
        if( serial->isOpen( ) ) serial->close( );
        if( !serial->open( QIODevice::WriteOnly ) ) {                                                 //open the serial port for read only
            QMessageBox msg;
            msg.setWindowTitle( "Cannot Communicate with Roaster" );
            QString str = "Communication with roaster has been interrupted. Either no roaster is plugged in or it has been turned off/disconnected."
                          " Please connect a roaster and try again.\n\nError: " + serial->errorString( );
            msg.setText( str );
            msg.setStandardButtons( QMessageBox::StandardButton::Ok );
            msg.exec( );
            return;
        }
        const char buff[6] = {'0',( char )ui->dsp_dial->value( ),'1',( char )value,'2',( char )ui->dh_dial->value( )};
        serial->write( buff, 6 );
        serial->close( );
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
    }
}*/

void ControlRoomDialog::make_graph( ) {
    selected_profile_graph = new QSplineSeries( );
    const int pts = ( profile->get_mins( ) ) * 4;
    for( int i = 0; i < pts; ++i ) {
        const int temp = profile->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, i );
        selected_profile_graph->append( i*15, temp );
    }
    chart = new QChart( );
    chart->addSeries( selected_profile_graph );
    selected_profile_graph->setName( profile->get_title( ) );
    auto s_pen = selected_profile_graph->pen( );
    s_pen.setWidth( 3 );
    selected_profile_graph->setPen( s_pen );
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
    ui->save_button->setEnabled( false );
    if( LIVE ) {                                                            //if we are already live
        timer->stop( );                                                     //stop the timer
        LIVE = false;                                                       //leave live
        ui->start_button->setText( "Start" );                               //set up start button
        chart->removeSeries( live_bean_graph );                                        //remove the live graphs from the chart
        chart->removeSeries( live_air_graph );
        chart_view->repaint( );                                             //repaint chart view
        live_bean_graph->clear( );                                                     //clear the info in the live graphs
        live_air_graph->clear( );
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
        live_bean_graph->clear( );
        live_air_graph->clear( );
        chart->addSeries( live_bean_graph );                                           //add live graphs to chart
        chart->addSeries( live_air_graph );
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
    serial->clear( );
    live_bean_graph = new QSplineSeries( );
    live_air_graph = new QSplineSeries( );
    recorded_profile = new CoffeeRoastingProfile( );
    recorded_profile->set_title( profile->get_title( ) );
    auto l_pen = live_bean_graph->pen( );
    l_pen.setWidth( 3 );
    l_pen.setColor( Qt::red );
    live_bean_graph->setPen( l_pen );
    l_pen.setColor( Qt::green );
    live_air_graph->setPen( l_pen );
    live_bean_graph->setName( "Live Bean Temperature" );
    live_air_graph->setName( "Live Air Temperature" );
    chart->addSeries( live_bean_graph );
    chart->addSeries( live_air_graph );
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
    LIVE = true;
}

void ControlRoomDialog::update_chart( ) {
    if( time_index == 1 ) ui->save_button->setEnabled( true );
    if( LIVE ) {
        if( serial->bytesAvailable( ) < 8 ) return;
        char buff[8];
        serial->read( buff, 8 );
        serial->clear( );
        if( buff[0] == '0' && buff[2] == '1' && buff[4] == '2' && buff[6] == '3' ) {
            const uint8_t bean_y_8val = ( uint8_t ) buff[1];
            const int bean_y_val = ( int )( bean_y_8val ) * 2;
            const uint8_t air_y_8val = ( uint8_t ) buff[3];
            const int air_y_val = ( int )( air_y_8val ) * 2;
            const uint8_t burner_val = ( uint8_t ) buff[5];
            const uint8_t fan_val = ( uint8_t ) buff[7];
            recorded_profile->set_data( -1, {500,bean_y_val,100,burner_val,fan_val} );
            if( air_y_val >= 200 ) live_air_graph->append( time_index, air_y_val );
            if( bean_y_val >= 200 ) live_bean_graph->append( time_index, bean_y_val );
            if( bean_y_val >= 200 || air_y_val >= 200 ) {
                rescale( );
                chart_view->repaint( );
            }

            /*CHANGED_INTERNALLY = true;
            const uint8_t dsp_8val = ( uint8_t ) buff[3];
            const int dsp_val = ( int )( dsp_8val ) * 2;
            ui->dsp_dial->setValue( dsp_val );
            CHANGED_INTERNALLY = true;
            const uint8_t dh = ( uint8_t ) buff[5];
            ui->dh_dial->setValue( dh );
            CHANGED_INTERNALLY = true;
            const uint8_t fs = ( uint8_t ) buff[7];
            ui->fs_dial->setValue( fs );*/
        }

        time_index++;

        if( time_index >= profile->get_mins( ) * 60 ) {
            const QString title = "Profile Graph: " + profile->get_title( ) + ", " +
                    QString::number( profile->get_mins( ) ) + " minutes";
            chart->setTitle( title );
            ui->start_button->setText( "Start" );
            timer->stop( );
            serial->close( );
            LIVE = false;
            recorded_profile->set_mins( );
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

        if( e->button( ) == Qt::LeftButton  ) {
            if( LEFT_CLICKED ) LEFT_CLICKED = false;
            else {
                LEFT_CLICKED = true;
                l_pos.setX( map_x );
                l_pos.setY( map_y );
            }
        }
        else if( e->button( ) == Qt::RightButton ) {
            if( LEFT_CLICKED ) {
                LEFT_CLICKED = false;
                double slope = ( ( float )( map_y - l_pos.y( ) ) ) / ( ( float )( map_x - l_pos.x( ) ) );
                slope *= 60.0;
                QMessageBox msg;
                const QString str = "Slope = " + QString::number( ( int )slope ) + " F/min";
                msg.setText( str );
                msg.exec( );
            }
        }
    }
}

QString ControlRoomDialog::get_time_str( int sec ) {
    const int min = sec / 60;
    const int s = sec % 60;
    const QString time_str = ( min < 10 ? "0" : "" ) + QString::number( min ) + ":" + ( s < 10 ? "0" : "" ) + QString::number( s );
    return time_str;
}

void ControlRoomDialog::load_graphs( ) {
    QFile graphs( "recordings.json" );
    if( !graphs.open( QIODevice::ReadOnly ) ) return;

    QByteArray ba = graphs.readAll( );
    if( ba.size( ) == 0 ) return;
    QJsonDocument doc( QJsonDocument::fromJson( ba ) );
    QJsonObject graphs_obj = doc.object( );
    const int num = graphs_obj["count"].toInt( );

    for( int i = 0; i < num; ++i ) {
        CoffeeRoastingProfile *r_graph = new CoffeeRoastingProfile( );
        QJsonObject graph = graphs_obj[QString::number( i )].toObject( );
        r_graph->read( graph );
        ui->saved_box->addItem( r_graph->get_title( ) );
        recorded_graphs.append( r_graph );
    }
    graphs.close( );
}

void ControlRoomDialog::on_load_button_clicked( ) {
    if( LIVE || recorded_graphs.size( ) < 1 ) return;
    if( SAVED_LOADED ) chart->removeSeries( saved );
    const int index = ui->saved_box->currentIndex( );
    CoffeeRoastingProfile *curr_graph = recorded_graphs[index];
    this->saved = new QSplineSeries( );
    auto s_pen = saved->pen( );
    s_pen.setWidth( 3 );
    s_pen.setColor( Qt::gray );
    saved->setPen( s_pen );
    const QString t = curr_graph->get_title( );
    const QString title = t + " (Saved)";
    for( int i = 0; i < curr_graph->num_data_points( ); ++i )
        saved->append( i, curr_graph->get( CoffeeRoastingProfile::DRUM_SET_PT, i ) );
    saved->setName( title );
    chart->addSeries( saved );
    rescale( );
    SAVED_LOADED = true;
    ui->clear_button->setEnabled( true );
}

void ControlRoomDialog::on_save_button_clicked( ) {
    recorded_profile->set_mins( );
    recorded_graphs.append( recorded_profile );
    update_memory( );
    QMessageBox msg;
    msg.setText( "Waveform has been saved, exit and re-enter to load it." );
    msg.exec( );
}

void ControlRoomDialog::on_clear_button_clicked( ) {
    if( LIVE ) return;
    chart->removeSeries( saved );
    chart_view->repaint( );
}

void ControlRoomDialog::on_delete_button_clicked( ) {
    recorded_graphs.remove( ui->saved_box->currentIndex( ) );
    ui->saved_box->removeItem( ui->saved_box->currentIndex( ) );
    update_memory( );
}

void ControlRoomDialog::update_memory( ) {
    QFile::remove( "recordings.json" );
    QFile graphs( "recordings.json" );
    if( !graphs.open( QIODevice::WriteOnly ) ) return;
    QJsonObject s_graphs;
    s_graphs["count"] = recorded_graphs.size( );
    for( int i = 0; i < recorded_graphs.size( ); ++i ) {
        QJsonObject json;
        recorded_graphs[i]->write( json );
        s_graphs[QString::number( i )] = json;
    }
    QJsonDocument doc( s_graphs );
    graphs.write( doc.toJson( ) );
    graphs.close( );
}

#include "graphicalcreatordialog.h"
#include "ui_graphicalcreatordialog.h"

GraphicalCreatorDialog::GraphicalCreatorDialog( QWidget *parent ) :
    QDialog( parent ),
    ui( new Ui::GraphicalCreatorDialog ) {
    ui->setupUi( this );
    beautify( );
    read_memory( );
    last_point = QPoint( 0, 500 );
    ui->save_button->setEnabled( false );
}

GraphicalCreatorDialog::~GraphicalCreatorDialog( ) {
    delete ui;
}

void GraphicalCreatorDialog::on_new_button_clicked( ) {
    NEW = true;
    SAVED = false;
    //ui->saved_box->setEnabled( false );
    make_graph( false );
    series->setName( "Custom" );
    ui->load_button->setText( "Undo" );
    ui->save_button->setEnabled( true );
    drawn_graph_index = 0;
}

void GraphicalCreatorDialog::beautify( void ) {
    this->setWindowTitle( "Graphical Profile Creator" );
    this->setWindowFlags( this->windowFlags( ) & ~Qt::WindowContextHelpButtonHint );
    ui->new_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                   "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->load_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                    "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->clear_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                     "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->save_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                    "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
}

void GraphicalCreatorDialog::make_graph( bool for_saved ) {
    series = new QSplineSeries( );
    chart = new QChart( );
    chart->addSeries( series );
    auto s_pen = series->pen( );
    s_pen.setWidth( 3 );
    series->setPen( s_pen );
    chart_view = new QChartView( chart, ui->graph_widget );
    rescale( );
}

void GraphicalCreatorDialog::on_save_button_clicked( ) {
    if( ui->name_edit->text( ).trimmed( ).isEmpty( ) ) {
        QMessageBox msg;
        msg.setWindowTitle( "Action not permitted" );
        msg.setText( "Please choose a name for your new profile" );
        msg.exec( );
        return;
    }
    CoffeeRoastingProfile *p = new CoffeeRoastingProfile( ui->name_edit->text( ), drawn_graph.get_size( )/60, 0, profiles.size( ) );
    for( int i = 0; i < drawn_graph.get_size( ); i += 15 )
        p->set_data( -1, {500,drawn_graph.get_data( i ),100,100,100} );
    profiles.append( p );
    write_memory( );
    QMessageBox msg;
    msg.setWindowTitle( "Saved" );
    msg.setText( "Your profile has been created and added, the main window's list will update once you close out of this window." );
    msg.exec( );
}

void GraphicalCreatorDialog::read_memory( void ) {
    QFile p( "profiles.json" );                                         //create the file object to read profiles from json encoding
    if( !p.open( QIODevice::ReadOnly ) ) return;                        //if the file fails to open we just get out of here
    QByteArray ba = p.readAll( );                                       //read file information as a byte array
    QJsonDocument doc( QJsonDocument::fromJson( ba ) );                 //create json doc object from byte array
    QVector<QJsonObject> json_array;                                    //create json object array
    QJsonObject json = doc.object( );                                   //get the json object from the document
    const int num_profiles = json["count"].toInt( );                    //read in the number of profiles saved

    for( int i = 0; i < num_profiles; ++i )                             //loop through the json object of objects
        json_array.append( json[QString::number( i )].toObject( ) );    //extract each json object which contains a profile

    for( int i = 0; i < json_array.size( ); ++i ) {                     //loop through the json objects
        CoffeeRoastingProfile* profile = new CoffeeRoastingProfile( );  //create new profile object
        profile->read( json_array.at( i ) );
        profiles.push_back( profile );                                  //add the profile to the current list
    }
    p.close( );                                                         //close the file since we are done
}

void GraphicalCreatorDialog::write_memory( void ) {
    QFile::remove( "profiles.json" );                                            //remove the file so we can clean
    QFile p( "profiles.json" );                                                  //create the file object
    p.open( QIODevice::WriteOnly );                                              //open the file again (recreating it)
    QJsonObject json_profiles;                                                   //create json object to hold all the profiles
    json_profiles["count"] = profiles.size( );                                   //add the count value to the top json object
    for( int i = 0; i < profiles.size( ); ++i ) {                                //loop through current profiles in RAM
        QJsonObject json;                                                        //make json object
        profiles[i]->write( json );                                              //write profile to json
        json_profiles[QString::number( i )] = json;                              //insert a profile json object into the top json object
    }
    QJsonDocument doc( json_profiles );                                          //create json document obect from the json object
    p.write( doc.toJson( ) );                                                    //write json info to file as a string
    p.close( );                                                                  //close file
}

void GraphicalCreatorDialog::on_clear_button_clicked( ) {
    series->clear( );
    pts.clear( );
    rescale( );
}

void GraphicalCreatorDialog::rescale( ) {
    chart->createDefaultAxes( );
    chart->axisX( )->setTitleText( "Seconds" );
    chart->axisX( )->setLineVisible( );
    chart->axisX( )->setRange( 0, 1200 );
    chart->axisY( )->setLineVisible( );
    chart->axisY( )->setRange( 200, 500 );
    chart->axisY( )->setTitleText( "Temperature (F)" );
    chart_view->setContentsMargins( 0, 0, 0, 0 );
    chart_view->resize( 1011, 401 );
    chart_view->setRenderHint( QPainter::Antialiasing );
    chart_view->show( );
}

void GraphicalCreatorDialog::mousePressEvent( QMouseEvent *e ) {
    auto pos = e->pos( );
    if( !NEW || pos.x( ) > 974 || pos.x( ) < 91 || pos.y( ) > 393 || pos.y( ) < 134 )
        e->accept( );
    else {
        const int x = ( int )( ( ( double )( pos.x( ) ) - 91.0 ) * 1.359 );
        const int y = ( int )( 200.0 + ( 393.0 - ( double )( pos.y( ) ) )*1.158 );
        series->append( x, y );
        if( drawn_graph.get_size( ) < 900 && x < 900 ) {
            check_slope( x, y );
            drawn_graph.append( y, x - drawn_graph_index );
            drawn_graph_index = x;
        }
        pts.push( QPoint( x, y ) );
        rescale( );
    }
}

void GraphicalCreatorDialog::check_slope( int x, int y ) {
    if( x - last_point.x( ) == 0 ) return;
    const double slope = ( ( double )( y - last_point.y( ) ) ) / ( ( double )( x - last_point.x( ) ) );
    last_point = QPoint( x, y );
    if( slope > 0.7 ) {
        QMessageBox msg;
        msg.setWindowTitle( "Temperature Rise May Be Too High" );
        msg.setText( "The last two points you have drawn have too much of a rise for the time frame between them. The roaster may"
                     " not be able to handle it. You may keep this, but we suggest clicking \"Undo\" and trying different points." );
        msg.exec( );
    }
}

#include "graphicalcreatordialog.h"
#include "ui_graphicalcreatordialog.h"

GraphicalCreatorDialog::GraphicalCreatorDialog( QWidget *parent ) :
    QDialog( parent ),
    ui( new Ui::GraphicalCreatorDialog ) {
    ui->setupUi( this );
    beautify( );
    load_graphs( );
    read_memory( );
}

GraphicalCreatorDialog::~GraphicalCreatorDialog( ) {
    delete ui;
}

void GraphicalCreatorDialog::on_saved_button_clicked( ) {
    SAVED = true;
    LIVE = false;
    NEW = false;
    ui->load_button->setText( "Load" );
    ui->clear_button->setText( "Clear" );
    ui->save_button->setText( "Save" );
    ui->saved_box->setEnabled( true );
}

void GraphicalCreatorDialog::on_live_button_clicked( ) {
    LIVE = true;
    SAVED = false;
    NEW = false;
    ui->load_button->setText( "Start" );
    ui->clear_button->setText( "Stop" );
    ui->save_button->setText( "Save" );
    ui->saved_box->setEnabled( false );
}

void GraphicalCreatorDialog::on_new_button_clicked( ) {
    NEW = true;
    SAVED = false;
    LIVE = false;
    ui->load_button->setText( "Start" );
    ui->clear_button->setText( "Clear" );
    ui->save_button->setText( "Save" );
    ui->saved_box->setEnabled( false );
}

void GraphicalCreatorDialog::beautify( void ) {
    this->setWindowTitle( "Graphical Profile Creator" );
    this->setWindowFlags( this->windowFlags( ) & ~Qt::WindowContextHelpButtonHint );
    ui->saved_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                     "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->live_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                    "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->new_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                   "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->load_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                    "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->clear_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                     "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    ui->save_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                    "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}");
    QListView *list1 = new QListView( ui->saved_box);
    list1->setStyleSheet( "QListView {background-color: #c9cacc;}"
                          "QListView::item {"
                          "border-bottom: 1px solid black}"
                          "QListView::item::selected {background-color: #1c3144;"
                          "color: white;}" );
    ui->saved_box->setView( list1 );
    QPalette p = ui->saved_box->palette( );
    p.setColor( QPalette::Highlight, QColor( 28, 49, 68 ) );
    ui->saved_box->setPalette( p );
}

void GraphicalCreatorDialog::make_graph( void ) {
    const int index = ui->saved_box->currentIndex( );
    series = new QSplineSeries( );
    const int pts = saved_graphs[index]->get_size( );
    for( int i = 0; i < pts; ++i ) {
        const int temp = saved_graphs[index]->get_data( i );
        series->append( i, temp );
    }
    chart = new QChart( );
    chart->addSeries( series );
    series->setName( saved_graphs[index]->get_title( ) );
    auto s_pen = series->pen( );
    s_pen.setWidth( 3 );
    series->setPen( s_pen );
    chart->createDefaultAxes( );
    const QString title = "Profile Graph: " + saved_graphs[index]->get_title( );
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
    chart_view->resize( 1011, 401 );
    chart_view->setRenderHint( QPainter::Antialiasing );
    chart_view->show( );
}

void GraphicalCreatorDialog::on_load_button_clicked( ) {
    if( SAVED ) {
        make_graph( );
        id = ui->saved_box->currentIndex( );
    }
}

void GraphicalCreatorDialog::load_graphs( void ) {
    QFile graphs( "graphs.json" );
    if( !graphs.open( QIODevice::ReadOnly ) ) return;

    QByteArray ba = graphs.readAll( );
    if( ba.size( ) == 0 ) return;
    QJsonDocument doc( QJsonDocument::fromJson( ba ) );
    QJsonObject graphs_obj = doc.object( );
    const int num = graphs_obj["count"].toInt( );

    for( int i = 0; i < num; ++i ) {
        RoastGraph *r_graph = new RoastGraph( );
        QJsonObject graph = graphs_obj[QString::number( i )].toObject( );
        r_graph->fromJSON( graph );
        ui->saved_box->addItem( r_graph->get_title( ) );
        saved_graphs.append( r_graph );
    }
    graphs.close( );
}

void GraphicalCreatorDialog::on_save_button_clicked( ) {
    if( SAVED ) {
        if( saved_graphs.size( ) < 1 ) return;
        if( ui->name_edit->text( ).trimmed( ).isEmpty( ) ) {
            QMessageBox msg;
            msg.setWindowTitle( "Action not permitted" );
            msg.setText( "Please choose a name for your new profile" );
            msg.exec( );
            return;
        }
        CoffeeRoastingProfile *p = saved_graphs[id]->to_profile( );
        p->set_title( ui->name_edit->text( ) );
        profiles.append( p );
        write_memory( );
        QMessageBox msg;
        msg.setWindowTitle( "Saved" );
        msg.setText( "Your profile has been created and added, the main window's list will update once you close out of this window." );
        msg.exec( );
    }
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
    QFile::remove( "profiles.json" );                                                   //remove the file so we can clean
    QFile p( "profiles.json" );                                                  //create the file object
    p.open( QIODevice::WriteOnly );                                              //open the file again (recreating it)
    QJsonObject json_profiles;                                                          //create json object to hold all the profiles
    json_profiles["count"] = profiles.size( );                                   //add the count value to the top json object
    for( int i = 0; i < profiles.size( ); ++i ) {                                //loop through current profiles in RAM
        QJsonObject json;                                                               //make json object
        profiles[i]->write( json );                                              //write profile to json
        json_profiles[QString::number( i )] = json;                                     //insert a profile json object into the top json object
    }
    QJsonDocument doc( json_profiles );                                          //create json document obect from the json object
    p.write( doc.toJson( ) );                                                    //write json info to file as a string
    p.close( );                                                                  //close file
}

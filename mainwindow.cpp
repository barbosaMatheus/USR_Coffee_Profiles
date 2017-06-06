#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    beautify( );
    hide_right_side( );                        //hide stuff on the right side that will show up only when needed
    data_model = new QStringListModel( this ); //create an object to the data model
    table_model = new QStandardItemModel( 80, 5, this ); //create an object for the table model
    ui->time_box->addItem( "15 minutes" );   //add item to combo box
    ui->time_box->addItem( "20 minutes" );
    set_headers( );                            //set table headers
    ui->pro_table->setModel( table_model );    //attach model to table
    ui->pro_list->setModel( data_model );      //connect the list ui object to the model
    populate_list( );                          //populate local list of profiles
    //hide extra rows since 15 min is default
    for( int i = 60; i < 80; i++ ) {
        ui->pro_table->setRowHidden( i, true );
    }
}

void MainWindow::beautify( void ) {
    this->setStyleSheet( "background-color: white" );
    ui->pro_table->setStyleSheet( "QTableView::item::selected { color: white; background-color: red }" );
    ui->pro_list->setStyleSheet( "QListView::item { border-bottom: 1px solid black; selection-color: red }" );
    ui->new_button->setStyleSheet( "color: white; background-color: blue" );
    ui->cancel_button->setStyleSheet( "color: white; background-color: red" );
    ui->create_button->setStyleSheet( "color: white; background-color: blue" );
    ui->select_button->setStyleSheet( "color: white; background-color: blue" );
    ui->set_button->setStyleSheet( "color: white; background-color: blue" );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populate_list( void ) {
    //mock populating of profiles list
    list << "Costa Rican Dark" << "Colombian Light" << "Brazilian Dark";
    data_model->setStringList( list );
}

void MainWindow::set_headers( void ) {
    //populate horizontal and vertical label lists for table
    horizontal_labels << "Catalyst Set Point" << "Drum Set Point"
                      << "Catalyst Heater %" << "Drum Heater %" << "Fan Speed %";
    for( int i = 0; i < 20; i++ ) {
        QString s1 = ( i < 10 ? "0" : "" ) + QString::number( i ) + ":00";
        QString s2 = ( i < 10 ? "0" : "" ) + QString::number( i ) + ":15";
        QString s3 = ( i < 10 ? "0" : "" ) + QString::number( i ) + ":30";
        QString s4 = ( i < 10 ? "0" : "" ) + QString::number( i ) + ":45";
        vertical_labels << s1 << s2 << s3 << s4;
    }

    table_model->setHorizontalHeaderLabels( horizontal_labels );
    table_model->setVerticalHeaderLabels( vertical_labels );
}

void MainWindow::hide_right_side( void ) {
    ui->choose_label->setVisible( false );
    ui->time_box->setVisible( false );
    ui->select_button->setVisible( false );
    ui->cancel_button->setVisible( false );
    ui->pro_table->setVisible( false );
    ui->set_button->setVisible( false );
    ui->value_box->setVisible( false );
    ui->create_button->setVisible( false );
    ui->name_edit->setVisible( false );
}

void MainWindow::on_new_button_clicked( )
{
    ui->choose_label->setVisible( true );
    ui->time_box->setVisible( true );
    ui->select_button->setVisible( true );
    ui->cancel_button->setVisible( true );
    ui->pro_table->setVisible( true );
    ui->set_button->setVisible( true );
    ui->value_box->setVisible( true );
    ui->create_button->setVisible( true );
    ui->name_edit->setVisible( true );
}

void MainWindow::on_cancel_button_clicked( )
{
    hide_right_side( );
    table_model->clear( );
    table_model->setColumnCount( 5 );
    table_model->setRowCount( 80 );
    table_model->setHorizontalHeaderLabels( horizontal_labels );
    table_model->setVerticalHeaderLabels( vertical_labels );
}

void MainWindow::on_select_button_clicked( )
{
    if( ui->time_box->currentIndex( ) == 0 ) {
        for( int i = 60; i < 80; i++ ) {
            ui->pro_table->setRowHidden( i, true );
        }
    }
    else if( ui->time_box->currentIndex( ) == 1 ) {
        for( int i = 60; i < 80; i++ ) {
            ui->pro_table->setRowHidden( i, false );
        }
    }
    else return;
}

void MainWindow::on_pro_table_clicked(const QModelIndex &index)
{
    int val = index.data( ).toInt( );
    ui->value_box->setValue( val );
}

void MainWindow::on_set_button_clicked()
{
    auto selected = this->ui->pro_table->selectionModel( )->selectedIndexes( );
    if( selected.size( ) > 0 ) {
        int val = ui->value_box->value( );
        for( int i = 0; i < selected.size( ); i++ ) table_model->setData( selected.at( i ), val );
    }
}

void MainWindow::on_create_button_clicked()
{
    QString str = ui->name_edit->text( );
    list << str;
    data_model->setStringList( list );
}

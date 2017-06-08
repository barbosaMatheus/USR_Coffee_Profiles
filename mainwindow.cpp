#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi(this);
    set_up_menu( );
    beautify( );                                            //changes style sheets for buttons, list and table
    hide_right_side( );                                     //hide stuff on the right side that will show up only when needed
    data_model = new QStringListModel( this );              //create an object to the data model
    table_model = new QStandardItemModel( 80, 5, this );    //create an object for the table model
    set_headers( );                                         //set table headers for vertical and horizontal
    ui->pro_table->setModel( table_model );                 //attach model to table
    ui->pro_list->setModel( data_model );                   //connect the list ui object to the model
    populate_list( );                                       //populate local list of profiles
    for( int i = 60; i < 80; i++ ) {                        //hide extra rows since 15 min is default
        ui->pro_table->setRowHidden( i, true );
    }
}



//style sheet settings for the window background, buttons, the list and the table
//NOTE: make UI more beautiful?
void MainWindow::beautify( ) {
    QColor color( 28, 49, 68 );
    this->setStyleSheet( "background-color: white" );
    ui->pro_table->setEditTriggers( QAbstractItemView::NoEditTriggers );
    ui->pro_table->setStyleSheet( "QTableView::item::selected { color: white; background-color: #70161e }" );
    ui->pro_list->setStyleSheet( "QListView::item { border-bottom: 1px solid black;}"
                                 "QListView::item::selected {background-color: #1c3144;"
                                 "color: white;}" );
    ui->new_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->cancel_button->setStyleSheet( "color: white; background-color: #70161e" );
    ui->save_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->select_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->set_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->download_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->edit_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->remove_button->setStyleSheet( "color: white; background-color: #70161e" );
    menuBar( )->setStyleSheet( "QMenuBar {background-color: #c9cacc;"
                               "color: black;}"
                               "QMenuBar::item:selected {color: white;"
                               "background-color: #1c3144;}"
                               "QMenu {background-color: #c9cacc;"
                               "color: black;}"
                               "QMenu::item {background-color: #c9cacc;}"
                               "QMenu::item::selected {background-color: #1c3144;"
                               "color: white;}" );
    ui->status_label->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->label->setStyleSheet( "color: white; background-color: #1c3144;" );
    ui->choose_label->setStyleSheet( "color: white; background-color: #1c3144;" );
    QPalette p0 = ui->value_box->palette( );
    p0.setColor( QPalette::Highlight, color );
    ui->value_box->setPalette( p0 );
    ui->name_edit->setPalette( p0 );
    menuBar( )-> setPalette( p0 );

    //making the roaster drop down look good
    QListView * list1 = new QListView( ui->roaster_box );
    ui->roaster_box->addItem( "Choose a roaster" );
    ui->roaster_box->addItem( "Mini Rev 1kg" );
    list1->setStyleSheet( "QListView {background-color: #c9cacc;}"
                          "QListView::item {"
                          "border-bottom: 1px solid black}"
                          "QListView::item::selected {background-color: #1c3144;"
                          "color: white;}" );
    ui->roaster_box->setView( list1 );
    QPalette p1 = ui->roaster_box->palette( );
    p1.setColor( QPalette::Highlight, color );
    ui->roaster_box->setPalette( p1 );

    //making the profile length drop down look good
    QListView *list2 = new QListView( ui->time_box );
    ui->time_box->addItem( "15 minutes" );                  //add items to profile time combo box
    ui->time_box->addItem( "20 minutes" );
    list2->setStyleSheet( "QListView {background-color: #c9cacc;}"
                          "QListView::item {"
                          "border-bottom: 1px solid black}"
                          "QListView::item::selected {background-color: #1c3144;"
                          "color: white;}" );
    ui->time_box->setView( list2 );
    ui->time_box->setPalette( p1 );
}



//sets up the menu bar at the top
void MainWindow::set_up_menu( ) {
    QAction *help = new QAction( "&User Help", this );
    QAction *contact = new QAction( "&Contact Us", this );
    QAction *quit = new QAction( "&Quit", this );
    QMenu *Help;
    QMenu *file;
    file = menuBar( )->addMenu( "&File" );
    Help = menuBar( )->addMenu( "&Help" );
    Help->addAction( help );
    Help->addAction( contact );
    file->addAction( quit );
    connect( help, SIGNAL( triggered( ) ), this, SLOT( help( ) ) );
    connect( quit, SIGNAL( triggered( ) ), this, SLOT( quit( ) ) );
    connect( contact, SIGNAL( triggered( ) ), this, SLOT( contact( ) ) );
}



MainWindow::~MainWindow( )
{
    delete ui;
}



//populating of profiles list with mock profiles for now
//TODO: get profiles from the cloud and not generated locally
void MainWindow::populate_list( ) {
    list << "Costa Rican Dark" << "Colombian Light" << "Brazilian Dark";
    data_model->setStringList( list );
}



//populate horizontal and vertical label lists for table
void MainWindow::set_headers( ) {
    //sets the horizontal headers which are the profile attributes
    horizontal_labels << "Catalyst Set Point" << "Drum Set Point"
                      << "Catalyst Heater %" << "Drum Heater %" << "Fan Speed %";
    //sets the vertical headers which are time stamps
    //with 15 seconds intervals
    for( int i = 0; i < 20; i++ ) {  //from 0 to 19 minutes
        QString s1 = ( i < 10 ? "0" : "" ) + QString::number( i ) + ":00";  //set the 00 interval
        QString s2 = ( i < 10 ? "0" : "" ) + QString::number( i ) + ":15";  //set the 15 interval
        QString s3 = ( i < 10 ? "0" : "" ) + QString::number( i ) + ":30";  //set the 30 interval
        QString s4 = ( i < 10 ? "0" : "" ) + QString::number( i ) + ":45";  //set the 45 interval
        vertical_labels << s1 << s2 << s3 << s4;
    }

    //these lines are what actually change/set the headers
    table_model->setHorizontalHeaderLabels( horizontal_labels );
    table_model->setVerticalHeaderLabels( vertical_labels );
}



//hides the right side of the window for when the
//user doesn't need it
void MainWindow::hide_right_side( ) {
    ui->choose_label->setVisible( false );
    ui->time_box->setVisible( false );
    ui->select_button->setVisible( false );
    ui->cancel_button->setVisible( false );
    ui->pro_table->setVisible( false );
    ui->set_button->setVisible( false );
    ui->value_box->setVisible( false );
    ui->save_button->setVisible( false );
    ui->name_edit->setVisible( false );

    ui-> status_label->setText( " ..." );
}



//button click handler for the new profile button:
//makes the right side visible so the user can
//use the table
void MainWindow::on_new_button_clicked( )
{
    ui-> status_label->setText( " New profile being created" );
    ui->choose_label->setVisible( true );
    ui->time_box->setVisible( true );
    ui->select_button->setVisible( true );
    ui->cancel_button->setVisible( true );
    ui->pro_table->setVisible( true );
    ui->set_button->setVisible( true );
    ui->value_box->setVisible( true );
    ui->value_box->setValue( 0 );
    ui->save_button->setVisible( true );
    ui->name_edit->setVisible( true );
    ui->name_edit->setText( "" );
}



//button click handler for the cancel button:
//hides the right side of the window and resets
//the table information for the next creation
void MainWindow::on_cancel_button_clicked( )
{
    hide_right_side( );                                             //hide the right side of the window
    table_model->clear( );                                          //clears the model which also clears labels and sizes
    table_model->setColumnCount( 5 );                               //reset column size
    table_model->setRowCount( 80 );                                 //reset row size
    table_model->setHorizontalHeaderLabels( horizontal_labels );    //the labels objects are unchanged so we just have to reset
    table_model->setVerticalHeaderLabels( vertical_labels );
}



//button click handler for the select button:
//hides or shows extra rows in the table
//depending on the length of the roast
void MainWindow::on_select_button_clicked( )
{
    if( ui->time_box->currentIndex( ) == 0 ) {          //if combo box selected index 0
        for( int i = 60; i < 80; i++ ) {                //from row 60 to 79
            ui->pro_table->setRowHidden( i, true );     //show row i
        }
    }
    else if( ui->time_box->currentIndex( ) == 1 ) {     //if combo box selected index 1
        for( int i = 60; i < 80; i++ ) {                //from row 60 to 79
            ui->pro_table->setRowHidden( i, false );    //hide row i
        }
    }
    else return;
}



//click event handler for the table cells:
//takes the data from the table and puts
//it in the spinner box for editing
void MainWindow::on_pro_table_clicked(const QModelIndex &index)
{
    int val = index.data( ).toInt( );       //save the value of the clicked cell
    ui->value_box->setValue( val );         //set the value box value to the saved value
}



//button click handler for the set button:
//fetches all selected cells and changes
//their value to the current value in
//the value spinner box. Works for 1 or
//any number of cells
void MainWindow::on_set_button_clicked( )
{
    auto selected = this->ui->pro_table->selectionModel( )->selectedIndexes( );                     //gets all selected cells in a QVector
    if( selected.size( ) > 0 ) {                                                                    //if non-empty
        int val = ui->value_box->value( );                                                          //save value box value
        for( int i = 0; i < selected.size( ); i++ ) {
            if( ( selected.at( i ).column( ) < 2 ) && ( val >= 0 ) && ( val <= 600 ) ) {            //if set point value is in-bounds
                table_model->setData( selected.at( i ), val );                                      //set cell i to the saved value
            }
            else if( ( selected.at( i ).column( ) >= 2 ) && ( val >= 0 ) && ( val <= 100 ) ){       //if percentage value is in bounds
                table_model->setData( selected.at( i ), val );                                      //set cell i to the saved value
            }
            else {                                                                                  //if values are out of bounds
                QMessageBox warning;
                warning.setWindowTitle( "Value Out of Bounds" );
                QString str = "You entered a value that is not allowed, the property will be unchanged."
                              "\nUse values between 0-600 for set points, and 0-100 for percentages.";
                warning.setText( str );
                warning.setStandardButtons( QMessageBox::StandardButton::Ok );
                warning.exec( );                                                                    //send warning to the user
                ui->value_box->clear( );
            }
        }
    }
}



//button click handler for the save button:
//checks to see if we have a valid profile name
//and if so adds the new name to the list
void MainWindow::on_save_button_clicked( )
{
    QString str = ui->name_edit->text( );
    if( str.isEmpty( ) ) {                                          //if the user tries to create a nameless profile
        ui-> status_label->setText( " Cannot add empty name" );       //send the warning message
        return;                                                     //return so we do nothing else in this function
    }
    list << str;                                                    //append new name to the list
    data_model->setStringList( list );                              //reset the models string list so it updates
    QString status = str + " profile added";                        //inform the user that a new profile was added
    ui->status_label->setText( status );
}



//button click handler for the download button:
//checks to see if a roaster was selected. If
//yes, downloads the current profile to the roaster.
//If not, it sends a warning message to the user
void MainWindow::on_download_button_clicked( )
{
    if( ui->roaster_box->currentIndex( ) > 0 ) {                                    //if a roaster has been chosen
        ui->download_button->setEnabled( false );                                   //disable the download button to prevent a crash
        auto str = "Downloaded " +
                ui->pro_list->currentIndex( ).data( ).toString( ) +
                " to " + ui->roaster_box->currentText( );                           //build the status string
        ui->status_label->setText( str );                                           //set the status text
        ui->progress_bar->setValue( 25 );
        ui->progress_bar->setValue( 50 );
        ui->progress_bar->setValue( 75 );
        ui->progress_bar->setValue( 100 );
        /*int val = 0;                                                                //start the download percent at 0
        while( val <= 100 ) {                                                       //from 0 to 100
            val += 2;                                                               //increment by 2
            QThread::msleep( 50 );                                                  //every 50 ms
            ui->progress_bar->setValue( val );                                      //update progress bar
        }
        ui-> status_label->setText( " ..." );                                         //reset the status text to neutral*/
        ui->download_button->setEnabled( true );                                    //enable the download button again
        ui->progress_bar->setValue( 0 );                                            //reset progress bar
    }
    else {                                                                          //if a roaster has not been chosen
        QMessageBox msg;
        msg.setWindowTitle( "Action Not Permitted" );
        msg.setText( "You must choose a roaster before downloading" );
        msg.addButton( QMessageBox::StandardButton::Ok );
        msg.exec( );
    }
}



//button click handler for the edit button:
//TODO: allow edit action
void MainWindow::on_edit_button_clicked( )
{
    ui-> status_label->setText( " ..." );
    ui-> status_label->setText( " Action not available" );
}



//button click handler for the remove button:
//TODO: allow removal
void MainWindow::on_remove_button_clicked( )
{
    ui-> status_label->setText( " ..." );
    ui-> status_label->setText( " Action not available" );
}



//help action slot: displays help text for the user
void MainWindow::help( ) {
    QMessageBox help;
    help.setWindowTitle( "User Help" );
    QString str = "This program is used to download, create, edit and share coffee roasting profiles:"
                  "<ul><li>The list on the left labelled \"Current Profiles\" contains the profiles available to download or edit.</li>"
                  "<li>Click on any item in the list to highlight it. Once highlighted, it can be downloaded, edited, or removed.</li>"
                  "<li>Use the \"Choose a roaster\" dropdown menu to select your roaster type. Click the \"Download\" button to download the highlighted profile to the selected roaster.</li>"
                  "<li>The text on the bottom left is the status indicator, which will relay messages to the user. Its default message is \"...\" if nothing is happening.</li>"
                  "<li>Click the \"New Profile\" button to start the creation of a new profile. The right side of the window will show the controls.</li></ul>"
                  "<li>To create a new profile:</li>"
                  "<ol><li>Choose the length from the dropdown menu on the top left (15 or 20 minutes).</li>"
                  "<li>Press \"Select\" (or \"Cancel\" if you change your mind).</li>"
                  "<li>Use the table to create a profile. Each column is a different aspect of the profile, and each row represents a 15 second period.</li>"
                  "<ul><li>To edit a cell's value, highlight it and use the value box to the right of the \"set\" button to enter a value (you may use your keyboard or the arrows next to the box).</li>"
                  "<li>Multiple cells may be highlighted and edited at the same time.</li></ul>"
                  "<li>When the profile is done, give it a name in the \"New profile name\" box and click \"Save\" to save it and add it to the list.</li></ol><br/>";
    help.setText( str );
    help.setStandardButtons( QMessageBox::StandardButton::Ok );
    help.exec( );
}



//quit action slot: exits the program
void MainWindow::quit( ) {
    QApplication::quit( );
}



//contact action slot: gives contact information
void MainWindow::contact( ) {
    QMessageBox msg;
    msg.setWindowTitle( "Contact Us" );
    QString str = "Contact us if you need any assistance with this program, or to report a bug/crash from the program."
                  "\nIf calling to report a bug/crash, please try to replicate it and record the steps taken to cause it."
                  "\n\nE-mail: matheus@usroastercorp.com\nPhone: 1-405-232-1534";
    msg.setText( str );
    msg.setStandardButtons( QMessageBox::StandardButton::Ok );
    msg.exec( );
}

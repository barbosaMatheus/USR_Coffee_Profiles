#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi(this);
    this->showMaximized( );
    this->setWindowTitle( "US Roaster Studio" );
    EDITING = false;
    SAVED = true;
    current_index = 0;
    ui->progress_bar->setVisible( false );
    beautify( );                                            //changes style sheets for buttons, list and table
    set_up_menu( );                                         //sets up the menu bar
    hide_right_side( );                                     //hide stuff on the right side that will show up only when needed
    data_model = new QStringListModel( this );              //create an object to the data model
    table_model = new QStandardItemModel( 80, 5, this );    //create an object for the table model
    set_headers( );                                         //set table headers for vertical and horizontal
    ui->pro_table->setModel( table_model );                 //attach model to table
    ui->pro_list->setModel( data_model );                   //connect the list ui object to the model
    ui->pro_list->setEditTriggers( QAbstractItemView::NoEditTriggers );
    ui->download_button->setEnabled( false );
    ui->upload_button->setEnabled( false );
    update_list( );                                         //update local list of profiles
    update_main_ids( );                                     //updates the indexes for everything
}

//style sheet settings for the window background,
//buttons, the list, the table and more
void MainWindow::beautify( ) {
    QColor color( 28, 49, 68 );
    this->showMaximized( );
    this->setWindowTitle( "US Roaster Studio" );
    QIcon icon( "coffee-grain.ico" );
    this->setWindowIcon( icon );
    this->setStyleSheet( "background-color: white" );
    ui->pro_table->setEditTriggers( QAbstractItemView::NoEditTriggers );
    ui->pro_table->setStyleSheet( "QTableView::item::selected { color: white; background-color: #70161e }" );
    QHeaderView *verticalHeader = ui->pro_table->verticalHeader( );
    verticalHeader->setSectionResizeMode( QHeaderView::Fixed );
    verticalHeader->setDefaultSectionSize( 15 );
    QFont font = ui->pro_table->verticalHeader( )->font( );
    font.setPointSize( 6 );
    font.setBold( true );
    ui->pro_table->verticalHeader( )->setFont( font );
    ui->pro_list->setStyleSheet( "QListView { border-image: url(C:/USRoasterStudio/images/3k_image.jpg); }"
                                 "QListView::item { background-color: white; border-bottom: 1px solid black;}"
                                 "QListView::item::selected {background-color: #1c3144;"
                                 "color: white;}" );
    ui->new_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                   "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );
    ui->cancel_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                      "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );
    ui->save_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                    "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );
    /*ui->select_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                      "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );*/
    ui->set_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                   "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );
    ui->download_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                        "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );
    ui->upload_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                        "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );
    ui->edit_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                    "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );
    ui->remove_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                      "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );
    ui->main_save_button->setStyleSheet( "QPushButton {color: white; border: 5px solid #70161e; background-color: #70161e;}"
                                      "QPushButton:hover {border: 1px solid #70161e; background: transparent;color: #70161e;}" );
    menuBar( )->setStyleSheet( "QMenuBar {background-color: #c9cacc;"
                               "color: black;}"
                               "QMenuBar::item:selected {color: white;"
                               "background-color: #1c3144;}"
                               "QMenu {background-color: #c9cacc;"
                               "color: black;}"
                               "QMenu::item {background-color: #c9cacc;}"
                               "QMenu::item::selected {background-color: #1c3144;"
                               "color: white;}" );
    menuBar( )->setFont( QFont( "Bookman Old Style", 12 ) );
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
    ui->roaster_box->addItem( "Choose a COM Port" );
    list1->setStyleSheet( "QListView {background-color: #c9cacc;}"
                          "QListView::item {"
                          "border-bottom: 1px solid black}"
                          "QListView::item::selected {background-color: #1c3144;"
                          "color: white;}" );
    
    ui->roaster_box->setView( list1 );
    QPalette p1 = ui->roaster_box->palette( );
    p1.setColor( QPalette::Highlight, color );
    ui->roaster_box->setPalette( p1 );

    QListView *list2 = new QListView( ui->roaster_list );
    ui->roaster_list->addItem( "All" );                  //add items to profile time combo box
    ui->roaster_list->addItem( "Roaster 1" );
    ui->roaster_list->addItem( "Roaster 2" );
    ui->roaster_list->addItem( "Roaster 3" );
    list2->setStyleSheet( "QListView {background-color: #c9cacc;}"
                          "QListView::item {"
                          "border-bottom: 1px solid black}"
                          "QListView::item::selected {background-color: #1c3144;"
                          "color: white;}" );
    ui->roaster_list->setView( list2 );
    ui->roaster_list->setPalette( p1 );

    QListView *list3 = new QListView( ui->roaster_selector );
    ui->roaster_selector->addItem( "All" );
    ui->roaster_selector->addItem( "Roaster 1" );
    ui->roaster_selector->addItem( "Roaster 2" );
    ui->roaster_selector->addItem( "Roaster 3" );
    list3->setStyleSheet( "QListView {background-color: #c9cacc;}"
                          "QListView::item {"
                          "border-bottom: 1px solid black}"
                          "QListView::item::selected {background-color: #1c3144;"
                          "color: white;}" );
    ui->roaster_selector->setView( list3 );
    ui->roaster_selector->setPalette( p1 );
}

//sets up the menu bar at the top
void MainWindow::set_up_menu( ) {
    QAction *help = new QAction( "&User Help", this );                              //make all the menu action objects
    help->setFont( QFont( "Bookman Old Style", 12 ) );
    help->setShortcut( QKeySequence( "Ctrl+H" ) );
    QAction *contact = new QAction( "&Contact Us", this );
    contact->setFont( QFont( "Bookman Old Style", 12 ) );
    contact->setShortcut( QKeySequence( "Ctrl+U" ) );
    QAction *quit = new QAction( "&Quit", this );
    quit->setShortcut( QKeySequence( "Ctrl+X" ) );
    quit->setFont( QFont( "Bookman Old Style", 12 ) );
    QAction *save = new QAction( "&Save Profiles", this );
    save->setFont( QFont( "Bookman Old Style", 12 ) );
    save->setShortcut( QKeySequence( "Ctrl+S" ) );
    QAction *cloud_dl = new QAction( "&Download from Cloud", this );
    cloud_dl->setFont( QFont( "Bookman Old Style", 12 ) );
    cloud_dl->setShortcut( QKeySequence( "Ctrl+C" ) );
    QAction *ctrl_room = new QAction( "&Control Room", this );
    ctrl_room->setFont( QFont( "Bookman Old Style", 12 ) );
    ctrl_room->setShortcut( QKeySequence( "Ctrl+R" ) );
    QAction *graphical_creator = new QAction( "&Graphical Profile Creator", this );
    graphical_creator->setFont( QFont( "Bookman Old Style", 12 ) );
    graphical_creator->setShortcut( QKeySequence( "Ctrl+G" ) );
    QAction *enable_com = new QAction( "&Enable COM", this );
    enable_com->setFont( QFont( "Bookman Old Style", 12 ) );
    enable_com->setShortcut( QKeySequence( "Ctrl+E" ) );
    QAction *disable_com = new QAction( "&Disable COM", this );
    disable_com->setFont( QFont( "Bookman Old Style", 12 ) );
    disable_com->setShortcut( QKeySequence( "Ctrl+D" ) );
    QMenu *Help;                                                                    //make all menu objects
    QMenu *File;
    QMenu *Tools;
    File = menuBar( )->addMenu( "&File" );                                          //add menus to menus bar and get the objects
    Tools = menuBar( )->addMenu( "&Tools" );
    Help = menuBar( )->addMenu( "&Help" );
    Help->addAction( help );                                                        //add actions to menu objects
    Help->addAction( contact );
    File->addAction( save );
    File->addAction( quit );
    Tools->addAction( cloud_dl );
    Tools->addAction( ctrl_room );
    Tools->addAction( graphical_creator );
    Tools->addAction( enable_com );
    Tools->addAction( disable_com );
    connect( help, SIGNAL( triggered( ) ), this, SLOT( help( ) ) );                 //connect menu actions to slots
    connect( quit, SIGNAL( triggered( ) ), this, SLOT( quit( ) ) );
    connect( contact, SIGNAL( triggered( ) ), this, SLOT( contact( ) ) );
    connect( save, SIGNAL( triggered( ) ), this, SLOT( save( ) ) );
    connect( cloud_dl, SIGNAL( triggered( ) ), this, SLOT( cloud_dl( ) ) );
    connect( ctrl_room, SIGNAL( triggered( ) ), this, SLOT( ctrl_room( ) ) );
    connect( graphical_creator, SIGNAL( triggered( ) ), this, SLOT( graphical_creator( ) ) );
    connect( enable_com, SIGNAL( triggered( ) ), this, SLOT( enable_com( ) ) );
    connect( disable_com, SIGNAL( triggered( ) ), this, SLOT( disable_com( ) ) );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

//updates the current list of profiles
void MainWindow::update_list( ) {
    QFile profiles( "profiles.json" );                                  //create the file object to read profiles from json encoding
    if( !profiles.open( QIODevice::ReadOnly ) ) return;                 //if the file fails to open we just get out of here
    coffee_profiles.clear( );
    current_profiles.clear( );
    list.clear( );
    QByteArray ba = profiles.readAll( );                                //read file information as a byte array
    QJsonDocument doc( QJsonDocument::fromJson( ba ) );                 //create json doc object from byte array
    QVector<QJsonObject> json_array;                                    //create json object array
    QJsonObject json = doc.object( );                                   //get the json object from the document
    const int num_profiles = json["count"].toInt( );                    //read in the number of profiles saved
    for( int i = 0; i < num_profiles; ++i )                             //loop through the json object of objects
        json_array.append( json[QString::number( i )].toObject( ) );    //extract each json object which contains a profile

    for( int i = 0; i < json_array.size( ); ++i ) {                     //loop through the json objects
        CoffeeRoastingProfile* profile = new CoffeeRoastingProfile( );  //create new profile object
        const QString title = profile->read( json_array.at( i ) );      //read the json into the profile object and get its title
        const QString label = title + ", " + QString::number( profile->get_mins( ) ) + " minutes, " +
                QString::number( profile->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, 0 ) ) +
                " F";
        list << label;                                                  //add the title to the list of profiles
        coffee_profiles.push_back( profile );                           //add the profile to the current list
        current_profiles.push_back( profile );
    }

    profiles.close( );                                                  //close the file since we are done
    data_model->setStringList( list );                                  //update the data model
}

//populate horizontal and vertical label lists for table
void MainWindow::set_headers( ) {
    //sets the horizontal headers which are the profile attributes
    horizontal_labels << "Drum Set Point" << "Drum Heat"
                      << "Catalyst Set Point" << "Catlyst Heat" << "Fan Speed %";
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
    //ui->time_box->setVisible( false );
    ui->minutes_box->setVisible( false );
    //ui->select_button->setVisible( false );
    ui->cancel_button->setVisible( false );
    ui->pro_table->setVisible( false );
    ui->set_button->setVisible( false );
    ui->value_box->setVisible( false );
    ui->save_button->setVisible( false );
    ui->name_edit->setVisible( false );
    ui->roaster_selector->setVisible( false );
    ui-> status_label->setText( " ..." );
}

//button click handler for the new profile button:
//makes the right side visible so the user can
//use the table
void MainWindow::on_new_button_clicked( )
{
    ui-> status_label->setText( " New profile being created" );
    EDITING = false;
    SAVED = false;
    show_right_side( );
    //go back to 'ALL' view if we are in a different directory
    if( ui->roaster_list->currentIndex( ) > 0 ) ui->roaster_list->setCurrentIndex( 0 );
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
    EDITING = false;                                                //in case we were editing
}

/*//button click handler for the select button:
//hides or shows extra rows in the table
//depending on the length of the roast
void MainWindow::on_select_button_clicked( )
{
    if( ui->minutes_box->value( ) <= 15 ) {
        for( int i = 60; i < 80; i++ ) {                //from row 60 to 79
            ui->pro_table->setRowHidden( i, true );     //show row i
        }
    }
    else {
        for( int i = 60; i < 80; i++ ) {                //from row 60 to 79
            ui->pro_table->setRowHidden( i, false );    //hide row i
        }
    }
    else return;
}*/

//click event handler for the table cells:
//takes the data from the table and puts
//it in the spinner box for editing
void MainWindow::on_pro_table_clicked( const QModelIndex &index )
{
    int val = index.data( ).toInt( );       //save the value of the clicked cell
    ui->value_box->setValue( val );         //set the value box value to the saved value
    ui->value_box->setFocus( );
}

//updates the main ids, or vector index
//for each of the currently saved profiles
void MainWindow::update_main_ids( void ) {
    for( int i = 0; i < coffee_profiles.size( ); ++i )
        coffee_profiles[i]->set_main_id( i );
}

//button click handler for the set button:
//fetches all selected cells and changes
//their value to the current value in
//the value spinner box. Works for 1 or
//any number of cells
void MainWindow::on_set_button_clicked( )
{
    SAVED = false;
    auto selected = this->ui->pro_table->selectionModel( )->selectedIndexes( );                     //gets all selected cells in a QVector
    if( selected.size( ) > 0 ) {                                                                    //if non-empty
        int val = ui->value_box->value( );                                                          //save value box value
        for( int i = 0; i < selected.size( ); i++ ) {
            if( ( ( selected.at( i ).column( ) == 0 ) || ( selected.at( i ).column( ) == 2 ) ) && ( val >= 0 ) && ( val <= 650 ) ) {//if set point value is in-bounds
                table_model->setData( selected.at( i ), val );                                      //set cell i to the saved value
            }
            else if( ( ( selected.at( i ).column( ) == 1 ) || ( selected.at( i ).column( ) >= 2 ) ) && ( val >= 0 ) && ( val <= 100 ) ){       //if percentage value is in bounds
                table_model->setData( selected.at( i ), val );                                      //set cell i to the saved value
            }
            else {                                                                                  //if values are out of bounds
                QMessageBox warning;
                warning.setWindowTitle( "Value Out of Bounds" );
                QString str = "You entered a value that is not allowed, the property will be unchanged."
                              "\nUse values between 0-650 for set points, and 0-100 for percentages.";
                warning.setText( str );
                warning.setStandardButtons( QMessageBox::StandardButton::Ok );
                warning.exec( );                                                                    //send warning to the user
                ui->value_box->clear( );
            }
        }
    }
}

//checks if a string is empty or whitespace
bool MainWindow::is_invalid( QString str ) {
    if( str.trimmed( ).isEmpty( ) ) return true;
    if( str.length( ) >= 50 ) return false;
    return false;
}

//button click handler for the save button:
//checks to see if we have a valid profile name
//and if so adds the new name to the list
void MainWindow::on_save_button_clicked( ) {
    if( EDITING ) {
        update_profile_object( current_index, EDITING );
        QString str = ui->name_edit->text( );
        if( !is_invalid( str ) ) {                                      //if the user changes the profile name
            current_profiles[current_index]->set_title( str );
            const QString label = str + ", " + QString::number( current_profiles[current_index]->get_mins( ) ) + " minutes, " +
                    QString::number( current_profiles[current_index]->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, 0 ) ) +
                    " F";
            list[current_index] = label;
            data_model->setStringList( list );                          //reset the models string list so it updates
        }
        QString status = str + " updated";                              //inform the user that the profile was updated
        ui->status_label->setText( status );
        EDITING = false;
        hide_right_side( );
        return;
    }
    const QString str = ui->name_edit->text( );
    if( is_invalid( str ) ) {                                          //if the user tries to create a nameless profile
        QMessageBox msg;
        msg.setWindowTitle( "Action Not Permitted" );
        msg.setText( "Cannot add empty name" );
        msg.addButton( QMessageBox::StandardButton::Ok );
        msg.exec( );                                                //send the warning message
        return;                                                     //return so we do nothing else in this function
    }
    CoffeeRoastingProfile* p = new CoffeeRoastingProfile( str, ui->minutes_box->value( ), ui->roaster_selector->currentIndex( )+1, coffee_profiles.size( ) );
    p->set_mins( ui->minutes_box->value( ) );
    coffee_profiles.push_back( p );
    current_profiles.push_back( p );
    update_profile_object( current_profiles.size( )-1, false );
    const QString label = str + ", " + QString::number( p->get_mins( ) ) + " minutes, " +
            QString::number( p->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, 0 ) ) +
            " F";
    list << label;                                                  //append new name to the list
    data_model->setStringList( list );                              //reset the models string list so it updates
    QString status = str + " profile added";                        //inform the user that a new profile was added
    ui->status_label->setText( status );
    hide_right_side( );
}

//button click handler for the download button:
//checks to see if a roaster was selected. If
//yes, downloads the current profile to the roaster.
//If not, it sends a warning message to the user
void MainWindow::on_download_button_clicked( )
{
    if( ( ui->roaster_box->currentIndex( ) > 0 ) && ( list.size( ) > 0 ) && ( current_index >= 0 ) ) {        //if a roaster has been chosen
        ui->progress_bar->setVisible( true );
        ui->progress_bar->setRange( 0, 0 );
        ui->download_button->setEnabled( false );                                   //disable the download button to prevent a crash
        auto str = "Downloading " +
                ui->pro_list->currentIndex( ).data( ).toString( ) +
                " to " + ui->roaster_box->currentText( );                           //build the status string
        ui->status_label->setText( str );                                           //set the status text
        send_to_roaster( *( current_profiles[current_index] ) );
        ui->download_button->setEnabled( true );                                    //enable the download button again
        ui->status_label->setText( "..." );
        ui->progress_bar->setVisible( false );
    }
    else {                                                                          //if a roaster has not been chosen
        QMessageBox msg;
        msg.setWindowTitle( "Action Not Permitted" );
        msg.setText( "You must choose a port from the drop down menu and a profile from the list before downloading" );
        msg.addButton( QMessageBox::StandardButton::Ok );
        msg.exec( );
    }
}

//button click handler for the edit button:
void MainWindow::on_edit_button_clicked( )
{
    EDITING = true;                                            //set editing to true so the save button works accordingly
    SAVED = false;
    show_right_side( );
    ui->name_edit->setText( current_profiles.at( current_index )->get_title( ) );
    ui->choose_label->setVisible( false );                     //hide a couple things
    ui->minutes_box->setVisible( false );
    ui->roaster_selector->setCurrentIndex( current_profiles.at( current_index )->get_list_id( ) );
    fill_table( );                                             //fill table with current data
    QString str = " Editing " + current_profiles.at( current_index )->get_title( );
    ui->status_label->setText( str );
}

//button click handler for the remove button:
void MainWindow::on_remove_button_clicked( )
{
    if( ui->save_button->isVisible( ) ) {
        QMessageBox msg;
        msg.setWindowTitle( "Action not Permitted" );
        msg.setText( "Cannot remove while in edit mode, as it can cause loss of data. Click \'Cancel\' to discard changes, or \'Save\' to keep the changes." );
        msg.exec( );
        return;
    }
    if( coffee_profiles.size( ) < 1 ) return;
    SAVED = false;
    const QString str = "Removed " + current_profiles.at( current_index )->get_title( );
    coffee_profiles.remove( current_profiles.at( current_index )->get_main_id( ) );
    current_profiles.remove( current_index );
    update_main_ids( );
    list.removeAt( current_index );
    data_model->setStringList( list );
    current_index = 0;
    ui->status_label->setText( str );
}

//help action slot: displays help text for the user
void MainWindow::help( ) {
    QMessageBox help;
    help.setWindowTitle( "User Help" );
    QString str = "This program is used to download, create, edit and share coffee roasting profiles:"
                  "<ul><li>The list on the left labelled \"Offline Profiles\" contains the profiles available to download or edit.</li>"
                  "<li>Click on any item in the list to highlight it. Once highlighted, it can be downloaded, edited, or removed.</li>"
                  "<li>Double-click to edit an item, once in edit mode, click other list items to switch between them (this will not save progress)</li>"
                  "<li>Use the \"Choose a COM Port\" dropdown menu to select your COM port. Click the \"Download\" button to download the highlighted profile to the selected COM Port.</li>"
                  "<li>The text on the bottom left is the status indicator, which will relay messages to the user. Its default message is \"...\" if nothing is happening.</li>"
                  "<li>Click the \"New Profile\" button to start the creation of a new profile. The right side of the window will show the controls.</li></ul>"
                  "<li>To create a new profile:</li>"
                  "<ol><li>Specify the profile length using the value input (up to 20 minutes).</li>"
                  "<li>Press \"Select\" (or \"Cancel\" if you change your mind).</li>"
                  "<li>Use the table to create a profile. Each column is a different aspect of the profile, and each row represents a 15 second period.</li>"
                  "<ul><li>To edit a cell's value, highlight it and use the value box to the right of the \"Set\" button to enter a value (you can press \"Set\" or use the return key to change values).</li>"
                  "<li>Multiple cells may be highlighted and edited at the same time.</li></ul>"
                  "<li>When the profile is done, give it a name in the \"New profile name\" box and click \"Save\" to save it and add it to the list.</li></ol>"
                  "<li>To save profiles locally (on your disk) go to File->Save Profiles. The status indicator will indicate that the profiles have been saved.</li>"
                  "<li>To see what profiles are available on the cloud, click Tools->Download From Cloud. Once the window shows up, you can browse, highlight, and click \"Download\" to download the highlighted profiles.</li>"
                  "<li>The same profile can be downloaded multiple times from the cloud, this is to allow users to download profiles and have different versions of the same one. The same name can be used but it is recommended to rename duplicates once downloaded.</li>"
                  "<li>There is a tool which is under development and it allows users to control and monitor a live roast from their desktop/laptop. Highlight a profile from the list, then click Tools->Control Room to open the dialog box.</li><br/>";
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

//save action slot: deletes old file and creates
//new file with current profile information
void MainWindow::save( ) {
    SAVED = true;
    QFile::remove( "profiles.json" );                                                   //remove the file so we can clean
    /*if( ( ui->save_button->isVisible( ) ) && ( coffee_profiles.size( ) > 0 ) ) ui->save_button->click( ); //do a local save if in edit/create mode
    else if( ui->save_button->isVisible( ) ) ui->cancel_button->click( );*/
    QFile profiles( "profiles.json" );                                                  //create the file object
    profiles.open( QIODevice::WriteOnly );                                              //open the file again (recreating it)
    QJsonObject json_profiles;                                                          //create json object to hold all the profiles
    json_profiles["count"] = coffee_profiles.size( );                                   //add the count value to the top json object
    for( int i = 0; i < coffee_profiles.size( ); ++i ) {                                //loop through current profiles in RAM
        QJsonObject json;                                                               //make json object
        coffee_profiles[i]->write( json );                                              //write profile to json
        json_profiles[QString::number( i )] = json;                                     //insert a profile json object into the top json object
    }
    QJsonDocument doc( json_profiles );                                                 //create json document obect from the json object
    profiles.write( doc.toJson( ) );                                                    //write json info to file as a string
    profiles.close( );                                                                  //close file
    ui->status_label->setText( "Local profiles updated" );                              //notify user
}

//shows all the widgets on the right side of the window
void MainWindow::show_right_side( ) {
    ui->choose_label->setVisible( true );
    //ui->time_box->setVisible( true );
    ui->minutes_box->setVisible( true );
    //ui->select_button->setVisible( true );
    ui->cancel_button->setVisible( true );
    ui->pro_table->setVisible( true );
    ui->set_button->setVisible( true );
    ui->value_box->setVisible( true );
    ui->value_box->setValue( 0 );
    ui->save_button->setVisible( true );
    ui->name_edit->setVisible( true );
    ui->roaster_selector->setVisible( true );
    ui->name_edit->setText( "" );
}

//fills the qtableview in the window with the selected
//profile's information
void MainWindow::fill_table( ) {
    CoffeeRoastingProfile *profile = current_profiles.at( current_index );
    //const int mins = profile->get_mins( );
    //const int rows = 4*mins;
    int data_size = profile->data_size( );

    for( int i = 0; i < data_size; i++ ) {
        table_model->setData( table_model->index( i, 0 ), profile->get( CoffeeRoastingProfile::DRUM_SET_PT, i ) );
        table_model->setData( table_model->index( i, 1 ), profile->get( CoffeeRoastingProfile::DRUM_HEAT, i ) );
        table_model->setData( table_model->index( i, 2 ), profile->get( CoffeeRoastingProfile::CAT_SET_PT, i ) );
        table_model->setData( table_model->index( i, 3 ), profile->get( CoffeeRoastingProfile::CAT_HEAT, i ) );
        table_model->setData( table_model->index( i, 4 ), profile->get( CoffeeRoastingProfile::FAN_SPEED, i ) );
    }
    for( int i = data_size; i < 80; ++i ) {
        table_model->setData( table_model->index( i, 0 ), 0 );
        table_model->setData( table_model->index( i, 1 ), 0 );
        table_model->setData( table_model->index( i, 2 ), 0 );
        table_model->setData( table_model->index( i, 3 ), 0 );
        table_model->setData( table_model->index( i, 4 ), 0 );
    }
}

//updates the data for the chosen profile
//using the data in the table
void MainWindow::update_profile_object( int index, bool from_edit ) {
    CoffeeRoastingProfile *profile = current_profiles.at( index );
    //const int mins = from_edit ? profile->get_mins( ) : 20;
    //const int rows = 4*mins;
    //if( !from_edit ) profile->set_mins( 100 );
    //profile->clear_all( );
    profile->set_mins( 20 );
    profile->set_list_id( ui->roaster_selector->currentIndex( ) );
    profile->set_main_id( index );
    for( int i = 0; i < 80; ++i ) {    //loop through the rows in the table and update
        if( table_model->data( table_model->index( i, 0 ) ).isNull( )
            || table_model->data( table_model->index( i, 0 ) ) <= 100 ) {
            profile->set_mins( i/4 );
            break;
        }
        //qDebug( ) << "ITERATION " << QString::number( i ) << " OF " << profile->get_title( );
        unsigned int d1 = table_model->data( table_model->index( i, 2 ) ).toInt( );
        if( d1 <= 100 ) d1 = 0;
        unsigned int d2 = table_model->data( table_model->index( i, 0 ) ).toInt( );
        if( d2 <= 100 ) d2 = 0;
        unsigned int d3 = table_model->data( table_model->index( i, 3 ) ).toInt( );
        unsigned int d4 = table_model->data( table_model->index( i, 1 ) ).toInt( );
        unsigned int d5 = table_model->data( table_model->index( i, 4 ) ).toInt( );
        profile->set_data( from_edit ? i : -1, {d1,d2,d3,d4,d5} );
    }
    //if( profile->get_mins( ) == 100 ) profile->set_mins( );
}

//click handler for profiles list:
//if in edit mode, saves and changes the profile being edited
//if not, simply changes the value for current_index
void MainWindow::on_pro_list_clicked( const QModelIndex &index ) {
    if( EDITING ) {
        const int old_index = current_index;
        current_index = index.row( );
        update_profile_object( old_index, EDITING );
        //QString istr = "OLD: " + QString::number( old_index ) + " NEW: " + QString::number( current_index );
        //qDebug( ) << istr;
        QString str = ui->name_edit->text( );
        if( !str.isEmpty( ) ) {                                         //if the user changes the profile name
            current_profiles[old_index]->set_title( str );
            const QString label = str + ", " + QString::number( current_profiles[old_index]->get_mins( ) ) + " minutes, " +
                    QString::number( current_profiles[old_index]->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, 0 ) ) +
                    " F";
            list[old_index] = label;
            data_model->setStringList( list );                          //reset the models string list so it updates
        }
        ui->pro_list->selectionModel( )->setCurrentIndex( data_model->index( current_index, 0 ), QItemSelectionModel::Select );
        ui->edit_button->click( );
    }
    else {
        current_index = index.row( );
    }
}

//handles the close event in order to tell the
//user that they might be exiting without saving
void MainWindow::closeEvent( QCloseEvent *event ) {
    if( SAVED ) {
        event->accept( );
        return;
    }
    event->ignore();
    QString msg = "You may have unsaved changes. Click File->Save Profiles to save data to your computer, or click \'Yes\' to exit.";
    if( QMessageBox::Yes == QMessageBox::question( this, "Close Confirmation", msg, QMessageBox::Yes | QMessageBox::Cancel ) ) {
        event->accept();
    }

}

//download from cloud action slot: calls the python code
//which gets data from the remote aws database and returns
//the json strings to create profile objects
void MainWindow::run_python( ) {
    cloud_d = new CloudDialog( dl_queue, ui->progress_bar, this );
    cloud_d->exec( );

    if( dl_queue.size( ) == 0 ) {
        ui->status_label->setText( "..." );
        ui->progress_bar->setVisible( false );
        return;
    }
    for( int i = 0; i < dl_queue.size( ); ++i ) {
        coffee_profiles.push_back( dl_queue[i] );
        current_profiles.push_back( dl_queue[i] );
        const QString label = dl_queue[i]->get_title( ) + ", " + QString::number( dl_queue[i]->get_mins( ) ) + " minutes, " +
                QString::number( dl_queue[i]->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, 0 ) ) +
                " F";;
        list << label;
    }

    data_model->setStringList( list );
    QString str = QString::number( dl_queue.size( ) ) + " profiles downloaded from cloud";
    ui->status_label->setText( str );
    dl_queue.clear( );
    ui->progress_bar->setVisible( false );
}

//cloud download slot: does a couple graphic
//things to entertain the user while we go
//fetch data from the cloud
void MainWindow::cloud_dl( ) {
    ui->progress_bar->setRange( 0, 100 );
    ui->progress_bar->setVisible( true );
    ui->status_label->setText( "Opening Cloud Download Tool" );
    if( ui->roaster_list->currentIndex( ) > 0 ) ui->roaster_list->setCurrentIndex( 0 );
    run_python( );
}

/*//parses a json string into a json doc
//then takes the object out of it. Also
//uses the CoffeeRoastingProfile functions
//to create a new profile from the json
//object and adds the new names to the list
void MainWindow::parse_json_str( QString json_str ) {
    QJsonDocument doc = QJsonDocument::fromJson( json_str.toUtf8( ) );
    if( !doc.isNull( ) ) {
        QJsonObject json = doc.object( );
        CoffeeRoastingProfile* profile = new CoffeeRoastingProfile( );  //create new profile object
        const QString title = profile->read( json );                    //read the json into the profile object and get its title
        const QString label = title + ", " + QString::number( profile->get_mins( ) ) + " minutes, " +
                QString::number( profile->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, 0 ) ) +
                " F";;
        list << label;                                                  //add the title to the list of profiles
        coffee_profiles.push_back( profile );                           //add the profile to the current list
        data_model->setStringList( list );
    }
    else ui->status_label->setText( "Invalid JSON" );
}*/

//downloads a selected profile to
//a roaster over serial connection
void MainWindow::send_to_roaster( CoffeeRoastingProfile pro ) {
    QSerialPort *serial = new QSerialPort( this );                                      //create the serial port object
    serial->setBaudRate( QSerialPort::Baud9600 );                                     //set the  baudrate
    serial->setPortName( ui->roaster_box->currentText( ) );                             //set the serial port
    if( !serial->open( QIODevice::WriteOnly ) ) {                                       //open the serial port for write only
        //qDebug( ) << serial->errorString(  );
        QMessageBox msg;
        msg.setWindowTitle( "Cannot Connect to Roaster" );
        QString str = "Communication with roaster has been interrupted. Either no roaster is plugged in or it has been turned off/disconnected."
                      " Please connect a roaster and try again.\n\nError: " + serial->errorString( );
        msg.setText( str );
        msg.setStandardButtons( QMessageBox::StandardButton::Ok );
        msg.exec( );
        return;
    }

    const int num_pts = pro.data_size( );
    for( int i = 0; i < 80; ++i ) {
        char c1, c2, c3, c4, c5;
        if( i >= num_pts ) {
            c1 = 0;
            c2 = 0;
            c3 = 0;
            c4 = 0;
            c5 = 0;
        } else {
            c1 = ( pro.get( CoffeeRoastingProfile::Index::CAT_SET_PT, i ) - 150 ) / 2;
            c2 = pro.get( CoffeeRoastingProfile::Index::DRUM_SET_PT, i ) / 2;
            c3 = pro.get( CoffeeRoastingProfile::Index::CAT_HEAT, i );
            c4 = pro.get( CoffeeRoastingProfile::Index::DRUM_HEAT, i );
            c5 = pro.get( CoffeeRoastingProfile::Index::FAN_SPEED, i );
        }
        QByteArray arr;
        arr.append( c1 ).append( c2 ).append( c3 ).append( c4 ).append( c5 );
        if( !( send_serial_bytes( arr, serial ) ) ) {
            QMessageBox msg;
            msg.setWindowTitle( "Cannot Send Data" );
            QString str = "Data stream has been interrupted. Either no roaster is plugged in or it has been turned off/disconnected."
                          " Please connect a roaster and try again.\n\nError: " + serial->errorString( );
            msg.setText( str );
            msg.setStandardButtons( QMessageBox::StandardButton::Ok );
            msg.exec( );
            serial->close( );
            return;
        }
    }

    //ADDED: for sending the profile name
    //serial->write( pro.get_title( ).toLatin1( ) );
    //serial->waitForBytesWritten( 10000 );
    serial->close( );
}

//sends a single byte over serial connection
//if the connection is established before
bool MainWindow::send_serial_bytes( QByteArray outgoing_data, QSerialPort *serial ) {
    if( serial->isOpen( ) ) {
        serial->write( outgoing_data );
        return serial->waitForBytesWritten( 10000 );
    }
    return false;
}

//Handles any keypress event for the whole
//window but really only cares about the enter
//key being pressed while the value box is in
//focus
void MainWindow::keyPressEvent( QKeyEvent *event ) {
    switch( event->key( ) ) {
    case Qt::Key_Return:
    case Qt::Key_Enter:
        if( ui->value_box->hasFocus( ) ) ui->set_button->click( );
        else if( ui->name_edit->hasFocus( ) ) ui->save_button->click( );
        break;
    default:
       return;
    }
}

//control room action slot: opens
//the control room window so the user
//can control a roaster from the laptop
void MainWindow::ctrl_room( ) {
    if( current_profiles.size( ) < 1 ) {
        QMessageBox msg;
        msg.setWindowTitle( "Empty List" );
        QString str = "Control room allows you to monitor a roast that follows a profile. "
                      "Your current profile list is empty. Please download, upload or create "
                      "a profile or change to a non-empty directory to use this feature.";
        msg.setText( str );
        msg.setStandardButtons( QMessageBox::StandardButton::Ok );
        msg.exec( );
        return;
    }
    ui->status_label->setText( "Running Control Room" );
    ctrl_d = new ControlRoomDialog( current_profiles[current_index], this );
    ctrl_d->exec( );
    ui->status_label->setText( "..." );
}

//list double click slot: handles a double
//click on a list item and takes the user
//to edit mode to edit that profile
void MainWindow::on_pro_list_doubleClicked( const QModelIndex &index ) {
    if( EDITING ) {
        on_pro_list_clicked( index );
        return;
    }
    current_index = index.row( );
    on_edit_button_clicked( );
}

//graphical creator slot: starts the graphical
//profile creator dialog box
void MainWindow::graphical_creator( void ) {
    ui->status_label->setText( "Running Graphical Creator" );
    g_creator = new GraphicalCreatorDialog( this );
    g_creator->exec( );
    update_list( );
    ui->status_label->setText( "Graphical Creator currently unavailable" );
}

//scans for available COM ports
//and fills the list with these
//port names to choose from
void MainWindow::enable_com( void ) {
    ui->roaster_box->clear( );
    ui->roaster_box->addItem( "Choose a COM Port" );
    foreach( const QSerialPortInfo &info, QSerialPortInfo::availablePorts( ) )
        ui->roaster_box->addItem( info.portName( ) );
    ui->download_button->setEnabled( true );
    ui->upload_button->setEnabled( true );
}

//disables COM buttons and functions
void MainWindow::disable_com( void ) {
    ui->roaster_box->clear( );
    ui->roaster_box->addItem( "Choose a COM Port" );
    ui->download_button->setEnabled( false );
    ui->upload_button->setEnabled( false );
}

//Takes an upload from the roaster
//on-board memory and saves it on
//this computer's local memory
void MainWindow::on_upload_button_clicked( ) {
    QSerialPort *serial = new QSerialPort( this );                                      //create the serial port object
    serial->setBaudRate( QSerialPort::Baud9600 );                                     //set the  baudrate
    serial->setPortName( ui->roaster_box->currentText( ) );                             //set the serial port
    if( !serial->open( QIODevice::ReadWrite ) ) {                                       //open the serial port for write only
        //qDebug( ) << serial->errorString(  );
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
    CoffeeRoastingProfile *new_profile = new CoffeeRoastingProfile( "New Profile", 20, 0, coffee_profiles.size( ) );
    //QString str = "";
    for( int i = 0; i < 80; ++i ) {
        //QString str = "";
        CoffeeRoastingProfile::ProfileDataPoint data_point;
        for( int j = 0; j < 5; ++j ) {
            char output[] = {i,j};
            char input[] = {0};
            serial->write( output, 2 );
            if( !serial->waitForBytesWritten( 60000 ) ) {
                QMessageBox msg;
                msg.setWindowTitle( "Cannot Send Data to Roaster" );
                QString error_text = "Please stop the process and try again."
                                     "\nError: " + serial->errorString( );
                msg.setText( error_text );
                msg.setStandardButtons( QMessageBox::StandardButton::Ok );
                msg.exec( );
                return;
            }
            if( !serial->waitForReadyRead( 60000 ) ) {
                QMessageBox msg;
                msg.setWindowTitle( "Cannot Read Data from Roaster" );
                QString error_text = "Please stop the process and try again."
                                     "\nError: " + serial->errorString( );
                msg.setText( error_text );
                msg.setStandardButtons( QMessageBox::StandardButton::Ok );
                msg.exec( );
                return;
            }
            serial->read( input, 1 );
            const int value = j < 2 ? ( uint8_t )( input[0] )*2 : ( uint8_t )( input[0] );
            //str = str + " " + QString::number( value );
            switch( j ) {
                case 0: {
                    data_point.drum_sp = value;
                    break;
                }
                case 1: {
                    data_point.cat_sp = value+150;
                    break;
                }
                case 2: {
                    data_point.drum_heat = value;
                    break;
                }
                case 3: {
                    data_point.cat_heat = value;
                    break;
                }
                case 4: {
                    data_point.fan_speed = value;
                    break;
                }
                default: break;
            }
        }
        if( new_profile->get_mins( ) == 20  && data_point.drum_sp <= 100 ) new_profile->set_mins( );
        new_profile->set_data( -1, data_point );
        //qDebug( ) << str;
    }
    serial->close( );
    //if( new_profile->get_mins( ) == 0 ) new_profile->set_mins( );
    coffee_profiles.push_back( new_profile );
    current_profiles.push_back( new_profile );
    const QString label = "New Profile, " + QString::number( new_profile->get_mins( ) ) + " minutes, " +
            QString::number( new_profile->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, 0 ) ) +
            " F";
    list << label;                                                  //append new name to the list
    data_model->setStringList( list );                              //reset the models string list so it updates
    QString status = "New profile added, must be saved";            //inform the user that a new profile was added
    ui->status_label->setText( status );
}

void MainWindow::on_main_save_button_clicked( )
{
    if( ui->save_button->isVisible( ) ) {
        on_save_button_clicked( );
    }
    this->save( );
}

void MainWindow::on_roaster_list_currentIndexChanged( int index ) {
    if( list.isEmpty( ) ) return;
    list.clear( );
    current_profiles.clear( );
    foreach( CoffeeRoastingProfile *profile, coffee_profiles ) {
        if( index == 0 || profile->get_list_id( ) == index || profile->get_list_id( ) == 0 ) {
            const QString label = profile->get_title( ) + ", " + QString::number( profile->get_mins( ) ) + " minutes, " +
                                  QString::number( profile->get( CoffeeRoastingProfile::Index::DRUM_SET_PT, 0 ) ) + " F";
            list << label;
            current_profiles.push_back( profile );
        }
    }
    data_model->setStringList( list );
}

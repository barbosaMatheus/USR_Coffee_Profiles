#include "clouddialog.h"
#include "ui_clouddialog.h"

CloudDialog::CloudDialog( QVector<CoffeeRoastingProfile*> &queue, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::CloudDialog) {
    ui->setupUi(this);
    q = &queue;
    data_model = new QStringListModel( this );
    this->setWindowTitle( "Online Profiles" );
    ui->cloud_list->setSelectionMode( QAbstractItemView::MultiSelection );
    ui->cloud_list->setModel( data_model );ui->cloud_list->setEditTriggers( QAbstractItemView::NoEditTriggers );
    beautify( );
    run_python( );
}

CloudDialog::~CloudDialog()
{
    delete ui;
}

void CloudDialog::beautify( ) {
    this->setWindowFlags( this->windowFlags( ) & ~Qt::WindowContextHelpButtonHint );
    ui->cloud_list->setStyleSheet( "QListView::item { border-bottom: 1px solid black;}"
                                   "QListView::item::selected {background-color: #1c3144;"
                                   "color: white;}" );
    ui->download_button->setStyleSheet( "color: white; background-color: #7a7940" );
    ui->label->setStyleSheet( "color: white; background-color: #1c3144;" );
}

void CloudDialog::run_python( ) {
    QProcess *p = new QProcess( this );                                                         //create a process object pointer
    QString app_path = "C:/USRoasterStudio/remote_fetch.py";                                //save the absolute path to the script
    QString py_path = "C:/Python27/python";                                                     //save the absolute path to Python
    p->start( py_path, QStringList( ) << app_path );                                            //start the process by running the python code
    p->waitForFinished( -1 );                                                                   //wait here for the process to finish
    QString str = p->readAllStandardOutput( );                                                  //get the console output from the python execution
    str.replace( "\\n", "\n" );                                                                 //replace the literal \n in the string with an actual new line
    QStringList json_list = str.split( "',), (u'", QString::SplitBehavior::SkipEmptyParts );    //split the string with ',), (u' weird but it is what it is, that's what the output has in between json strings
    for( int i = 0; i < json_list.size( ); ++i ) {
        if( json_list.size( ) == 1 )
            list << get_name( json_list[i].mid( 4, json_list[i].size( )-6 ) );
        else if( i == 0 )                                                                       //if it's the first, cleanup the first four chars
            list << get_name( json_list[i].mid( 4 ) );
        else if(  i == json_list.size( )-1 )                                                    //if it's the last, cleanup the last four chars
            list << get_name( json_list[i].left( json_list[i].size( )-6 ) );
        else list << get_name( json_list[i] );
    }
    data_model->setStringList( list );
}

QString CloudDialog::get_name( QString str ) {
    QJsonDocument doc = QJsonDocument::fromJson( str.toUtf8( ) );
    if( !doc.isNull( ) ) {
        QJsonObject json = doc.object( );
        profiles.push_back( json );
        const int pts = ( json["mins"].toInt( ) ) * 4;
        const QString data_str = "data_" + QString::number( pts-1 );
        const QJsonObject data_json = json[data_str].toObject( );
        const QString str = json["title"].toString( ) + ", " + QString::number( pts/4 ) +
                " minutes, " + QString::number( data_json["drum_sp"].toInt( ) ) + "F";
        return str;
    }
    return "Invalid JSON";
}

void CloudDialog::on_download_button_clicked( ) {
    QItemSelectionModel *selection = ui->cloud_list->selectionModel( );
    auto indexes = selection->selectedIndexes( );

    for( int i = 0; i < indexes.size( ); ++i ) {
        CoffeeRoastingProfile *pro = new CoffeeRoastingProfile;
        pro->read( profiles[indexes[i].row( )] );
        q->push_back( pro );
    }

    this->close( );
}

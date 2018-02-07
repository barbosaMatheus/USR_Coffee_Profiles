#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QCloseEvent>
#include <QProcess>
#include <QtSerialPort>
#include <QSplashScreen>
#include "coffeeroastingprofile.h"
#include "clouddialog.h"
#include "controlroomdialog.h"
#include "graphicalcreatordialog.h"
#include "directorysettingsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void keyPressEvent( QKeyEvent *event );

public:
    explicit MainWindow( QWidget *parent = 0 );
    void closeEvent( QCloseEvent *event );
    ~MainWindow( );
    void update_list( );
    void hide_right_side( );
    void show_right_side( );
    void set_headers( );
    void beautify( );
    void mock_download( );
    void set_up_menu( );
    void fill_table( );
    void update_profile_object( int index, bool from_edit );
    bool is_invalid( QString str );
    void send_to_roaster( CoffeeRoastingProfile pro );
    bool send_serial_bytes( QByteArray, QSerialPort * );
    void parse_json_str( QString json_str );
    void update_main_ids( void );
    void get_directory_names( void );

private slots:
    void on_new_button_clicked( );
    void on_cancel_button_clicked( );
    void on_pro_table_clicked( const QModelIndex &index );
    void on_set_button_clicked( );
    void on_download_button_clicked( );
    void on_save_button_clicked( );
    void on_edit_button_clicked( );
    void on_remove_button_clicked( );
    void help( );
    void quit( );
    void contact( );
    void save( );
    void on_pro_list_clicked( const QModelIndex &index );
    void run_python( );
    void ctrl_room( );
    void cloud_dl( );
    void on_pro_list_doubleClicked( const QModelIndex &index );
    void graphical_creator( void );
    void enable_com( void );
    void disable_com( void );
    void on_upload_button_clicked( void );
    void on_main_save_button_clicked( );
    void on_roaster_list_currentIndexChanged( int index );
    void edit_directory_names( void );
    
private:
    Ui::MainWindow *ui;
    QStringListModel *data_model;
    QStandardItemModel *table_model;
    QStringList list;
    QStringList horizontal_labels;
    QStringList vertical_labels;
    QVector<CoffeeRoastingProfile*> coffee_profiles;
    QVector<CoffeeRoastingProfile*> current_profiles;
    QVector<CoffeeRoastingProfile*> dl_queue;
    bool EDITING;                                       //true if we are in edit mode
    bool SAVED;                                         //true if latest changes have been saved
    int current_index;                                  //index of the current profile we are editing
};

#endif // MAINWINDOW_H

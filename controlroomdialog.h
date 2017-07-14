#ifndef CONTROLROOMDIALOG_H
#define CONTROLROOMDIALOG_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QSerialPort>
#include <QMessageBox>
#include <QTimer>
#include <QListView>
#include <QFile>
#include "coffeeroastingprofile.h"
#include "roastgraph.h"
using namespace QtCharts;

namespace Ui {
class ControlRoomDialog;
}

class ControlRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ControlRoomDialog( CoffeeRoastingProfile *pro, QWidget *parent = 0 );
    ~ControlRoomDialog( );
    void beautify( );
    void make_graph( );
    void closeEvent( QCloseEvent *event );
    void rescale( );
    //void mouseMoveEvent( QMouseEvent *e );
    void mousePressEvent( QMouseEvent *e );
    QString get_time_str( int sec );
    void load_graphs( );
    void update_memory( );

private slots:
    void on_dsp_dial_valueChanged( int value );
    void on_dh_dial_valueChanged( int value );
    void on_fs_dial_valueChanged( int value );
    void on_start_button_clicked( );
    void on_com_box_currentTextChanged( const QString &arg1 );
    void on_load_button_clicked( );
    void on_save_button_clicked( );
    void on_clear_button_clicked( );
    void on_delete_button_clicked( );
    void update_chart( );

private:
    Ui::ControlRoomDialog *ui;
    CoffeeRoastingProfile *profile;
    QSplineSeries *series;
    QSplineSeries *live;
    QSplineSeries *saved;
    QChart *chart;
    QChartView *chart_view;
    QSerialPort *serial;
    QTimer *timer;
    QVector<RoastGraph*> saved_graphs;
    RoastGraph *current;
    int time_index;
    const int INTERVAL = 1000;
    bool LIVE;
    bool TIMER_STARTED;
    bool SAVED_LOADED;
    bool LEFT_CLICKED;
    QPoint l_pos;
};

#endif // CONTROLROOMDIALOG_H

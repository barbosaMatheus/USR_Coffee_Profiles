#ifndef CONTROLROOMDIALOG_H
#define CONTROLROOMDIALOG_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QSerialPort>
#include <QMessageBox>
#include <QTimer>
#include <QListView>
#include <QDebug>
#include "coffeeroastingprofile.h"
using namespace QtCharts;

namespace Ui {
class ControlRoomDialog;
}

class ControlRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ControlRoomDialog( CoffeeRoastingProfile *pro, QWidget *parent = 0 );
    ~ControlRoomDialog();
    void beautify( );
    void make_graph( );
    void closeEvent( QCloseEvent *event );
    void rescale( );
    //void mouseMoveEvent( QMouseEvent *e );
    void mousePressEvent( QMouseEvent *e );
    QString get_time_str( int sec );

private slots:
    void on_dsp_dial_valueChanged( int value );
    void on_dh_dial_valueChanged( int value );
    void on_csp_dial_valueChanged( int value );
    void on_ch_dial_valueChanged( int value );
    void on_fs_dial_valueChanged( int value );
    void on_ds_dial_valueChanged( int value );
    void update_chart( );
    void on_start_button_clicked();
    void on_com_box_currentTextChanged(const QString &arg1);

private:
    Ui::ControlRoomDialog *ui;
    CoffeeRoastingProfile *profile;
    QSplineSeries *series;
    QSplineSeries *live;
    QChart *chart;
    QChartView *chart_view;
    QSerialPort *serial;
    QTimer *timer;
    int time_index;
    const int INTERVAL = 1000;
    bool LIVE;                          //true if we are
    bool TIMER_STARTED;
};

#endif // CONTROLROOMDIALOG_H

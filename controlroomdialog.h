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
    void mousePressEvent( QMouseEvent *e );
    QString get_time_str( int sec );

private slots:
    void on_start_button_clicked( );
    void on_com_box_currentTextChanged( const QString &arg1 );
    void update_chart( );

private:
    Ui::ControlRoomDialog *ui;
    CoffeeRoastingProfile *profile;
    QSplineSeries *selected_profile_graph;
    QSplineSeries *live_bean_graph;
    QSplineSeries *live_air_graph;
    QSplineSeries *saved;
    QChart *chart;
    QChartView *chart_view;
    QSerialPort *serial;
    QTimer *timer;
    int time_index;
    const int INTERVAL = 1000;
    bool LIVE;
    bool TIMER_STARTED;
    bool LEFT_CLICKED;
    QPoint l_pos;
};

#endif // CONTROLROOMDIALOG_H

#ifndef CONTROLROOMDIALOG_H
#define CONTROLROOMDIALOG_H

#include <QDialog>
#include <QtCharts/QLineSeries>
#include <QChartView>
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

private slots:
    void on_dsp_dial_valueChanged(int value);

    void on_dh_dial_valueChanged(int value);

    void on_csp_dial_valueChanged(int value);

    void on_ch_dial_valueChanged(int value);

    void on_fs_dial_valueChanged(int value);

    void on_ds_dial_valueChanged(int value);

private:
    Ui::ControlRoomDialog *ui;
    CoffeeRoastingProfile *profile;
    QLineSeries *series;
    QChart *chart;
    QChartView *chart_view;
};

#endif // CONTROLROOMDIALOG_H

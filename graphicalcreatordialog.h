#ifndef GRAPHICALCREATORDIALOG_H
#define GRAPHICALCREATORDIALOG_H

#include <QDialog>
#include "roastgraph.h"
#include "coffeeroastingprofile.h"
using namespace QtCharts;

namespace Ui {
class GraphicalCreatorDialog;
}

class GraphicalCreatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicalCreatorDialog(QWidget *parent = 0);
    ~GraphicalCreatorDialog();
    void beautify( void );
    void make_graph( bool for_saved );
    void load_graphs( void );
    void update_list( void );
    void read_memory( void );
    void write_memory( void );
    void rescale( void );
    void mousePressEvent( QMouseEvent *e );

private slots:
    void on_saved_button_clicked();
    void on_new_button_clicked();
    void on_load_button_clicked();
    void on_save_button_clicked();
    void on_clear_button_clicked();

private:
    Ui::GraphicalCreatorDialog *ui;
    bool SAVED;     //true if making profile from saved graph
    bool NEW;       //true if making profile from new graph
    QVector<RoastGraph*> saved_graphs;
    QSplineSeries *series;
    QChart *chart;
    QChartView *chart_view;
    QVector<CoffeeRoastingProfile*> profiles;
    QStack<QPoint> pts;
    int id;         //index of currently selected graph
};

#endif // GRAPHICALCREATORDIALOG_H

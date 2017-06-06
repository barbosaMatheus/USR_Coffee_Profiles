#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void populate_list( void );
    void hide_right_side( void );

private slots:
    void on_new_button_clicked();
    void on_cancel_button_clicked();
    void on_select_button_clicked();
    void on_pro_table_clicked(const QModelIndex &index);
    void on_set_button_clicked();
    void set_headers( void );
    void on_create_button_clicked();
    void beautify( void );

private:
    Ui::MainWindow *ui;
    QStringListModel *data_model;
    QStandardItemModel *table_model;
    QStringList list;
    QStringList horizontal_labels;
    QStringList vertical_labels;
};

#endif // MAINWINDOW_H

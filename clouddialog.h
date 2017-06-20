#ifndef CLOUDDIALOG_H
#define CLOUDDIALOG_H

#include <QDialog>
#include <QVector>
#include <QJsonObject>
#include <QJsonDocument>
#include <QStringListModel>
#include <QProcess>
#include "coffeeroastingprofile.h"

namespace Ui {
class CloudDialog;
}

class CloudDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CloudDialog( QVector<CoffeeRoastingProfile*> &queue, QWidget *parent = 0 );
    ~CloudDialog();
    void beautify( );
    void run_python( );
    QString get_name( QString str );

private slots:
    void on_download_button_clicked();

private:
    Ui::CloudDialog *ui;
    QStringList list;
    QStringListModel *data_model;
    QVector<QJsonObject> profiles;
    QVector<CoffeeRoastingProfile*> *q;
};

#endif // CLOUDDIALOG_H

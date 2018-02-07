#ifndef DIRECTORYSETTINGSDIALOG_H
#define DIRECTORYSETTINGSDIALOG_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class DirectorySettingsDialog;
}

class DirectorySettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DirectorySettingsDialog( QComboBox *dir_list, QWidget *parent = 0 );
    ~DirectorySettingsDialog( );
    void beautify( void );
    void fill_names( void );

private slots:
    void on_done_button_clicked();

private:
    Ui::DirectorySettingsDialog *ui;
    QComboBox *dir_list;
};

#endif // DIRECTORYSETTINGSDIALOG_H

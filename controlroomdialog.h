#ifndef CONTROLROOMDIALOG_H
#define CONTROLROOMDIALOG_H

#include <QDialog>

namespace Ui {
class ControlRoomDialog;
}

class ControlRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ControlRoomDialog(QWidget *parent = 0);
    ~ControlRoomDialog();

private:
    Ui::ControlRoomDialog *ui;
};

#endif // CONTROLROOMDIALOG_H

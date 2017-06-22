#include "controlroomdialog.h"
#include "ui_controlroomdialog.h"

ControlRoomDialog::ControlRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlRoomDialog)
{
    ui->setupUi(this);
}

ControlRoomDialog::~ControlRoomDialog()
{
    delete ui;
}

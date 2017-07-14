#include "graphicalcreatordialog.h"
#include "ui_graphicalcreatordialog.h"

GraphicalCreatorDialog::GraphicalCreatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphicalCreatorDialog)
{
    ui->setupUi(this);
}

GraphicalCreatorDialog::~GraphicalCreatorDialog()
{
    delete ui;
}

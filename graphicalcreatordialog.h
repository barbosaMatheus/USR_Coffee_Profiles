#ifndef GRAPHICALCREATORDIALOG_H
#define GRAPHICALCREATORDIALOG_H

#include <QDialog>

namespace Ui {
class GraphicalCreatorDialog;
}

class GraphicalCreatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicalCreatorDialog(QWidget *parent = 0);
    ~GraphicalCreatorDialog();

private:
    Ui::GraphicalCreatorDialog *ui;
};

#endif // GRAPHICALCREATORDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'controlroomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLROOMDIALOG_H
#define UI_CONTROLROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlRoomDialog
{
public:
    QFrame *line;
    QWidget *graph_widget;
    QLabel *x_pos;
    QLabel *y_pos;
    QLabel *drum_sp;
    QLabel *drum_heat;
    QLabel *fan_sp;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *saved_box;
    QPushButton *load_button;
    QPushButton *clear_button;
    QPushButton *save_button;
    QPushButton *delete_button;
    QComboBox *com_box;
    QPushButton *start_button;

    void setupUi(QDialog *ControlRoomDialog)
    {
        if (ControlRoomDialog->objectName().isEmpty())
            ControlRoomDialog->setObjectName(QStringLiteral("ControlRoomDialog"));
        ControlRoomDialog->resize(1021, 512);
        line = new QFrame(ControlRoomDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(9, 430, 1003, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        graph_widget = new QWidget(ControlRoomDialog);
        graph_widget->setObjectName(QStringLiteral("graph_widget"));
        graph_widget->setGeometry(QRect(0, 0, 1021, 401));
        x_pos = new QLabel(ControlRoomDialog);
        x_pos->setObjectName(QStringLiteral("x_pos"));
        x_pos->setGeometry(QRect(10, 410, 101, 21));
        QFont font;
        font.setFamily(QStringLiteral("Bookman Old Style"));
        font.setPointSize(9);
        x_pos->setFont(font);
        x_pos->setFrameShape(QFrame::StyledPanel);
        x_pos->setFrameShadow(QFrame::Raised);
        x_pos->setLineWidth(5);
        x_pos->setWordWrap(true);
        y_pos = new QLabel(ControlRoomDialog);
        y_pos->setObjectName(QStringLiteral("y_pos"));
        y_pos->setGeometry(QRect(130, 410, 101, 21));
        y_pos->setFont(font);
        y_pos->setFrameShape(QFrame::StyledPanel);
        y_pos->setFrameShadow(QFrame::Raised);
        y_pos->setLineWidth(5);
        y_pos->setWordWrap(true);
        drum_sp = new QLabel(ControlRoomDialog);
        drum_sp->setObjectName(QStringLiteral("drum_sp"));
        drum_sp->setGeometry(QRect(250, 410, 161, 21));
        drum_sp->setFont(font);
        drum_sp->setFrameShape(QFrame::StyledPanel);
        drum_sp->setFrameShadow(QFrame::Raised);
        drum_sp->setLineWidth(5);
        drum_sp->setWordWrap(true);
        drum_heat = new QLabel(ControlRoomDialog);
        drum_heat->setObjectName(QStringLiteral("drum_heat"));
        drum_heat->setGeometry(QRect(430, 410, 151, 21));
        drum_heat->setFont(font);
        drum_heat->setFrameShape(QFrame::StyledPanel);
        drum_heat->setFrameShadow(QFrame::Raised);
        drum_heat->setLineWidth(5);
        drum_heat->setWordWrap(true);
        fan_sp = new QLabel(ControlRoomDialog);
        fan_sp->setObjectName(QStringLiteral("fan_sp"));
        fan_sp->setGeometry(QRect(600, 410, 151, 21));
        fan_sp->setFont(font);
        fan_sp->setFrameShape(QFrame::StyledPanel);
        fan_sp->setFrameShadow(QFrame::Raised);
        fan_sp->setLineWidth(5);
        fan_sp->setWordWrap(true);
        layoutWidget = new QWidget(ControlRoomDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 450, 631, 54));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        saved_box = new QComboBox(layoutWidget);
        saved_box->setObjectName(QStringLiteral("saved_box"));
        QFont font1;
        font1.setFamily(QStringLiteral("Bookman Old Style"));
        font1.setPointSize(8);
        saved_box->setFont(font1);

        gridLayout->addWidget(saved_box, 0, 0, 2, 1);

        load_button = new QPushButton(layoutWidget);
        load_button->setObjectName(QStringLiteral("load_button"));
        QFont font2;
        font2.setFamily(QStringLiteral("Bookman Old Style"));
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        load_button->setFont(font2);

        gridLayout->addWidget(load_button, 0, 1, 1, 1);

        clear_button = new QPushButton(layoutWidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        clear_button->setFont(font2);

        gridLayout->addWidget(clear_button, 0, 2, 1, 1);

        save_button = new QPushButton(layoutWidget);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setFont(font2);

        gridLayout->addWidget(save_button, 1, 1, 1, 1);

        delete_button = new QPushButton(layoutWidget);
        delete_button->setObjectName(QStringLiteral("delete_button"));
        delete_button->setFont(font2);

        gridLayout->addWidget(delete_button, 1, 2, 1, 1);

        com_box = new QComboBox(ControlRoomDialog);
        com_box->setObjectName(QStringLiteral("com_box"));
        com_box->setGeometry(QRect(100, 472, 171, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Book Antiqua"));
        font3.setPointSize(12);
        com_box->setFont(font3);
        start_button = new QPushButton(ControlRoomDialog);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(11, 460, 75, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Bookman Old Style"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        start_button->setFont(font4);

        retranslateUi(ControlRoomDialog);

        QMetaObject::connectSlotsByName(ControlRoomDialog);
    } // setupUi

    void retranslateUi(QDialog *ControlRoomDialog)
    {
        ControlRoomDialog->setWindowTitle(QApplication::translate("ControlRoomDialog", "Dialog", Q_NULLPTR));
        x_pos->setText(QString());
        y_pos->setText(QString());
        drum_sp->setText(QString());
        drum_heat->setText(QString());
        fan_sp->setText(QString());
        load_button->setText(QApplication::translate("ControlRoomDialog", "Load", Q_NULLPTR));
        clear_button->setText(QApplication::translate("ControlRoomDialog", "Clear", Q_NULLPTR));
        save_button->setText(QApplication::translate("ControlRoomDialog", "Save", Q_NULLPTR));
        delete_button->setText(QApplication::translate("ControlRoomDialog", "Delete", Q_NULLPTR));
        start_button->setText(QApplication::translate("ControlRoomDialog", "Start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ControlRoomDialog: public Ui_ControlRoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLROOMDIALOG_H

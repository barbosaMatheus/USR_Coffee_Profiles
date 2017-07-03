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
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlRoomDialog
{
public:
    QFrame *line;
    QWidget *graph_widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *stir_button;
    QPushButton *door_button;
    QPushButton *cooler_button;
    QPushButton *ex_button;
    QPushButton *dmp3_button;
    QPushButton *dmp4_button;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *start_button;
    QComboBox *com_box;
    QLabel *info_label;
    QLabel *dsp_label;
    QLabel *dh_label;
    QLabel *fs_label;
    QDial *dh_dial;
    QDial *dsp_dial;
    QDial *fs_dial;
    QLabel *x_pos;
    QLabel *y_pos;
    QLabel *drum_sp;
    QLabel *drum_heat;
    QLabel *fan_sp;

    void setupUi(QDialog *ControlRoomDialog)
    {
        if (ControlRoomDialog->objectName().isEmpty())
            ControlRoomDialog->setObjectName(QStringLiteral("ControlRoomDialog"));
        ControlRoomDialog->resize(1021, 690);
        line = new QFrame(ControlRoomDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(9, 400, 1003, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        graph_widget = new QWidget(ControlRoomDialog);
        graph_widget->setObjectName(QStringLiteral("graph_widget"));
        graph_widget->setGeometry(QRect(0, 0, 1021, 401));
        layoutWidget = new QWidget(ControlRoomDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(817, 490, 191, 188));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stir_button = new QPushButton(layoutWidget);
        stir_button->setObjectName(QStringLiteral("stir_button"));
        QFont font;
        font.setFamily(QStringLiteral("Bookman Old Style"));
        font.setPointSize(10);
        stir_button->setFont(font);

        verticalLayout->addWidget(stir_button);

        door_button = new QPushButton(layoutWidget);
        door_button->setObjectName(QStringLiteral("door_button"));
        door_button->setFont(font);

        verticalLayout->addWidget(door_button);

        cooler_button = new QPushButton(layoutWidget);
        cooler_button->setObjectName(QStringLiteral("cooler_button"));
        cooler_button->setFont(font);

        verticalLayout->addWidget(cooler_button);

        ex_button = new QPushButton(layoutWidget);
        ex_button->setObjectName(QStringLiteral("ex_button"));
        ex_button->setFont(font);

        verticalLayout->addWidget(ex_button);

        dmp3_button = new QPushButton(layoutWidget);
        dmp3_button->setObjectName(QStringLiteral("dmp3_button"));
        dmp3_button->setFont(font);

        verticalLayout->addWidget(dmp3_button);

        dmp4_button = new QPushButton(layoutWidget);
        dmp4_button->setObjectName(QStringLiteral("dmp4_button"));
        dmp4_button->setFont(font);

        verticalLayout->addWidget(dmp4_button);

        layoutWidget1 = new QWidget(ControlRoomDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 650, 441, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        start_button = new QPushButton(layoutWidget1);
        start_button->setObjectName(QStringLiteral("start_button"));
        QFont font1;
        font1.setFamily(QStringLiteral("Book Antiqua"));
        font1.setPointSize(10);
        start_button->setFont(font1);

        horizontalLayout->addWidget(start_button);

        com_box = new QComboBox(layoutWidget1);
        com_box->setObjectName(QStringLiteral("com_box"));
        com_box->setFont(font1);

        horizontalLayout->addWidget(com_box);

        info_label = new QLabel(ControlRoomDialog);
        info_label->setObjectName(QStringLiteral("info_label"));
        info_label->setGeometry(QRect(480, 650, 311, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Bookman Old Style"));
        font2.setPointSize(9);
        info_label->setFont(font2);
        info_label->setFrameShape(QFrame::StyledPanel);
        info_label->setFrameShadow(QFrame::Raised);
        info_label->setLineWidth(5);
        info_label->setWordWrap(true);
        dsp_label = new QLabel(ControlRoomDialog);
        dsp_label->setObjectName(QStringLiteral("dsp_label"));
        dsp_label->setGeometry(QRect(30, 610, 171, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Bookman Old Style"));
        font3.setPointSize(11);
        dsp_label->setFont(font3);
        dh_label = new QLabel(ControlRoomDialog);
        dh_label->setObjectName(QStringLiteral("dh_label"));
        dh_label->setGeometry(QRect(340, 610, 131, 16));
        dh_label->setFont(font3);
        fs_label = new QLabel(ControlRoomDialog);
        fs_label->setObjectName(QStringLiteral("fs_label"));
        fs_label->setGeometry(QRect(660, 610, 131, 16));
        fs_label->setFont(font3);
        dh_dial = new QDial(ControlRoomDialog);
        dh_dial->setObjectName(QStringLiteral("dh_dial"));
        dh_dial->setGeometry(QRect(320, 450, 161, 151));
        dh_dial->setMaximum(99);
        dh_dial->setNotchesVisible(true);
        dsp_dial = new QDial(ControlRoomDialog);
        dsp_dial->setObjectName(QStringLiteral("dsp_dial"));
        dsp_dial->setGeometry(QRect(30, 460, 151, 141));
        dsp_dial->setMinimum(100);
        dsp_dial->setMaximum(600);
        dsp_dial->setNotchesVisible(true);
        fs_dial = new QDial(ControlRoomDialog);
        fs_dial->setObjectName(QStringLiteral("fs_dial"));
        fs_dial->setGeometry(QRect(630, 450, 161, 151));
        fs_dial->setNotchesVisible(true);
        x_pos = new QLabel(ControlRoomDialog);
        x_pos->setObjectName(QStringLiteral("x_pos"));
        x_pos->setGeometry(QRect(10, 420, 101, 21));
        x_pos->setFont(font2);
        x_pos->setFrameShape(QFrame::StyledPanel);
        x_pos->setFrameShadow(QFrame::Raised);
        x_pos->setLineWidth(5);
        x_pos->setWordWrap(true);
        y_pos = new QLabel(ControlRoomDialog);
        y_pos->setObjectName(QStringLiteral("y_pos"));
        y_pos->setGeometry(QRect(130, 420, 101, 21));
        y_pos->setFont(font2);
        y_pos->setFrameShape(QFrame::StyledPanel);
        y_pos->setFrameShadow(QFrame::Raised);
        y_pos->setLineWidth(5);
        y_pos->setWordWrap(true);
        drum_sp = new QLabel(ControlRoomDialog);
        drum_sp->setObjectName(QStringLiteral("drum_sp"));
        drum_sp->setGeometry(QRect(250, 420, 161, 21));
        drum_sp->setFont(font2);
        drum_sp->setFrameShape(QFrame::StyledPanel);
        drum_sp->setFrameShadow(QFrame::Raised);
        drum_sp->setLineWidth(5);
        drum_sp->setWordWrap(true);
        drum_heat = new QLabel(ControlRoomDialog);
        drum_heat->setObjectName(QStringLiteral("drum_heat"));
        drum_heat->setGeometry(QRect(430, 420, 151, 21));
        drum_heat->setFont(font2);
        drum_heat->setFrameShape(QFrame::StyledPanel);
        drum_heat->setFrameShadow(QFrame::Raised);
        drum_heat->setLineWidth(5);
        drum_heat->setWordWrap(true);
        fan_sp = new QLabel(ControlRoomDialog);
        fan_sp->setObjectName(QStringLiteral("fan_sp"));
        fan_sp->setGeometry(QRect(600, 420, 151, 21));
        fan_sp->setFont(font2);
        fan_sp->setFrameShape(QFrame::StyledPanel);
        fan_sp->setFrameShadow(QFrame::Raised);
        fan_sp->setLineWidth(5);
        fan_sp->setWordWrap(true);

        retranslateUi(ControlRoomDialog);

        QMetaObject::connectSlotsByName(ControlRoomDialog);
    } // setupUi

    void retranslateUi(QDialog *ControlRoomDialog)
    {
        ControlRoomDialog->setWindowTitle(QApplication::translate("ControlRoomDialog", "Dialog", Q_NULLPTR));
        stir_button->setText(QApplication::translate("ControlRoomDialog", "Stir", Q_NULLPTR));
        door_button->setText(QApplication::translate("ControlRoomDialog", "Door", Q_NULLPTR));
        cooler_button->setText(QApplication::translate("ControlRoomDialog", "Cooler", Q_NULLPTR));
        ex_button->setText(QApplication::translate("ControlRoomDialog", "Exhaust", Q_NULLPTR));
        dmp3_button->setText(QApplication::translate("ControlRoomDialog", "Damper 3", Q_NULLPTR));
        dmp4_button->setText(QApplication::translate("ControlRoomDialog", "Damper 4", Q_NULLPTR));
        start_button->setText(QApplication::translate("ControlRoomDialog", "Start", Q_NULLPTR));
        info_label->setText(QString());
        dsp_label->setText(QApplication::translate("ControlRoomDialog", "Drum Set Point: 100F", Q_NULLPTR));
        dh_label->setText(QApplication::translate("ControlRoomDialog", "Drum Heat: 0%", Q_NULLPTR));
        fs_label->setText(QApplication::translate("ControlRoomDialog", "Fan Speed: 0%", Q_NULLPTR));
        x_pos->setText(QString());
        y_pos->setText(QString());
        drum_sp->setText(QString());
        drum_heat->setText(QString());
        fan_sp->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ControlRoomDialog: public Ui_ControlRoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLROOMDIALOG_H

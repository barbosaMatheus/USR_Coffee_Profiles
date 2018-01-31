/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *choose_label;
    QSpinBox *minutes_box;
    QComboBox *roaster_list;
    QComboBox *roaster_selector;
    QListView *pro_list;
    QTableView *pro_table;
    QPushButton *new_button;
    QPushButton *download_button;
    QPushButton *upload_button;
    QPushButton *edit_button;
    QPushButton *remove_button;
    QPushButton *main_save_button;
    QComboBox *roaster_box;
    QProgressBar *progress_bar;
    QPushButton *set_button;
    QSpinBox *value_box;
    QPushButton *save_button;
    QLabel *status_label;
    QLineEdit *name_edit;
    QPushButton *cancel_button;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(861, 490);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Bookman Old Style"));
        font.setPointSize(12);
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);
        label->setLineWidth(5);

        gridLayout->addWidget(label, 0, 0, 1, 6);

        choose_label = new QLabel(centralWidget);
        choose_label->setObjectName(QStringLiteral("choose_label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Bookman Old Style"));
        choose_label->setFont(font1);
        choose_label->setFrameShape(QFrame::StyledPanel);
        choose_label->setFrameShadow(QFrame::Raised);
        choose_label->setLineWidth(5);

        gridLayout->addWidget(choose_label, 0, 6, 1, 2);

        minutes_box = new QSpinBox(centralWidget);
        minutes_box->setObjectName(QStringLiteral("minutes_box"));
        minutes_box->setMaximum(20);

        gridLayout->addWidget(minutes_box, 0, 8, 1, 2);

        roaster_list = new QComboBox(centralWidget);
        roaster_list->setObjectName(QStringLiteral("roaster_list"));

        gridLayout->addWidget(roaster_list, 1, 0, 1, 6);

        roaster_selector = new QComboBox(centralWidget);
        roaster_selector->setObjectName(QStringLiteral("roaster_selector"));

        gridLayout->addWidget(roaster_selector, 1, 6, 1, 4);

        pro_list = new QListView(centralWidget);
        pro_list->setObjectName(QStringLiteral("pro_list"));
        QFont font2;
        font2.setFamily(QStringLiteral("Bookman Old Style"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        pro_list->setFont(font2);

        gridLayout->addWidget(pro_list, 2, 0, 1, 6);

        pro_table = new QTableView(centralWidget);
        pro_table->setObjectName(QStringLiteral("pro_table"));
        QFont font3;
        font3.setFamily(QStringLiteral("Bookman Old Style"));
        font3.setPointSize(7);
        pro_table->setFont(font3);

        gridLayout->addWidget(pro_table, 2, 6, 3, 4);

        new_button = new QPushButton(centralWidget);
        new_button->setObjectName(QStringLiteral("new_button"));
        QFont font4;
        font4.setFamily(QStringLiteral("Bookman Old Style"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        new_button->setFont(font4);

        gridLayout->addWidget(new_button, 3, 0, 1, 1);

        download_button = new QPushButton(centralWidget);
        download_button->setObjectName(QStringLiteral("download_button"));
        download_button->setFont(font4);

        gridLayout->addWidget(download_button, 3, 1, 1, 1);

        upload_button = new QPushButton(centralWidget);
        upload_button->setObjectName(QStringLiteral("upload_button"));
        upload_button->setFont(font4);

        gridLayout->addWidget(upload_button, 3, 2, 1, 1);

        edit_button = new QPushButton(centralWidget);
        edit_button->setObjectName(QStringLiteral("edit_button"));
        edit_button->setFont(font4);

        gridLayout->addWidget(edit_button, 3, 3, 1, 1);

        remove_button = new QPushButton(centralWidget);
        remove_button->setObjectName(QStringLiteral("remove_button"));
        remove_button->setFont(font4);

        gridLayout->addWidget(remove_button, 3, 4, 1, 1);

        main_save_button = new QPushButton(centralWidget);
        main_save_button->setObjectName(QStringLiteral("main_save_button"));
        main_save_button->setFont(font4);

        gridLayout->addWidget(main_save_button, 3, 5, 1, 1);

        roaster_box = new QComboBox(centralWidget);
        roaster_box->setObjectName(QStringLiteral("roaster_box"));
        roaster_box->setFont(font1);

        gridLayout->addWidget(roaster_box, 4, 0, 1, 6);

        progress_bar = new QProgressBar(centralWidget);
        progress_bar->setObjectName(QStringLiteral("progress_bar"));
        progress_bar->setValue(0);

        gridLayout->addWidget(progress_bar, 5, 0, 1, 6);

        set_button = new QPushButton(centralWidget);
        set_button->setObjectName(QStringLiteral("set_button"));
        set_button->setFont(font4);

        gridLayout->addWidget(set_button, 5, 6, 1, 1);

        value_box = new QSpinBox(centralWidget);
        value_box->setObjectName(QStringLiteral("value_box"));
        value_box->setFont(font1);
        value_box->setMaximum(1000);

        gridLayout->addWidget(value_box, 5, 7, 1, 2);

        save_button = new QPushButton(centralWidget);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setFont(font4);

        gridLayout->addWidget(save_button, 5, 9, 1, 1);

        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QStringLiteral("status_label"));
        QFont font5;
        font5.setFamily(QStringLiteral("Bookman Old Style"));
        font5.setPointSize(10);
        status_label->setFont(font5);
        status_label->setFrameShape(QFrame::StyledPanel);
        status_label->setFrameShadow(QFrame::Raised);
        status_label->setLineWidth(5);

        gridLayout->addWidget(status_label, 6, 0, 1, 6);

        name_edit = new QLineEdit(centralWidget);
        name_edit->setObjectName(QStringLiteral("name_edit"));
        name_edit->setFont(font1);

        gridLayout->addWidget(name_edit, 6, 6, 1, 3);

        cancel_button = new QPushButton(centralWidget);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setFont(font4);

        gridLayout->addWidget(cancel_button, 6, 9, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 861, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "US Roasters Coffee Profiles", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Offline Profiles</p></body></html>", Q_NULLPTR));
        choose_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Set profile length:</p></body></html>", Q_NULLPTR));
        new_button->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
        download_button->setText(QApplication::translate("MainWindow", "Transmit", Q_NULLPTR));
        upload_button->setText(QApplication::translate("MainWindow", "Receive", Q_NULLPTR));
        edit_button->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        remove_button->setText(QApplication::translate("MainWindow", "Remove", Q_NULLPTR));
        main_save_button->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        set_button->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        save_button->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        status_label->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        name_edit->setPlaceholderText(QApplication::translate("MainWindow", "New profile name", Q_NULLPTR));
        cancel_button->setText(QApplication::translate("MainWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

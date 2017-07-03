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
#include <QtWidgets/QFrame>
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
    QSpinBox *value_box;
    QProgressBar *progress_bar;
    QLabel *choose_label;
    QLineEdit *name_edit;
    QLabel *status_label;
    QPushButton *save_button;
    QPushButton *download_button;
    QComboBox *time_box;
    QFrame *line;
    QPushButton *edit_button;
    QPushButton *select_button;
    QPushButton *cancel_button;
    QPushButton *new_button;
    QLabel *label;
    QListView *pro_list;
    QTableView *pro_table;
    QComboBox *roaster_box;
    QPushButton *set_button;
    QPushButton *remove_button;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(756, 491);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        value_box = new QSpinBox(centralWidget);
        value_box->setObjectName(QStringLiteral("value_box"));
        QFont font;
        font.setFamily(QStringLiteral("Bookman Old Style"));
        value_box->setFont(font);
        value_box->setMaximum(1000);

        gridLayout->addWidget(value_box, 4, 6, 1, 2);

        progress_bar = new QProgressBar(centralWidget);
        progress_bar->setObjectName(QStringLiteral("progress_bar"));
        progress_bar->setValue(0);

        gridLayout->addWidget(progress_bar, 5, 0, 2, 4);

        choose_label = new QLabel(centralWidget);
        choose_label->setObjectName(QStringLiteral("choose_label"));
        choose_label->setFont(font);
        choose_label->setFrameShape(QFrame::StyledPanel);
        choose_label->setFrameShadow(QFrame::Raised);
        choose_label->setLineWidth(5);

        gridLayout->addWidget(choose_label, 0, 5, 1, 2);

        name_edit = new QLineEdit(centralWidget);
        name_edit->setObjectName(QStringLiteral("name_edit"));
        name_edit->setFont(font);

        gridLayout->addWidget(name_edit, 6, 5, 1, 4);

        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QStringLiteral("status_label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Bookman Old Style"));
        font1.setPointSize(10);
        status_label->setFont(font1);
        status_label->setFrameShape(QFrame::StyledPanel);
        status_label->setFrameShadow(QFrame::Raised);
        status_label->setLineWidth(5);

        gridLayout->addWidget(status_label, 7, 0, 1, 4);

        save_button = new QPushButton(centralWidget);
        save_button->setObjectName(QStringLiteral("save_button"));
        QFont font2;
        font2.setFamily(QStringLiteral("Bookman Old Style"));
        font2.setPointSize(12);
        save_button->setFont(font2);

        gridLayout->addWidget(save_button, 7, 8, 1, 1);

        download_button = new QPushButton(centralWidget);
        download_button->setObjectName(QStringLiteral("download_button"));
        download_button->setFont(font2);

        gridLayout->addWidget(download_button, 3, 1, 1, 1);

        time_box = new QComboBox(centralWidget);
        time_box->setObjectName(QStringLiteral("time_box"));
        time_box->setFont(font);

        gridLayout->addWidget(time_box, 0, 7, 1, 2);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 4, 8, 1);

        edit_button = new QPushButton(centralWidget);
        edit_button->setObjectName(QStringLiteral("edit_button"));
        edit_button->setFont(font2);

        gridLayout->addWidget(edit_button, 3, 2, 1, 1);

        select_button = new QPushButton(centralWidget);
        select_button->setObjectName(QStringLiteral("select_button"));
        select_button->setFont(font2);

        gridLayout->addWidget(select_button, 1, 7, 1, 1);

        cancel_button = new QPushButton(centralWidget);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setFont(font2);

        gridLayout->addWidget(cancel_button, 1, 8, 1, 1);

        new_button = new QPushButton(centralWidget);
        new_button->setObjectName(QStringLiteral("new_button"));
        new_button->setFont(font2);

        gridLayout->addWidget(new_button, 3, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);
        label->setLineWidth(5);

        gridLayout->addWidget(label, 1, 0, 1, 4);

        pro_list = new QListView(centralWidget);
        pro_list->setObjectName(QStringLiteral("pro_list"));
        QFont font3;
        font3.setFamily(QStringLiteral("Bookman Old Style"));
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setWeight(50);
        pro_list->setFont(font3);

        gridLayout->addWidget(pro_list, 2, 0, 1, 4);

        pro_table = new QTableView(centralWidget);
        pro_table->setObjectName(QStringLiteral("pro_table"));
        QFont font4;
        font4.setFamily(QStringLiteral("Bookman Old Style"));
        font4.setPointSize(7);
        pro_table->setFont(font4);

        gridLayout->addWidget(pro_table, 2, 5, 1, 4);

        roaster_box = new QComboBox(centralWidget);
        roaster_box->setObjectName(QStringLiteral("roaster_box"));
        roaster_box->setFont(font);

        gridLayout->addWidget(roaster_box, 4, 0, 1, 4);

        set_button = new QPushButton(centralWidget);
        set_button->setObjectName(QStringLiteral("set_button"));
        set_button->setFont(font2);

        gridLayout->addWidget(set_button, 4, 5, 1, 1);

        remove_button = new QPushButton(centralWidget);
        remove_button->setObjectName(QStringLiteral("remove_button"));
        remove_button->setFont(font2);

        gridLayout->addWidget(remove_button, 3, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 756, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "US Roasters Coffee Profiles", Q_NULLPTR));
        choose_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Choose a type of profile:</span></p></body></html>", Q_NULLPTR));
        name_edit->setPlaceholderText(QApplication::translate("MainWindow", "New profile name", Q_NULLPTR));
        status_label->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        save_button->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        download_button->setText(QApplication::translate("MainWindow", "Download", Q_NULLPTR));
        edit_button->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        select_button->setText(QApplication::translate("MainWindow", "Select", Q_NULLPTR));
        cancel_button->setText(QApplication::translate("MainWindow", "Cancel", Q_NULLPTR));
        new_button->setText(QApplication::translate("MainWindow", "New Profile", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Offline Profiles</p></body></html>", Q_NULLPTR));
        set_button->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        remove_button->setText(QApplication::translate("MainWindow", "Remove", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

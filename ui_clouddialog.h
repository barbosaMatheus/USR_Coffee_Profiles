/********************************************************************************
** Form generated from reading UI file 'clouddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOUDDIALOG_H
#define UI_CLOUDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CloudDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListView *cloud_list;
    QLabel *label;
    QPushButton *download_button;

    void setupUi(QDialog *CloudDialog)
    {
        if (CloudDialog->objectName().isEmpty())
            CloudDialog->setObjectName(QStringLiteral("CloudDialog"));
        CloudDialog->resize(291, 370);
        verticalLayout = new QVBoxLayout(CloudDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cloud_list = new QListView(CloudDialog);
        cloud_list->setObjectName(QStringLiteral("cloud_list"));
        QFont font;
        font.setFamily(QStringLiteral("Bookman Old Style"));
        font.setPointSize(11);
        font.setItalic(true);
        cloud_list->setFont(font);

        verticalLayout->addWidget(cloud_list);

        label = new QLabel(CloudDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Book Antiqua"));
        font1.setPointSize(12);
        label->setFont(font1);
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);
        label->setLineWidth(5);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        download_button = new QPushButton(CloudDialog);
        download_button->setObjectName(QStringLiteral("download_button"));
        QFont font2;
        font2.setFamily(QStringLiteral("Bookman Old Style"));
        font2.setPointSize(12);
        download_button->setFont(font2);

        verticalLayout->addWidget(download_button);


        retranslateUi(CloudDialog);

        QMetaObject::connectSlotsByName(CloudDialog);
    } // setupUi

    void retranslateUi(QDialog *CloudDialog)
    {
        CloudDialog->setWindowTitle(QApplication::translate("CloudDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CloudDialog", "<html><head/><body><p><span style=\" font-size:9pt;\">Select the profiles you wish to download and press the button below, or just close the window to cancel.</span></p></body></html>", Q_NULLPTR));
        download_button->setText(QApplication::translate("CloudDialog", "Download", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CloudDialog: public Ui_CloudDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOUDDIALOG_H

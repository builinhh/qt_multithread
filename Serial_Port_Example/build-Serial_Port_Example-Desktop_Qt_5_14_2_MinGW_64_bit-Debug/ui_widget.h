/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox_port;
    QComboBox *comboBox_baud;
    QComboBox *comboBox_dataBit;
    QComboBox *comboBox_stopBit;
    QComboBox *comboBox_parity;
    QLineEdit *lineEdit_send;
    QPushButton *pushButton_send;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QPushButton *pushButton_refreshPort;
    QPushButton *pushButton_clear;
    QTextBrowser *text_header;
    QTextBrowser *text_receive;
    QLabel *label_8;
    QLabel *label_9;
    QTextBrowser *text_length;
    QTextBrowser *text_data;
    QTextBrowser *text_crc;
    QTextBrowser *text_header_hex;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QTextBrowser *text_data_hex;
    QTextBrowser *text_length_hex;
    QTextBrowser *text_crc_hex;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(666, 459);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 49, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 70, 61, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 100, 61, 16));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 130, 49, 16));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 160, 49, 16));
        comboBox_port = new QComboBox(Widget);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));
        comboBox_port->setGeometry(QRect(130, 40, 69, 22));
        comboBox_baud = new QComboBox(Widget);
        comboBox_baud->setObjectName(QString::fromUtf8("comboBox_baud"));
        comboBox_baud->setGeometry(QRect(130, 70, 69, 22));
        comboBox_dataBit = new QComboBox(Widget);
        comboBox_dataBit->setObjectName(QString::fromUtf8("comboBox_dataBit"));
        comboBox_dataBit->setGeometry(QRect(130, 100, 69, 22));
        comboBox_stopBit = new QComboBox(Widget);
        comboBox_stopBit->setObjectName(QString::fromUtf8("comboBox_stopBit"));
        comboBox_stopBit->setGeometry(QRect(130, 130, 69, 22));
        comboBox_parity = new QComboBox(Widget);
        comboBox_parity->setObjectName(QString::fromUtf8("comboBox_parity"));
        comboBox_parity->setGeometry(QRect(130, 160, 69, 22));
        lineEdit_send = new QLineEdit(Widget);
        lineEdit_send->setObjectName(QString::fromUtf8("lineEdit_send"));
        lineEdit_send->setGeometry(QRect(390, 40, 261, 22));
        pushButton_send = new QPushButton(Widget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(290, 40, 75, 24));
        pushButton_connect = new QPushButton(Widget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(50, 260, 75, 24));
        pushButton_disconnect = new QPushButton(Widget);
        pushButton_disconnect->setObjectName(QString::fromUtf8("pushButton_disconnect"));
        pushButton_disconnect->setGeometry(QRect(150, 260, 75, 24));
        pushButton_refreshPort = new QPushButton(Widget);
        pushButton_refreshPort->setObjectName(QString::fromUtf8("pushButton_refreshPort"));
        pushButton_refreshPort->setGeometry(QRect(90, 290, 81, 24));
        pushButton_clear = new QPushButton(Widget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(550, 10, 75, 24));
        text_header = new QTextBrowser(Widget);
        text_header->setObjectName(QString::fromUtf8("text_header"));
        text_header->setGeometry(QRect(390, 170, 91, 31));
        text_receive = new QTextBrowser(Widget);
        text_receive->setObjectName(QString::fromUtf8("text_receive"));
        text_receive->setGeometry(QRect(390, 80, 261, 61));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(310, 80, 51, 21));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 170, 51, 21));
        text_length = new QTextBrowser(Widget);
        text_length->setObjectName(QString::fromUtf8("text_length"));
        text_length->setGeometry(QRect(390, 220, 91, 31));
        text_data = new QTextBrowser(Widget);
        text_data->setObjectName(QString::fromUtf8("text_data"));
        text_data->setGeometry(QRect(390, 270, 91, 31));
        text_crc = new QTextBrowser(Widget);
        text_crc->setObjectName(QString::fromUtf8("text_crc"));
        text_crc->setGeometry(QRect(390, 320, 91, 31));
        text_header_hex = new QTextBrowser(Widget);
        text_header_hex->setObjectName(QString::fromUtf8("text_header_hex"));
        text_header_hex->setGeometry(QRect(540, 170, 91, 31));
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(310, 220, 51, 21));
        label_11 = new QLabel(Widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(310, 270, 51, 21));
        label_12 = new QLabel(Widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(310, 320, 51, 21));
        text_data_hex = new QTextBrowser(Widget);
        text_data_hex->setObjectName(QString::fromUtf8("text_data_hex"));
        text_data_hex->setGeometry(QRect(540, 270, 91, 31));
        text_length_hex = new QTextBrowser(Widget);
        text_length_hex->setObjectName(QString::fromUtf8("text_length_hex"));
        text_length_hex->setGeometry(QRect(540, 220, 91, 31));
        text_crc_hex = new QTextBrowser(Widget);
        text_crc_hex->setObjectName(QString::fromUtf8("text_crc_hex"));
        text_crc_hex->setGeometry(QRect(540, 320, 91, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Port", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Baud Rate", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Data Bits", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Stop Bits", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Parity", nullptr));
        pushButton_send->setText(QCoreApplication::translate("Widget", "Send", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
        pushButton_disconnect->setText(QCoreApplication::translate("Widget", "Disconnect", nullptr));
        pushButton_refreshPort->setText(QCoreApplication::translate("Widget", "Refresh Ports", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Widget", "Clear", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "Receive", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "Header", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "Length", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "Data", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "CRC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

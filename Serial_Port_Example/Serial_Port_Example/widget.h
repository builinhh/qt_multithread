#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QByteArray>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    uint16_t CalculateCRC(QByteArray data_stm, uint16_t length_stm);
    ~Widget();

private slots:
    void on_pushButton_connect_clicked();
    void receiveMessage();
    void on_pushButton_disconnect_clicked();
    void on_pushButton_refreshPort_clicked();
    void on_pushButton_clear_clicked();

private:
    Ui::Widget *ui;
    QSerialPort serialPort;
    QSerialPortInfo info;
//    QByteArray buffer;
    QString code;
    QByteArray buffer_temp;
    int codeSize;
};
#endif // WIDGET_H

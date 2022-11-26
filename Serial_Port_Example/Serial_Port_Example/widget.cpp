#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QVariant>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(width(), height());

    // Tittle of widget
    QWidget::setWindowTitle("Serial Port Data");

    // Ports
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox_port->addItems(stringPorts);

    // Baud Rate Ratios
    ui->comboBox_baud->addItem("4800");
    ui->comboBox_baud->addItem("9600");
    ui->comboBox_baud->addItem("115200");

    // Data Bits
    ui->comboBox_dataBit->addItem("8");

    // Stop Bits
    ui->comboBox_stopBit->addItem("1 Bit");

    // Parities
    ui->comboBox_parity->addItem("No Parity");
    ui->comboBox_parity->addItem("Even Parity");
    ui->comboBox_parity->addItem("Odd Parity");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_connect_clicked()
{

    QString portName = ui->comboBox_port->currentText();
    serialPort.setPortName(portName);
    serialPort.open(QIODevice::ReadWrite);

    if(!serialPort.isOpen()){
        ui->text_receive->setTextColor(Qt::red);
        ui->text_receive->append("!!!! Something went Wrong !!!!");
    }
    else {

        QString stringbaudRate = ui->comboBox_baud->currentText();
        int intbaudRate = stringbaudRate.toInt();
        serialPort.setBaudRate(intbaudRate);

        serialPort.setDataBits(QSerialPort::Data8);
        serialPort.setStopBits(QSerialPort::OneStop);

        QString parity = ui->comboBox_parity->currentText();
        if(parity == "No Parity"){
            serialPort.setParity(QSerialPort::NoParity);
        }
        else if(parity == "Even Parity"){
            serialPort.setParity(QSerialPort::EvenParity);
        }
        else if(parity == "Odd Parity"){
            serialPort.setParity(QSerialPort::OddParity);
        }

        connect(&serialPort,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
    }


}

uint16_t Widget::CalculateCRC(QByteArray data_stm, uint16_t length_stm)
{
    unsigned int temp, temp2, flag;
    temp = 0xFFFF;
    for(int i = 0; i < length_stm; i++)
    {
        temp = temp ^ data_stm[i];
        for(int j = 0; j < length_stm; j++)
        {
            flag = temp & 0x0001;
            temp >>= 1;
            if(flag)
                temp ^= 0xA001;
        }
    }
    // reverse byte order.
    temp2 = temp >> 8;
    temp = (temp << 8) | temp2;
    temp &= 0xFFFF;
    return temp;
}

void Widget::receiveMessage()
{
    QByteArray dataBA = serialPort.readAll();
    QByteArray buffer;
    buffer.append(dataBA);
    uint16_t m_header;
    uint8_t m_length{0};
    uint8_t crc_cal[2];
    uint8_t crc_receive[2];
    static int count_message = 0;

    while(buffer.size() > 17)
    {
        int byteProcessed{0};
        //Xu ly TH mat ban tin
        if(static_cast<uint8_t>(buffer.at(byteProcessed++)) != 0x42)
        {
            buffer.remove(0, byteProcessed);
            ui->text_receive->clear();
            ui->text_header->clear();
            ui->text_length->clear();
            ui->text_data->clear();
            ui->text_crc->clear();
            continue;
        }

        if(static_cast<uint8_t>(buffer.at(byteProcessed++)) != 0x4C)
        {
            buffer.remove(0, byteProcessed);
            ui->text_receive->clear();
            ui->text_header->clear();
            ui->text_length->clear();
            ui->text_data->clear();
            ui->text_crc->clear();
            continue;
        }
        // header and length of data
        m_header = 0x424C;
        m_length = buffer.at(2);

        if(m_length > buffer.size())
        {
            break;
        }

        // receive and calculate crc
        crc_receive[0] =  buffer.at(16);
        crc_receive[1] =  buffer.at(15);

        uint16_t tmp = CalculateCRC(buffer, 15);
        crc_cal[0] = tmp;
        crc_cal[1] = tmp >>8;

        uint8_t m_data[m_length];
        QByteArray ba;
        if(crc_receive[0] == crc_cal[0] && crc_receive[1] == crc_cal[1])
        {
            memcpy(m_data, buffer.data() + 3, m_length);
            QString message = buffer.mid(3, m_length);
            qDebug() << ++count_message;
            ui->text_receive->setTextColor("green");
            ui->text_receive->setText(buffer.mid(0, 17));
//            ui->text_receive->append(buffer.mid(0, 17));
            ui->text_header->setTextColor("green");
            ui->text_header->setText(QString::number(m_header));
            ui->text_length->setTextColor("green");
            ui->text_length->setText(QString::number(m_length));
            ui->text_data->setTextColor("green");
            ui->text_data->setText(message);
            ui->text_crc->setTextColor("green");
            ui->text_crc->setText(QString::number(tmp));
            if(buffer.size() > 51)
            {
                buffer.remove(0, 17);
            }
            else
            {
                break;
            }
        }
        else
        {
            byteProcessed += 1 + m_length + 2; // 1byte Length + 2ByteCRC
            if(buffer.size() > byteProcessed)
            {
                buffer.remove(0, byteProcessed);
            }
        }
    }
}




// Button of Disconnect
void Widget::on_pushButton_disconnect_clicked()
{
    serialPort.close();
}

// Button of Refresh Ports
void Widget::on_pushButton_refreshPort_clicked()
{
    ui->comboBox_port->clear();
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox_port->addItems(stringPorts);
}

// Button of Clear
void Widget::on_pushButton_clear_clicked()
{
    ui->text_receive->clear();
    ui->text_header->clear();
    ui->text_length->clear();
    ui->text_data->clear();
    ui->text_crc->clear();
    QString portName = ui->comboBox_port->currentText();
    serialPort.setPortName(portName);
    serialPort.open(QIODevice::ReadWrite);

    if(!serialPort.isOpen()){
        ui->text_receive->setTextColor(Qt::red);
        ui->text_receive->append("!!!! Something went Wrong !!!!");
    }
    else {

        QString stringbaudRate = ui->comboBox_baud->currentText();
        int intbaudRate = stringbaudRate.toInt();
        serialPort.setBaudRate(intbaudRate);

        serialPort.setDataBits(QSerialPort::Data8);
        serialPort.setStopBits(QSerialPort::OneStop);

        QString parity = ui->comboBox_parity->currentText();
        if(parity == "No Parity"){
            serialPort.setParity(QSerialPort::NoParity);
        }
        else if(parity == "Even Parity"){
            serialPort.setParity(QSerialPort::EvenParity);
        }
        else if(parity == "Odd Parity"){
            serialPort.setParity(QSerialPort::OddParity);
        }

        connect(&serialPort,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
    }
}


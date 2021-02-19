#include "main_window.h"
#include "ui_main_window.h"

QSerialPort* port = new QSerialPort();


Main_window::Main_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_window)
{
    ui->setupUi(this);
    for(auto& info: QSerialPortInfo::availablePorts()){
        ui->comboBox->addItem(info.portName());
    }

}

Main_window::~Main_window()
{
    delete ui;
    delete port;
}

void Main_window::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
    QByteArray arr;
    arr.setNum(value);
    arr.append("\n\r");
    if(port->isOpen()){
        port->write(arr);
    }
}

void Main_window::on_pushButton_clicked()
{
    if(port != nullptr) {
        port->setPortName(ui->comboBox->currentText());
        port->setBaudRate(9600);
        port->setParity(QSerialPort::NoParity);
        port->setStopBits(QSerialPort::OneStop);
        port->setDataBits(QSerialPort::Data8);
        port->open(QIODevice::ReadWrite);
        on_dial_valueChanged(ui->dial->value());
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->comboBox->setEnabled(false);
    }
}

void Main_window::on_pushButton_2_clicked()
{
    if(port->isOpen()){
        port->close();

        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->comboBox->setEnabled(true);
    }
}

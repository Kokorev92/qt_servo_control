#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "QtSerialPort"

QT_BEGIN_NAMESPACE
namespace Ui { class Main_window; }
QT_END_NAMESPACE

class Main_window : public QMainWindow
{
    Q_OBJECT

public:
    Main_window(QWidget *parent = nullptr);
    ~Main_window();

private slots:
    void on_dial_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Main_window *ui;
};
#endif // MAIN_WINDOW_H

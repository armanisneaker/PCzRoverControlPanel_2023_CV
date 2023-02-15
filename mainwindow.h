#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <string.h>
#include <vector>
#include <QTextCursor>
#include <QTableWidgetItem>
#include <QLabel>
#include <QLayout>
#include <QMatrix2x2>
#include <QBitArray>
#include <QTimer>
#include <QUdpSocket>
#include <QMessageBox>
#include "Arm.h"

#include "mapmodule.h"
#include "structures.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Movement
{
    int Value[4]{};    //power, x, y, z
    int Combobox[6]{};  //No to akurat jest fajna zabawa xd gdzieś dam listę tego gówna co siedzi w środku xdxd
};

struct UiElements
{
    int framesSentLabelValue{0};
    QMessageBox Msgbox;
    QString adress = "192.168.1.10";
    int port = 5150;
};

struct VirtualJoystick
{
    QPoint point;
    int start_pos_X;
    int start_pos_Y;
    int mouse_pos_X;
    int mouse_pos_Y;
    bool ispressed = false;

    int diff_X = 0;
    int diff_Y = 0;
};

struct MouseEvent
{
    int pos_x;
    int pos_y;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        void sendFrame(int, int);

        Movement movement;
        VirtualJoystick virtualJoystick;
        UiElements uiElements;
        Arm::buttonFunction buttonFunction = Arm::buttonFunction::none;

        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        //reimplementacja funkcji
        bool eventFilter(QObject * object, QEvent * event);

        //-----------------------------------------------------------------MAPA---------------------------------------------------------
        Navigation navigation;
        MapModule * mapmodule;

        //funkcje dające wartosci do struktury "navigate"
                void on_pushButton_add_pos_clicked();
                void on_tableWidget_nav_cellClicked(int row, int column);
                void on_pushButtonDeletePoint_clicked();

        //-----------------------------------------------------------------MAPA---------------------------------------------------------
    private slots:
        //funkcje dające wartosci do struktury "navigate"

        //joystick na ekranie
        void joystickMove(QMouseEvent *event);
        void joystickRelease(QMouseEvent *event);

        void on_horizontalSlider_power_drive_valueChanged(int value);

        void on_horizontalSlider_x_drive_valueChanged(int value);

        void on_horizontalSlider_y_drive_valueChanged(int value);

        void on_horizontalSlider_x_drive_sliderReleased();

        void on_horizontalSlider_y_drive_sliderReleased();

        void on_comboBox_1_currentTextChanged(const QString &arg1);

        void on_spinBox_power_drive_valueChanged(int arg1);

        void on_horizontalSlider_power_arm_valueChanged(int value);

        void on_horizontalSlider_x_arm_valueChanged(int value);

        void on_horizontalSlider_y_arm_valueChanged(int value);

        void on_horizontalSlider_z_arm_valueChanged(int value);

        void on_pushButton_clicked();

        void on_pushButton_button_function_arm_1_clicked();

        void on_pushButton_button_function_arm_2_clicked();

        void on_pushButton_button_function_arm_3_clicked();

        void on_pushButton_button_function_arm_4_clicked();

        void on_pushButton_button_function_arm_5_clicked();

        void on_pushButton_button_function_arm_6_clicked();

        void on_lineEdit_IP_adress_editingFinished();

        void on_lineEdit_IP_adress_textChanged(const QString &arg1);

        void on_lineEdit_port_textChanged(const QString &arg1);

        void on_pushButton_stop_clicked();

        void on_pushButtonUnZoom_clicked();

        void on_pushButtonZoom_clicked();

        void on_pushButtonSend_clicked();

        void on_pushButtonRotate_clicked();

public: //only na użytek klas Qt, potrzebne do praru rzeczy
        Ui::MainWindow *ui;
        QTableWidgetItem * item[3];
        QPoint point;
        QMouseEvent * mouseevent;
        bool isGroupBox6 = false;
        QPixmap pixmap;
        QPixmap pixmap2;
        QPixmap pixmap3;
        Scale scale;
};
#endif // MAINWINDOW_H

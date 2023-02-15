/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMain_Page;
    QAction *actionfd;
    QWidget *centralwidget;
    QGroupBox *groupBoxArm;
    QSlider *horizontalSlider_z_arm;
    QLabel *label_Z;
    QComboBox *comboBox_arm_1;
    QLabel *label_z_arm;
    QComboBox *comboBox_arm_2;
    QComboBox *comboBox_arm_3;
    QComboBox *comboBox_arm_4;
    QComboBox *comboBox_arm_5;
    QComboBox *comboBox_arm_6;
    QLabel *label_Y_2;
    QLabel *label_y_arm;
    QSlider *horizontalSlider_x_arm;
    QLabel *label_x_arm;
    QSpinBox *spinBox_power_arm;
    QLabel *label_POWER;
    QSlider *horizontalSlider_power_arm;
    QLabel *label_X_2;
    QSlider *horizontalSlider_y_arm;
    QPushButton *pushButton_button_function_arm_1;
    QPushButton *pushButton_button_function_arm_2;
    QPushButton *pushButton_button_function_arm_3;
    QPushButton *pushButton_button_function_arm_4;
    QPushButton *pushButton_button_function_arm_5;
    QPushButton *pushButton_button_function_arm_6;
    QGroupBox *groupBoxDrive;
    QLabel *label_Y;
    QLabel *label_y_drive;
    QSlider *horizontalSlider_x_drive;
    QSlider *horizontalSlider_power_drive;
    QLabel *label_X;
    QLabel *label_power_drive;
    QLabel *label_x_drive;
    QSlider *horizontalSlider_y_drive;
    QSpinBox *spinBox_power_drive;
    QGroupBox *groupBox;
    QProgressBar *progressBar_wheel_right_back;
    QProgressBar *progressBar_wheel_right_front;
    QProgressBar *progressBar_wheel_left_middle;
    QProgressBar *progressBar_wheel_left_front;
    QProgressBar *progressBar_wheel_left_back;
    QProgressBar *progressBar_wheel_right_middle;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_joystick;
    QGroupBox *groupBox_6;
    QGroupBox *groupBox_4;
    QGraphicsView *graphicsView;
    QPushButton *pushButtonZoom;
    QPushButton *pushButtonUnZoom;
    QLabel *label_scale;
    QGroupBox *groupBox_7;
    QTableWidget *tableWidget_nav;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *pushButton_add_pos;
    QLabel *label_22;
    QLabel *labelChoosenIndex;
    QPushButton *pushButtonDeletePoint;
    QLineEdit *lineEditPosX;
    QLineEdit *lineEditPosY;
    QGroupBox *groupBox_2;
    QLabel *label_drive_control;
    QLabel *label_arm_control;
    QComboBox *comboBox_arm_control;
    QComboBox *comboBox_drive_control;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_IP_adress;
    QLineEdit *lineEdit_port;
    QLineEdit *lineEditPosYRover;
    QLineEdit *lineEditPosXRover;
    QLineEdit *lineEditRotate;
    QPushButton *pushButtonRotate;
    QPushButton *pushButtonSend;
    QPushButton *pushButton_stop;
    QGroupBox *groupBox_8;
    QLabel *label_frames_received_count;
    QLabel *label_frames_sent_count;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_battery_voltage;
    QLabel *label_2;
    QLabel *label_joysticks_count;
    QMenuBar *menubar;
    QMenu *menuMainPage;
    QMenu *menuBiology;
    QMenu *menuCalibrate;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background: #363062;\n"
"}\n"
"\n"
"QMenuBar\n"
"{\n"
"	background: #363062;\n"
"	color:rgb(255, 255, 255)\n"
"}"));
        MainWindow->setAnimated(true);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionMain_Page = new QAction(MainWindow);
        actionMain_Page->setObjectName(QString::fromUtf8("actionMain_Page"));
        actionfd = new QAction(MainWindow);
        actionfd->setObjectName(QString::fromUtf8("actionfd"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background: #363062;\n"
"	color:	#E9D5DA;\n"
"	border-color: rgb(32, 32, 32);\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"	background-color: #4D4C7D;\n"
"}\n"
"\n"
"QGroupBox\n"
"{\n"
"	background: rgb(0,0,0,0);\n"
"  	border-color: rgb(100, 100, 100);\n"
"  	border-width: 1px;        \n"
"  	border-style: solid;\n"
"	border-radius:15px;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	background-color: rgb(108, 108, 152);\n"
"}\n"
"\n"
"QSpinBox\n"
"{\n"
"	background-color: rgb(108, 108, 152);\n"
"}\n"
"\n"
"QSlider\n"
"{\n"
"	color: rgb(108, 108, 152);\n"
"}"));
        groupBoxArm = new QGroupBox(centralwidget);
        groupBoxArm->setObjectName(QString::fromUtf8("groupBoxArm"));
        groupBoxArm->setGeometry(QRect(10, 10, 291, 351));
        horizontalSlider_z_arm = new QSlider(groupBoxArm);
        horizontalSlider_z_arm->setObjectName(QString::fromUtf8("horizontalSlider_z_arm"));
        horizontalSlider_z_arm->setGeometry(QRect(60, 120, 160, 22));
        horizontalSlider_z_arm->setMinimum(-100);
        horizontalSlider_z_arm->setMaximum(100);
        horizontalSlider_z_arm->setOrientation(Qt::Horizontal);
        label_Z = new QLabel(groupBoxArm);
        label_Z->setObjectName(QString::fromUtf8("label_Z"));
        label_Z->setGeometry(QRect(10, 120, 41, 21));
        comboBox_arm_1 = new QComboBox(groupBoxArm);
        comboBox_arm_1->addItem(QString());
        comboBox_arm_1->addItem(QString());
        comboBox_arm_1->addItem(QString());
        comboBox_arm_1->addItem(QString());
        comboBox_arm_1->addItem(QString());
        comboBox_arm_1->addItem(QString());
        comboBox_arm_1->addItem(QString());
        comboBox_arm_1->setObjectName(QString::fromUtf8("comboBox_arm_1"));
        comboBox_arm_1->setGeometry(QRect(70, 160, 211, 22));
        comboBox_arm_1->setEditable(false);
        label_z_arm = new QLabel(groupBoxArm);
        label_z_arm->setObjectName(QString::fromUtf8("label_z_arm"));
        label_z_arm->setGeometry(QRect(230, 120, 49, 21));
        comboBox_arm_2 = new QComboBox(groupBoxArm);
        comboBox_arm_2->addItem(QString());
        comboBox_arm_2->addItem(QString());
        comboBox_arm_2->addItem(QString());
        comboBox_arm_2->addItem(QString());
        comboBox_arm_2->addItem(QString());
        comboBox_arm_2->addItem(QString());
        comboBox_arm_2->addItem(QString());
        comboBox_arm_2->setObjectName(QString::fromUtf8("comboBox_arm_2"));
        comboBox_arm_2->setGeometry(QRect(70, 190, 211, 22));
        comboBox_arm_2->setEditable(false);
        comboBox_arm_3 = new QComboBox(groupBoxArm);
        comboBox_arm_3->addItem(QString());
        comboBox_arm_3->addItem(QString());
        comboBox_arm_3->addItem(QString());
        comboBox_arm_3->addItem(QString());
        comboBox_arm_3->addItem(QString());
        comboBox_arm_3->addItem(QString());
        comboBox_arm_3->addItem(QString());
        comboBox_arm_3->setObjectName(QString::fromUtf8("comboBox_arm_3"));
        comboBox_arm_3->setGeometry(QRect(70, 220, 211, 22));
        comboBox_arm_4 = new QComboBox(groupBoxArm);
        comboBox_arm_4->addItem(QString());
        comboBox_arm_4->addItem(QString());
        comboBox_arm_4->addItem(QString());
        comboBox_arm_4->addItem(QString());
        comboBox_arm_4->addItem(QString());
        comboBox_arm_4->addItem(QString());
        comboBox_arm_4->addItem(QString());
        comboBox_arm_4->setObjectName(QString::fromUtf8("comboBox_arm_4"));
        comboBox_arm_4->setGeometry(QRect(70, 250, 211, 22));
        comboBox_arm_5 = new QComboBox(groupBoxArm);
        comboBox_arm_5->addItem(QString());
        comboBox_arm_5->addItem(QString());
        comboBox_arm_5->addItem(QString());
        comboBox_arm_5->addItem(QString());
        comboBox_arm_5->addItem(QString());
        comboBox_arm_5->addItem(QString());
        comboBox_arm_5->addItem(QString());
        comboBox_arm_5->setObjectName(QString::fromUtf8("comboBox_arm_5"));
        comboBox_arm_5->setGeometry(QRect(70, 280, 211, 22));
        comboBox_arm_6 = new QComboBox(groupBoxArm);
        comboBox_arm_6->addItem(QString());
        comboBox_arm_6->addItem(QString());
        comboBox_arm_6->addItem(QString());
        comboBox_arm_6->addItem(QString());
        comboBox_arm_6->addItem(QString());
        comboBox_arm_6->addItem(QString());
        comboBox_arm_6->addItem(QString());
        comboBox_arm_6->setObjectName(QString::fromUtf8("comboBox_arm_6"));
        comboBox_arm_6->setGeometry(QRect(70, 310, 211, 22));
        label_Y_2 = new QLabel(groupBoxArm);
        label_Y_2->setObjectName(QString::fromUtf8("label_Y_2"));
        label_Y_2->setGeometry(QRect(10, 90, 41, 21));
        label_y_arm = new QLabel(groupBoxArm);
        label_y_arm->setObjectName(QString::fromUtf8("label_y_arm"));
        label_y_arm->setGeometry(QRect(230, 90, 49, 21));
        horizontalSlider_x_arm = new QSlider(groupBoxArm);
        horizontalSlider_x_arm->setObjectName(QString::fromUtf8("horizontalSlider_x_arm"));
        horizontalSlider_x_arm->setGeometry(QRect(60, 60, 160, 22));
        horizontalSlider_x_arm->setMinimum(-100);
        horizontalSlider_x_arm->setMaximum(100);
        horizontalSlider_x_arm->setSingleStep(0);
        horizontalSlider_x_arm->setPageStep(0);
        horizontalSlider_x_arm->setOrientation(Qt::Horizontal);
        label_x_arm = new QLabel(groupBoxArm);
        label_x_arm->setObjectName(QString::fromUtf8("label_x_arm"));
        label_x_arm->setGeometry(QRect(230, 60, 49, 21));
        spinBox_power_arm = new QSpinBox(groupBoxArm);
        spinBox_power_arm->setObjectName(QString::fromUtf8("spinBox_power_arm"));
        spinBox_power_arm->setGeometry(QRect(230, 30, 51, 22));
        spinBox_power_arm->setMaximum(100);
        label_POWER = new QLabel(groupBoxArm);
        label_POWER->setObjectName(QString::fromUtf8("label_POWER"));
        label_POWER->setGeometry(QRect(10, 30, 41, 21));
        horizontalSlider_power_arm = new QSlider(groupBoxArm);
        horizontalSlider_power_arm->setObjectName(QString::fromUtf8("horizontalSlider_power_arm"));
        horizontalSlider_power_arm->setGeometry(QRect(60, 30, 160, 22));
        horizontalSlider_power_arm->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider_power_arm->setMaximum(100);
        horizontalSlider_power_arm->setOrientation(Qt::Horizontal);
        horizontalSlider_power_arm->setInvertedAppearance(false);
        horizontalSlider_power_arm->setInvertedControls(false);
        label_X_2 = new QLabel(groupBoxArm);
        label_X_2->setObjectName(QString::fromUtf8("label_X_2"));
        label_X_2->setGeometry(QRect(10, 60, 41, 21));
        horizontalSlider_y_arm = new QSlider(groupBoxArm);
        horizontalSlider_y_arm->setObjectName(QString::fromUtf8("horizontalSlider_y_arm"));
        horizontalSlider_y_arm->setGeometry(QRect(60, 90, 160, 22));
        horizontalSlider_y_arm->setAcceptDrops(false);
        horizontalSlider_y_arm->setMinimum(-100);
        horizontalSlider_y_arm->setMaximum(100);
        horizontalSlider_y_arm->setSingleStep(0);
        horizontalSlider_y_arm->setPageStep(0);
        horizontalSlider_y_arm->setOrientation(Qt::Horizontal);
        horizontalSlider_y_arm->setInvertedAppearance(false);
        horizontalSlider_y_arm->setInvertedControls(false);
        horizontalSlider_y_arm->setTickPosition(QSlider::NoTicks);
        horizontalSlider_y_arm->setTickInterval(0);
        pushButton_button_function_arm_1 = new QPushButton(groupBoxArm);
        pushButton_button_function_arm_1->setObjectName(QString::fromUtf8("pushButton_button_function_arm_1"));
        pushButton_button_function_arm_1->setGeometry(QRect(10, 161, 51, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        pushButton_button_function_arm_1->setFont(font);
        pushButton_button_function_arm_1->setStyleSheet(QString::fromUtf8(""));
        pushButton_button_function_arm_2 = new QPushButton(groupBoxArm);
        pushButton_button_function_arm_2->setObjectName(QString::fromUtf8("pushButton_button_function_arm_2"));
        pushButton_button_function_arm_2->setGeometry(QRect(10, 190, 51, 21));
        pushButton_button_function_arm_2->setFont(font);
        pushButton_button_function_arm_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_button_function_arm_3 = new QPushButton(groupBoxArm);
        pushButton_button_function_arm_3->setObjectName(QString::fromUtf8("pushButton_button_function_arm_3"));
        pushButton_button_function_arm_3->setGeometry(QRect(10, 220, 51, 21));
        pushButton_button_function_arm_3->setFont(font);
        pushButton_button_function_arm_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_button_function_arm_4 = new QPushButton(groupBoxArm);
        pushButton_button_function_arm_4->setObjectName(QString::fromUtf8("pushButton_button_function_arm_4"));
        pushButton_button_function_arm_4->setGeometry(QRect(10, 250, 51, 21));
        pushButton_button_function_arm_4->setFont(font);
        pushButton_button_function_arm_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_button_function_arm_5 = new QPushButton(groupBoxArm);
        pushButton_button_function_arm_5->setObjectName(QString::fromUtf8("pushButton_button_function_arm_5"));
        pushButton_button_function_arm_5->setGeometry(QRect(10, 280, 51, 21));
        pushButton_button_function_arm_5->setFont(font);
        pushButton_button_function_arm_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_button_function_arm_6 = new QPushButton(groupBoxArm);
        pushButton_button_function_arm_6->setObjectName(QString::fromUtf8("pushButton_button_function_arm_6"));
        pushButton_button_function_arm_6->setGeometry(QRect(10, 310, 51, 21));
        pushButton_button_function_arm_6->setFont(font);
        pushButton_button_function_arm_6->setStyleSheet(QString::fromUtf8(""));
        groupBoxDrive = new QGroupBox(centralwidget);
        groupBoxDrive->setObjectName(QString::fromUtf8("groupBoxDrive"));
        groupBoxDrive->setGeometry(QRect(310, 10, 291, 521));
        groupBoxDrive->setStyleSheet(QString::fromUtf8(""));
        label_Y = new QLabel(groupBoxDrive);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));
        label_Y->setGeometry(QRect(10, 90, 41, 21));
        label_y_drive = new QLabel(groupBoxDrive);
        label_y_drive->setObjectName(QString::fromUtf8("label_y_drive"));
        label_y_drive->setGeometry(QRect(230, 90, 49, 21));
        horizontalSlider_x_drive = new QSlider(groupBoxDrive);
        horizontalSlider_x_drive->setObjectName(QString::fromUtf8("horizontalSlider_x_drive"));
        horizontalSlider_x_drive->setGeometry(QRect(60, 60, 160, 22));
        horizontalSlider_x_drive->setMinimum(-100);
        horizontalSlider_x_drive->setMaximum(100);
        horizontalSlider_x_drive->setSingleStep(0);
        horizontalSlider_x_drive->setPageStep(0);
        horizontalSlider_x_drive->setOrientation(Qt::Horizontal);
        horizontalSlider_power_drive = new QSlider(groupBoxDrive);
        horizontalSlider_power_drive->setObjectName(QString::fromUtf8("horizontalSlider_power_drive"));
        horizontalSlider_power_drive->setGeometry(QRect(60, 30, 160, 22));
        horizontalSlider_power_drive->setMaximum(100);
        horizontalSlider_power_drive->setOrientation(Qt::Horizontal);
        horizontalSlider_power_drive->setInvertedAppearance(false);
        horizontalSlider_power_drive->setInvertedControls(false);
        label_X = new QLabel(groupBoxDrive);
        label_X->setObjectName(QString::fromUtf8("label_X"));
        label_X->setGeometry(QRect(10, 60, 41, 21));
        label_power_drive = new QLabel(groupBoxDrive);
        label_power_drive->setObjectName(QString::fromUtf8("label_power_drive"));
        label_power_drive->setGeometry(QRect(10, 30, 41, 21));
        label_x_drive = new QLabel(groupBoxDrive);
        label_x_drive->setObjectName(QString::fromUtf8("label_x_drive"));
        label_x_drive->setGeometry(QRect(230, 60, 49, 21));
        horizontalSlider_y_drive = new QSlider(groupBoxDrive);
        horizontalSlider_y_drive->setObjectName(QString::fromUtf8("horizontalSlider_y_drive"));
        horizontalSlider_y_drive->setGeometry(QRect(60, 90, 160, 22));
        horizontalSlider_y_drive->setAcceptDrops(false);
        horizontalSlider_y_drive->setMinimum(-100);
        horizontalSlider_y_drive->setMaximum(100);
        horizontalSlider_y_drive->setSingleStep(0);
        horizontalSlider_y_drive->setPageStep(0);
        horizontalSlider_y_drive->setOrientation(Qt::Horizontal);
        horizontalSlider_y_drive->setInvertedAppearance(false);
        horizontalSlider_y_drive->setInvertedControls(false);
        horizontalSlider_y_drive->setTickPosition(QSlider::NoTicks);
        horizontalSlider_y_drive->setTickInterval(0);
        spinBox_power_drive = new QSpinBox(groupBoxDrive);
        spinBox_power_drive->setObjectName(QString::fromUtf8("spinBox_power_drive"));
        spinBox_power_drive->setGeometry(QRect(230, 30, 51, 22));
        spinBox_power_drive->setMaximum(100);
        groupBox = new QGroupBox(groupBoxDrive);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 380, 271, 131));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        progressBar_wheel_right_back = new QProgressBar(groupBox);
        progressBar_wheel_right_back->setObjectName(QString::fromUtf8("progressBar_wheel_right_back"));
        progressBar_wheel_right_back->setGeometry(QRect(140, 100, 121, 21));
        progressBar_wheel_right_back->setLayoutDirection(Qt::LeftToRight);
        progressBar_wheel_right_back->setAutoFillBackground(false);
        progressBar_wheel_right_back->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(235, 0, 0, 150);\n"
"    border: 1px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color:  rgba(0, 255, 123, 150);\n"
"    width: 1px;\n"
"    \n"
"}"));
        progressBar_wheel_right_back->setMaximum(6400);
        progressBar_wheel_right_back->setValue(3200);
        progressBar_wheel_right_back->setTextVisible(true);
        progressBar_wheel_right_back->setOrientation(Qt::Horizontal);
        progressBar_wheel_right_back->setInvertedAppearance(false);
        progressBar_wheel_right_back->setTextDirection(QProgressBar::TopToBottom);
        progressBar_wheel_right_front = new QProgressBar(groupBox);
        progressBar_wheel_right_front->setObjectName(QString::fromUtf8("progressBar_wheel_right_front"));
        progressBar_wheel_right_front->setGeometry(QRect(140, 40, 121, 21));
        progressBar_wheel_right_front->setLayoutDirection(Qt::LeftToRight);
        progressBar_wheel_right_front->setAutoFillBackground(false);
        progressBar_wheel_right_front->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(235, 0, 0, 150);\n"
"    border: 1px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color:  rgba(0, 255, 123, 150);\n"
"    width: 1px;\n"
"    \n"
"}"));
        progressBar_wheel_right_front->setMaximum(6400);
        progressBar_wheel_right_front->setValue(3200);
        progressBar_wheel_right_front->setTextVisible(true);
        progressBar_wheel_right_front->setOrientation(Qt::Horizontal);
        progressBar_wheel_right_front->setInvertedAppearance(false);
        progressBar_wheel_right_front->setTextDirection(QProgressBar::TopToBottom);
        progressBar_wheel_left_middle = new QProgressBar(groupBox);
        progressBar_wheel_left_middle->setObjectName(QString::fromUtf8("progressBar_wheel_left_middle"));
        progressBar_wheel_left_middle->setGeometry(QRect(10, 70, 121, 21));
        progressBar_wheel_left_middle->setLayoutDirection(Qt::LeftToRight);
        progressBar_wheel_left_middle->setAutoFillBackground(false);
        progressBar_wheel_left_middle->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(235, 0, 0, 150);\n"
"    border: 1px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color:  rgba(0, 255, 123, 150);\n"
"    width: 1px;\n"
"    \n"
"}"));
        progressBar_wheel_left_middle->setMaximum(6400);
        progressBar_wheel_left_middle->setValue(3200);
        progressBar_wheel_left_middle->setTextVisible(true);
        progressBar_wheel_left_middle->setOrientation(Qt::Horizontal);
        progressBar_wheel_left_middle->setInvertedAppearance(false);
        progressBar_wheel_left_middle->setTextDirection(QProgressBar::TopToBottom);
        progressBar_wheel_left_front = new QProgressBar(groupBox);
        progressBar_wheel_left_front->setObjectName(QString::fromUtf8("progressBar_wheel_left_front"));
        progressBar_wheel_left_front->setGeometry(QRect(10, 40, 121, 21));
        progressBar_wheel_left_front->setLayoutDirection(Qt::LeftToRight);
        progressBar_wheel_left_front->setAutoFillBackground(false);
        progressBar_wheel_left_front->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(235, 0, 0, 150);\n"
"    border: 1px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color:  rgba(0, 255, 123, 150);\n"
"    width: 1px;\n"
"    \n"
"}"));
        progressBar_wheel_left_front->setMinimum(0);
        progressBar_wheel_left_front->setMaximum(6400);
        progressBar_wheel_left_front->setValue(3200);
        progressBar_wheel_left_front->setTextVisible(true);
        progressBar_wheel_left_front->setOrientation(Qt::Horizontal);
        progressBar_wheel_left_front->setInvertedAppearance(false);
        progressBar_wheel_left_front->setTextDirection(QProgressBar::TopToBottom);
        progressBar_wheel_left_back = new QProgressBar(groupBox);
        progressBar_wheel_left_back->setObjectName(QString::fromUtf8("progressBar_wheel_left_back"));
        progressBar_wheel_left_back->setGeometry(QRect(10, 100, 121, 21));
        progressBar_wheel_left_back->setLayoutDirection(Qt::LeftToRight);
        progressBar_wheel_left_back->setAutoFillBackground(false);
        progressBar_wheel_left_back->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(235, 0, 0, 150);\n"
"    border: 1px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color:  rgba(0, 255, 123, 150);\n"
"    width: 1px;\n"
"    \n"
"}"));
        progressBar_wheel_left_back->setMaximum(6400);
        progressBar_wheel_left_back->setValue(3200);
        progressBar_wheel_left_back->setTextVisible(true);
        progressBar_wheel_left_back->setOrientation(Qt::Horizontal);
        progressBar_wheel_left_back->setInvertedAppearance(false);
        progressBar_wheel_left_back->setTextDirection(QProgressBar::TopToBottom);
        progressBar_wheel_right_middle = new QProgressBar(groupBox);
        progressBar_wheel_right_middle->setObjectName(QString::fromUtf8("progressBar_wheel_right_middle"));
        progressBar_wheel_right_middle->setGeometry(QRect(140, 70, 121, 21));
        progressBar_wheel_right_middle->setLayoutDirection(Qt::LeftToRight);
        progressBar_wheel_right_middle->setAutoFillBackground(false);
        progressBar_wheel_right_middle->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(235, 0, 0, 150);\n"
"    border: 1px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color:  rgba(0, 255, 123, 150);\n"
"    width: 1px;\n"
"    \n"
"}"));
        progressBar_wheel_right_middle->setMaximum(6400);
        progressBar_wheel_right_middle->setValue(3200);
        progressBar_wheel_right_middle->setTextVisible(true);
        progressBar_wheel_right_middle->setOrientation(Qt::Horizontal);
        progressBar_wheel_right_middle->setInvertedAppearance(false);
        progressBar_wheel_right_middle->setTextDirection(QProgressBar::TopToBottom);
        groupBox->raise();
        label_Y->raise();
        label_y_drive->raise();
        horizontalSlider_x_drive->raise();
        horizontalSlider_power_drive->raise();
        label_X->raise();
        label_power_drive->raise();
        label_x_drive->raise();
        horizontalSlider_y_drive->raise();
        spinBox_power_drive->raise();
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 370, 291, 321));
        pushButton_joystick = new QPushButton(centralwidget);
        pushButton_joystick->setObjectName(QString::fromUtf8("pushButton_joystick"));
        pushButton_joystick->setEnabled(true);
        pushButton_joystick->setGeometry(QRect(-30, 680, 50, 50));
        pushButton_joystick->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_joystick->setStyleSheet(QString::fromUtf8("QPushButton\n"
" {\n"
"  background: #E9A6A6;\n"
"  border-color: rgb(100, 100, 100);\n"
"  border-width: 2px;        \n"
"  border-style: solid;\n"
"  border-radius: 25px;\n"
"  margin:0px;\n"
"  padding:0px;\n"
"}"));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setEnabled(true);
        groupBox_6->setGeometry(QRect(330, 130, 250, 250));
        groupBox_6->setMouseTracking(true);
        groupBox_6->setStyleSheet(QString::fromUtf8("QGroupBox\n"
" {\n"
"	background: rgb(0,0,0,0);\n"
"  	border-color: rgb(100, 100, 100);\n"
"  	border-width: 1px;        \n"
"  	border-style: solid;\n"
"	border-radius: 25px;\n"
"  	margin:0px;\n"
"  	padding:0px;\n"
"}"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(610, 0, 661, 351));
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        graphicsView = new QGraphicsView(groupBox_4);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 581, 311));
        pushButtonZoom = new QPushButton(groupBox_4);
        pushButtonZoom->setObjectName(QString::fromUtf8("pushButtonZoom"));
        pushButtonZoom->setGeometry(QRect(610, 270, 41, 24));
        pushButtonUnZoom = new QPushButton(groupBox_4);
        pushButtonUnZoom->setObjectName(QString::fromUtf8("pushButtonUnZoom"));
        pushButtonUnZoom->setGeometry(QRect(610, 300, 41, 24));
        label_scale = new QLabel(groupBox_4);
        label_scale->setObjectName(QString::fromUtf8("label_scale"));
        label_scale->setGeometry(QRect(610, 250, 41, 20));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(920, 360, 341, 311));
        tableWidget_nav = new QTableWidget(groupBox_7);
        if (tableWidget_nav->columnCount() < 3)
            tableWidget_nav->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_nav->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_nav->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_nav->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_nav->setObjectName(QString::fromUtf8("tableWidget_nav"));
        tableWidget_nav->setGeometry(QRect(10, 20, 321, 201));
        tableWidget_nav->setMaximumSize(QSize(351, 16777215));
        tableWidget_nav->setLayoutDirection(Qt::LeftToRight);
        tableWidget_nav->setAutoFillBackground(false);
        tableWidget_nav->setStyleSheet(QString::fromUtf8(""));
        tableWidget_nav->setLocale(QLocale(QLocale::Polish, QLocale::Poland));
        tableWidget_nav->setAutoScroll(true);
        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 250, 16, 21));
        label_19 = new QLabel(groupBox_7);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(140, 250, 16, 21));
        pushButton_add_pos = new QPushButton(groupBox_7);
        pushButton_add_pos->setObjectName(QString::fromUtf8("pushButton_add_pos"));
        pushButton_add_pos->setGeometry(QRect(270, 250, 61, 21));
        label_22 = new QLabel(groupBox_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(30, 280, 81, 16));
        labelChoosenIndex = new QLabel(groupBox_7);
        labelChoosenIndex->setObjectName(QString::fromUtf8("labelChoosenIndex"));
        labelChoosenIndex->setGeometry(QRect(120, 280, 49, 16));
        pushButtonDeletePoint = new QPushButton(groupBox_7);
        pushButtonDeletePoint->setObjectName(QString::fromUtf8("pushButtonDeletePoint"));
        pushButtonDeletePoint->setGeometry(QRect(270, 280, 61, 24));
        lineEditPosX = new QLineEdit(groupBox_7);
        lineEditPosX->setObjectName(QString::fromUtf8("lineEditPosX"));
        lineEditPosX->setGeometry(QRect(30, 250, 101, 22));
        lineEditPosY = new QLineEdit(groupBox_7);
        lineEditPosY->setObjectName(QString::fromUtf8("lineEditPosY"));
        lineEditPosY->setGeometry(QRect(160, 250, 101, 22));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(610, 360, 301, 331));
        label_drive_control = new QLabel(groupBox_2);
        label_drive_control->setObjectName(QString::fromUtf8("label_drive_control"));
        label_drive_control->setGeometry(QRect(25, 186, 51, 20));
        label_arm_control = new QLabel(groupBox_2);
        label_arm_control->setObjectName(QString::fromUtf8("label_arm_control"));
        label_arm_control->setGeometry(QRect(25, 156, 31, 20));
        label_arm_control->setFrameShape(QFrame::NoFrame);
        comboBox_arm_control = new QComboBox(groupBox_2);
        comboBox_arm_control->addItem(QString());
        comboBox_arm_control->addItem(QString());
        comboBox_arm_control->addItem(QString());
        comboBox_arm_control->setObjectName(QString::fromUtf8("comboBox_arm_control"));
        comboBox_arm_control->setGeometry(QRect(125, 156, 151, 26));
        comboBox_arm_control->setMaxVisibleItems(5);
        comboBox_drive_control = new QComboBox(groupBox_2);
        comboBox_drive_control->addItem(QString());
        comboBox_drive_control->addItem(QString());
        comboBox_drive_control->addItem(QString());
        comboBox_drive_control->setObjectName(QString::fromUtf8("comboBox_drive_control"));
        comboBox_drive_control->setGeometry(QRect(125, 186, 151, 26));
        comboBox_drive_control->setMaxVisibleItems(5);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(25, 96, 81, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(25, 126, 81, 21));
        lineEdit_IP_adress = new QLineEdit(groupBox_2);
        lineEdit_IP_adress->setObjectName(QString::fromUtf8("lineEdit_IP_adress"));
        lineEdit_IP_adress->setGeometry(QRect(125, 96, 151, 26));
        lineEdit_port = new QLineEdit(groupBox_2);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(125, 126, 151, 26));
        lineEditPosYRover = new QLineEdit(groupBox_2);
        lineEditPosYRover->setObjectName(QString::fromUtf8("lineEditPosYRover"));
        lineEditPosYRover->setGeometry(QRect(75, 226, 41, 22));
        lineEditPosXRover = new QLineEdit(groupBox_2);
        lineEditPosXRover->setObjectName(QString::fromUtf8("lineEditPosXRover"));
        lineEditPosXRover->setGeometry(QRect(25, 226, 41, 22));
        lineEditRotate = new QLineEdit(groupBox_2);
        lineEditRotate->setObjectName(QString::fromUtf8("lineEditRotate"));
        lineEditRotate->setGeometry(QRect(25, 256, 91, 22));
        pushButtonRotate = new QPushButton(groupBox_2);
        pushButtonRotate->setObjectName(QString::fromUtf8("pushButtonRotate"));
        pushButtonRotate->setGeometry(QRect(125, 256, 151, 24));
        pushButtonSend = new QPushButton(groupBox_2);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(125, 226, 151, 24));
        pushButton_stop = new QPushButton(groupBox_2);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(20, 30, 261, 51));
        pushButton_stop->setStyleSheet(QString::fromUtf8("\n"
"  background: rgb(156, 18, 18);\n"
"  \n"
"\n"
"\n"
""));
        pushButton_stop->setCheckable(false);
        pushButton_stop->setAutoDefault(false);
        pushButton_stop->setFlat(false);
        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(310, 540, 291, 151));
        label_frames_received_count = new QLabel(groupBox_8);
        label_frames_received_count->setObjectName(QString::fromUtf8("label_frames_received_count"));
        label_frames_received_count->setGeometry(QRect(140, 50, 131, 20));
        label_frames_sent_count = new QLabel(groupBox_8);
        label_frames_sent_count->setObjectName(QString::fromUtf8("label_frames_sent_count"));
        label_frames_sent_count->setGeometry(QRect(140, 30, 131, 20));
        label_frames_sent_count->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBox_8);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 91, 20));
        label->setStyleSheet(QString::fromUtf8(""));
        label_8 = new QLabel(groupBox_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 50, 111, 20));
        label_10 = new QLabel(groupBox_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 90, 111, 20));
        label_battery_voltage = new QLabel(groupBox_8);
        label_battery_voltage->setObjectName(QString::fromUtf8("label_battery_voltage"));
        label_battery_voltage->setGeometry(QRect(140, 90, 41, 20));
        label_2 = new QLabel(groupBox_8);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 111, 20));
        label_joysticks_count = new QLabel(groupBox_8);
        label_joysticks_count->setObjectName(QString::fromUtf8("label_joysticks_count"));
        label_joysticks_count->setGeometry(QRect(140, 70, 16, 20));
        MainWindow->setCentralWidget(centralwidget);
        pushButton_joystick->raise();
        groupBoxArm->raise();
        groupBoxDrive->raise();
        groupBox_5->raise();
        groupBox_6->raise();
        groupBox_4->raise();
        groupBox_7->raise();
        groupBox_2->raise();
        groupBox_8->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        menuMainPage = new QMenu(menubar);
        menuMainPage->setObjectName(QString::fromUtf8("menuMainPage"));
        menuBiology = new QMenu(menubar);
        menuBiology->setObjectName(QString::fromUtf8("menuBiology"));
        menuCalibrate = new QMenu(menubar);
        menuCalibrate->setObjectName(QString::fromUtf8("menuCalibrate"));
        menuCalibrate->setEnabled(true);
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuMainPage->menuAction());
        menubar->addAction(menuBiology->menuAction());
        menubar->addAction(menuCalibrate->menuAction());

        retranslateUi(MainWindow);

        comboBox_arm_1->setCurrentIndex(1);
        comboBox_arm_2->setCurrentIndex(2);
        comboBox_arm_3->setCurrentIndex(3);
        comboBox_arm_4->setCurrentIndex(4);
        comboBox_arm_5->setCurrentIndex(5);
        comboBox_arm_6->setCurrentIndex(6);
        comboBox_drive_control->setCurrentIndex(0);
        pushButton_stop->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionMain_Page->setText(QCoreApplication::translate("MainWindow", "Main Page", nullptr));
        actionfd->setText(QCoreApplication::translate("MainWindow", "fd", nullptr));
        groupBoxArm->setTitle(QCoreApplication::translate("MainWindow", "Arm", nullptr));
        label_Z->setText(QCoreApplication::translate("MainWindow", "Z Axis", nullptr));
        comboBox_arm_1->setItemText(0, QCoreApplication::translate("MainWindow", "--None--", nullptr));
        comboBox_arm_1->setItemText(1, QCoreApplication::translate("MainWindow", "First Segment", nullptr));
        comboBox_arm_1->setItemText(2, QCoreApplication::translate("MainWindow", "Second Segment", nullptr));
        comboBox_arm_1->setItemText(3, QCoreApplication::translate("MainWindow", "Third Segment", nullptr));
        comboBox_arm_1->setItemText(4, QCoreApplication::translate("MainWindow", "Jaws", nullptr));
        comboBox_arm_1->setItemText(5, QCoreApplication::translate("MainWindow", "All", nullptr));
        comboBox_arm_1->setItemText(6, QCoreApplication::translate("MainWindow", "Inverse Kinematics", nullptr));

        comboBox_arm_1->setCurrentText(QCoreApplication::translate("MainWindow", "First Segment", nullptr));
        label_z_arm->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox_arm_2->setItemText(0, QCoreApplication::translate("MainWindow", "--None--", nullptr));
        comboBox_arm_2->setItemText(1, QCoreApplication::translate("MainWindow", "First Segment", nullptr));
        comboBox_arm_2->setItemText(2, QCoreApplication::translate("MainWindow", "Second Segment", nullptr));
        comboBox_arm_2->setItemText(3, QCoreApplication::translate("MainWindow", "Third Segment", nullptr));
        comboBox_arm_2->setItemText(4, QCoreApplication::translate("MainWindow", "Jaws", nullptr));
        comboBox_arm_2->setItemText(5, QCoreApplication::translate("MainWindow", "All", nullptr));
        comboBox_arm_2->setItemText(6, QCoreApplication::translate("MainWindow", "Inverse Kinematics", nullptr));

        comboBox_arm_2->setCurrentText(QCoreApplication::translate("MainWindow", "Second Segment", nullptr));
        comboBox_arm_3->setItemText(0, QCoreApplication::translate("MainWindow", "--None--", nullptr));
        comboBox_arm_3->setItemText(1, QCoreApplication::translate("MainWindow", "First Segment", nullptr));
        comboBox_arm_3->setItemText(2, QCoreApplication::translate("MainWindow", "Second Segment", nullptr));
        comboBox_arm_3->setItemText(3, QCoreApplication::translate("MainWindow", "Third Segment", nullptr));
        comboBox_arm_3->setItemText(4, QCoreApplication::translate("MainWindow", "Jaws", nullptr));
        comboBox_arm_3->setItemText(5, QCoreApplication::translate("MainWindow", "All", nullptr));
        comboBox_arm_3->setItemText(6, QCoreApplication::translate("MainWindow", "Inverse Kinematics", nullptr));

        comboBox_arm_4->setItemText(0, QCoreApplication::translate("MainWindow", "--None--", nullptr));
        comboBox_arm_4->setItemText(1, QCoreApplication::translate("MainWindow", "First Segment", nullptr));
        comboBox_arm_4->setItemText(2, QCoreApplication::translate("MainWindow", "Second Segment", nullptr));
        comboBox_arm_4->setItemText(3, QCoreApplication::translate("MainWindow", "Third Segment", nullptr));
        comboBox_arm_4->setItemText(4, QCoreApplication::translate("MainWindow", "Jaws", nullptr));
        comboBox_arm_4->setItemText(5, QCoreApplication::translate("MainWindow", "All", nullptr));
        comboBox_arm_4->setItemText(6, QCoreApplication::translate("MainWindow", "Inverse Kinematics", nullptr));

        comboBox_arm_5->setItemText(0, QCoreApplication::translate("MainWindow", "--None--", nullptr));
        comboBox_arm_5->setItemText(1, QCoreApplication::translate("MainWindow", "First Segment", nullptr));
        comboBox_arm_5->setItemText(2, QCoreApplication::translate("MainWindow", "Second Segment", nullptr));
        comboBox_arm_5->setItemText(3, QCoreApplication::translate("MainWindow", "Third Segment", nullptr));
        comboBox_arm_5->setItemText(4, QCoreApplication::translate("MainWindow", "Jaws", nullptr));
        comboBox_arm_5->setItemText(5, QCoreApplication::translate("MainWindow", "All", nullptr));
        comboBox_arm_5->setItemText(6, QCoreApplication::translate("MainWindow", "Inverse Kinematics", nullptr));

        comboBox_arm_6->setItemText(0, QCoreApplication::translate("MainWindow", "--None--", nullptr));
        comboBox_arm_6->setItemText(1, QCoreApplication::translate("MainWindow", "First Segment", nullptr));
        comboBox_arm_6->setItemText(2, QCoreApplication::translate("MainWindow", "Second Segment", nullptr));
        comboBox_arm_6->setItemText(3, QCoreApplication::translate("MainWindow", "Third Segment", nullptr));
        comboBox_arm_6->setItemText(4, QCoreApplication::translate("MainWindow", "Jaws", nullptr));
        comboBox_arm_6->setItemText(5, QCoreApplication::translate("MainWindow", "All", nullptr));
        comboBox_arm_6->setItemText(6, QCoreApplication::translate("MainWindow", "Inverse Kinematics", nullptr));

        label_Y_2->setText(QCoreApplication::translate("MainWindow", "Y Axis", nullptr));
        label_y_arm->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_x_arm->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_POWER->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
        label_X_2->setText(QCoreApplication::translate("MainWindow", "X Axis", nullptr));
        pushButton_button_function_arm_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_button_function_arm_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_button_function_arm_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_button_function_arm_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_button_function_arm_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_button_function_arm_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        groupBoxDrive->setTitle(QCoreApplication::translate("MainWindow", "Drive", nullptr));
        label_Y->setText(QCoreApplication::translate("MainWindow", "Y Axis", nullptr));
        label_y_drive->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_X->setText(QCoreApplication::translate("MainWindow", "X Axis", nullptr));
        label_power_drive->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
        label_x_drive->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Wheels Speeds", nullptr));
        progressBar_wheel_right_back->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        progressBar_wheel_right_front->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        progressBar_wheel_left_middle->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        progressBar_wheel_left_front->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        progressBar_wheel_left_back->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        progressBar_wheel_right_middle->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Arm's Simulation", nullptr));
        pushButton_joystick->setText(QString());
        groupBox_6->setTitle(QString());
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Compass / Map", nullptr));
        pushButtonZoom->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButtonUnZoom->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "GPS List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_nav->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_nav->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "X - Geo Width", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_nav->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Y- Geo Length", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        pushButton_add_pos->setText(QCoreApplication::translate("MainWindow", "Add Pos", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Choosen Inxed:", nullptr));
        labelChoosenIndex->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButtonDeletePoint->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Fast Settings", nullptr));
        label_drive_control->setText(QCoreApplication::translate("MainWindow", "Drive", nullptr));
        label_arm_control->setText(QCoreApplication::translate("MainWindow", "Arm", nullptr));
        comboBox_arm_control->setItemText(0, QCoreApplication::translate("MainWindow", "Virtual Sliders", nullptr));
        comboBox_arm_control->setItemText(1, QCoreApplication::translate("MainWindow", "Physical Joystick 1", nullptr));
        comboBox_arm_control->setItemText(2, QCoreApplication::translate("MainWindow", "Physical Joystick 2", nullptr));

        comboBox_drive_control->setItemText(0, QCoreApplication::translate("MainWindow", "Virtual Sliders", nullptr));
        comboBox_drive_control->setItemText(1, QCoreApplication::translate("MainWindow", "Physical Joystick 1", nullptr));
        comboBox_drive_control->setItemText(2, QCoreApplication::translate("MainWindow", "Physical Joystick 2", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "IP Adress:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        lineEdit_IP_adress->setText(QCoreApplication::translate("MainWindow", "192.168.1.10", nullptr));
        lineEdit_port->setText(QCoreApplication::translate("MainWindow", "5150", nullptr));
        lineEditPosYRover->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        lineEditPosXRover->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lineEditRotate->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButtonRotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "General Info", nullptr));
        label_frames_received_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_frames_sent_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sent Frames", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Recieved Frames", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Battery Voltage", nullptr));
        label_battery_voltage->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Found Joysticks:", nullptr));
        label_joysticks_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        menuMainPage->setTitle(QCoreApplication::translate("MainWindow", "MainPage", nullptr));
        menuBiology->setTitle(QCoreApplication::translate("MainWindow", "Biology", nullptr));
        menuCalibrate->setTitle(QCoreApplication::translate("MainWindow", "Calibrate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

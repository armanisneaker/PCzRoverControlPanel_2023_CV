#include <QApplication>
#include <QPushButton>
#include <QTimer>
#include <QThread>
#include <QtEndian>
#include "mainwindow.h"
#include "Drive.h"
#include "Arm.h"
#include "Input.h"
#include "Joystick.h"
#include "Connection.h"
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("fusion");


    MainWindow w;
    Drive drive;
    Arm arm;
    Input input;
    Joystick* joysticks[2];
    Connection connection;

    int x=1920/4;
    int y=1080/4;

    int bytesSentInFrame{0};
    int framesSent{0};
    int framesReceived{0};
    int framesReceivedOld{0};
    int cyclesFromLastFrameReceived{0};

    int wheelSpeeds[6];
    int motorSpeeds[2];

    int physicalJoystickDrivePower = 0;
    int physicalJoystickDriveX = 0;
    int physicalJoystickDriveY = 0;
    int physicalJoystickArmPower = 0;
    int physicalJoystickArmX = 0;
    int physicalJoystickArmY = 0;
    int physicalJoystickArmZ = 0;
    int physicalJoystickButtonPressed = -1;
    float physicalJoystickMaxValue = 65535;

    unsigned int numJoysticks = 0;
    unsigned int numJoysticksOld = 0;

    QByteArray frame(320,0);
    QByteArray frameReceived(320,0);
    w.setGeometry(x,y,w.width(),w.height());
    w.show();

    QTimer uiTimer;
    QTimer communicationTimer;

    //uiTimer.setTimerType(Qt::PreciseTimer);
    //uiTimer.setInterval(10);

        QObject::connect(&uiTimer, &QTimer::timeout, [&]()
        {
            input.drive.x = 0;
            input.drive.y = 0;
            input.drive.power = w.ui->horizontalSlider_power_drive->sliderPosition();

            input.arm.x = 0;
            input.arm.y = 0;
            input.arm.z = 0;
            input.arm.power = w.ui->horizontalSlider_power_arm->sliderPosition();


            numJoysticks = Joystick::deviceCount();
            w.ui->label_joysticks_count->setText(QString::number(numJoysticks));
            if(numJoysticks!=numJoysticksOld)
            {
                for (int i = 0; i < numJoysticksOld; i++)
                {
                    joysticks[i]->close();
                }
                for (int i = 0; i < numJoysticks; i++)
                {
                    joysticks[i] = new Joystick(i);
                    joysticks[i]->open();
                }
            }
            numJoysticksOld = numJoysticks;

            DIJOYSTATE2 joystickState[4];

            if(w.ui->comboBox_arm_control->currentIndex() == 0)
            {
                if(w.ui->horizontalSlider_x_arm->isSliderDown() || w.ui->horizontalSlider_y_arm->isSliderDown() || w.ui->horizontalSlider_z_arm->isSliderDown() || w.ui->horizontalSlider_power_arm->isSliderDown())
                {
                    input.arm.x = w.ui->horizontalSlider_x_arm->value();
                    input.arm.y = w.ui->horizontalSlider_y_arm->value();
                    input.arm.z = w.ui->horizontalSlider_z_arm->value();
                    input.arm.power = w.ui->horizontalSlider_power_arm->value();
                }
                else
                {
                    w.ui->horizontalSlider_x_arm->setSliderPosition(0);
                    w.ui->horizontalSlider_y_arm->setSliderPosition(0);
                    w.ui->horizontalSlider_z_arm->setSliderPosition(0);
                }
            }
            else
            {
                w.ui->horizontalSlider_x_arm->setSliderPosition(0);
                w.ui->horizontalSlider_y_arm->setSliderPosition(0);
                w.ui->horizontalSlider_z_arm->setSliderPosition(0);
                w.ui->horizontalSlider_power_arm->setSliderPosition(0);
            }

            for(int joystickNumber = 0; joystickNumber< numJoysticks; joystickNumber++)
            {
                if(w.ui->comboBox_arm_control->currentIndex() == joystickNumber+1)
                {
                    joysticks[joystickNumber]->poll(&joystickState[joystickNumber]);
                    physicalJoystickArmPower = ((joystickState[joystickNumber].rglSlider[0]/physicalJoystickMaxValue)*100-100)*-1;
                    physicalJoystickArmX = (joystickState[joystickNumber].lX/physicalJoystickMaxValue-0.50)*200;
                    physicalJoystickArmY = (joystickState[joystickNumber].lY/physicalJoystickMaxValue-0.50)*-200;
                    physicalJoystickArmZ = (joystickState[joystickNumber].lRz/physicalJoystickMaxValue-0.50)*200;
                    input.arm.x = physicalJoystickArmX;
                    input.arm.y = physicalJoystickArmY;
                    input.arm.z = physicalJoystickArmZ;
                    input.arm.power = physicalJoystickArmPower;
                    w.ui->horizontalSlider_power_arm->setSliderPosition(input.arm.power);
                    w.ui->horizontalSlider_x_arm->setSliderPosition(input.arm.x);
                    w.ui->horizontalSlider_y_arm->setSliderPosition(input.arm.y);
                    w.ui->horizontalSlider_z_arm->setSliderPosition(input.arm.z);

                    physicalJoystickButtonPressed = -1;

                    for (int i = 0; i < 20; i++) //128 max
                    {
                        if (joystickState[joystickNumber].rgbButtons[i] & 0x80)
                        {
                            qDebug()<<i;

                            physicalJoystickButtonPressed = i;

                            switch(i)
                            {
                            case 4:
                                //w.buttonFunction = Arm::buttonFunction::first;
                                switch(w.ui->comboBox_arm_1->currentIndex())
                                {
                                case 0:
                                    w.buttonFunction = Arm::buttonFunction::none;
                                    break;
                                case 1:
                                    w.buttonFunction = Arm::buttonFunction::first;
                                    break;
                                case 2:
                                    w.buttonFunction = Arm::buttonFunction::second;
                                    break;
                                case 3:
                                    w.buttonFunction = Arm::buttonFunction::third;
                                    break;
                                case 4:
                                    w.buttonFunction = Arm::buttonFunction::jaws;
                                    break;
                                case 5:
                                    w.buttonFunction = Arm::buttonFunction::all;
                                    break;
                                case 6:
                                    w.buttonFunction = Arm::buttonFunction::inverseKinematics;
                                    break;
                                }
                                break;
                            case 5:
                                switch(w.ui->comboBox_arm_2->currentIndex())
                                {
                                case 0:
                                    w.buttonFunction = Arm::buttonFunction::none;
                                    break;
                                case 1:
                                    w.buttonFunction = Arm::buttonFunction::first;
                                    break;
                                case 2:
                                    w.buttonFunction = Arm::buttonFunction::second;
                                    break;
                                case 3:
                                    w.buttonFunction = Arm::buttonFunction::third;
                                    break;
                                case 4:
                                    w.buttonFunction = Arm::buttonFunction::jaws;
                                    break;
                                case 5:
                                    w.buttonFunction = Arm::buttonFunction::all;
                                    break;
                                case 6:
                                    w.buttonFunction = Arm::buttonFunction::inverseKinematics;
                                    break;
                                }
                                break;
                            case 6:
                                switch(w.ui->comboBox_arm_3->currentIndex())
                                {
                                case 0:
                                    w.buttonFunction = Arm::buttonFunction::none;
                                    break;
                                case 1:
                                    w.buttonFunction = Arm::buttonFunction::first;
                                    break;
                                case 2:
                                    w.buttonFunction = Arm::buttonFunction::second;
                                    break;
                                case 3:
                                    w.buttonFunction = Arm::buttonFunction::third;
                                    break;
                                case 4:
                                    w.buttonFunction = Arm::buttonFunction::jaws;
                                    break;
                                case 5:
                                    w.buttonFunction = Arm::buttonFunction::all;
                                    break;
                                case 6:
                                    w.buttonFunction = Arm::buttonFunction::inverseKinematics;
                                    break;
                                }
                                break;
                            case 7:
                                switch(w.ui->comboBox_arm_4->currentIndex())
                                {
                                case 0:
                                    w.buttonFunction = Arm::buttonFunction::none;
                                    break;
                                case 1:
                                    w.buttonFunction = Arm::buttonFunction::first;
                                    break;
                                case 2:
                                    w.buttonFunction = Arm::buttonFunction::second;
                                    break;
                                case 3:
                                    w.buttonFunction = Arm::buttonFunction::third;
                                    break;
                                case 4:
                                    w.buttonFunction = Arm::buttonFunction::jaws;
                                    break;
                                case 5:
                                    w.buttonFunction = Arm::buttonFunction::all;
                                    break;
                                case 6:
                                    w.buttonFunction = Arm::buttonFunction::inverseKinematics;
                                    break;
                                }
                                break;
                            case 8:
                                switch(w.ui->comboBox_arm_5->currentIndex())
                                {
                                case 0:
                                    w.buttonFunction = Arm::buttonFunction::none;
                                    break;
                                case 1:
                                    w.buttonFunction = Arm::buttonFunction::first;
                                    break;
                                case 2:
                                    w.buttonFunction = Arm::buttonFunction::second;
                                    break;
                                case 3:
                                    w.buttonFunction = Arm::buttonFunction::third;
                                    break;
                                case 4:
                                    w.buttonFunction = Arm::buttonFunction::jaws;
                                    break;
                                case 5:
                                    w.buttonFunction = Arm::buttonFunction::all;
                                    break;
                                case 6:
                                    w.buttonFunction = Arm::buttonFunction::inverseKinematics;
                                    break;
                                }
                                break;
                            case 9:
                                switch(w.ui->comboBox_arm_6->currentIndex())
                                {
                                case 0:
                                    w.buttonFunction = Arm::buttonFunction::none;
                                    break;
                                case 1:
                                    w.buttonFunction = Arm::buttonFunction::first;
                                    break;
                                case 2:
                                    w.buttonFunction = Arm::buttonFunction::second;
                                    break;
                                case 3:
                                    w.buttonFunction = Arm::buttonFunction::third;
                                    break;
                                case 4:
                                    w.buttonFunction = Arm::buttonFunction::jaws;
                                    break;
                                case 5:
                                    w.buttonFunction = Arm::buttonFunction::all;
                                    break;
                                case 6:
                                    w.buttonFunction = Arm::buttonFunction::inverseKinematics;
                                    break;
                                }
                                break;
                            }
                        }
                    }
                }
            }

            if(w.ui->comboBox_drive_control->currentIndex() == 0)
            {
                if(w.ui->horizontalSlider_power_drive->isSliderDown())
                {
                    input.drive.power = w.movement.Value[0];
                }

                if(w.virtualJoystick.ispressed)
                {
                    input.drive.x = w.virtualJoystick.diff_X;
                    input.drive.y = w.virtualJoystick.diff_Y;
                    w.ui->horizontalSlider_x_drive->setSliderPosition(w.virtualJoystick.diff_X);
                    w.ui->horizontalSlider_y_drive->setSliderPosition(w.virtualJoystick.diff_Y);
                }
                else
                {
                    w.ui->pushButton_joystick->move( w.virtualJoystick.start_pos_X, w.virtualJoystick.start_pos_Y);
                }
                if(w.ui->horizontalSlider_x_drive->isSliderDown() || w.ui->horizontalSlider_y_drive->isSliderDown())
                {
                    input.drive.x = w.movement.Value[1];
                    input.drive.y = w.movement.Value[2];
                    w.ui->pushButton_joystick->move( w.virtualJoystick.start_pos_X+w.movement.Value[1], w.virtualJoystick.start_pos_Y-w.movement.Value[2]);
                }
            }
            else
            {
                w.ui->horizontalSlider_x_drive->setSliderPosition(0);
                w.ui->horizontalSlider_y_drive->setSliderPosition(0);
                w.ui->horizontalSlider_power_drive->setSliderPosition(0);
            }

            for(int joystickNumber = 0; joystickNumber< numJoysticks; joystickNumber++)
            {
                if(w.ui->comboBox_drive_control->currentIndex() == joystickNumber+1)
                {
                    joysticks[joystickNumber]->poll(&joystickState[joystickNumber]);
                    physicalJoystickDrivePower = ((joystickState[joystickNumber].rglSlider[0]/physicalJoystickMaxValue)*100-100)*-1;
                    physicalJoystickDriveX = (joystickState[joystickNumber].lX/physicalJoystickMaxValue-0.50)*200;
                    physicalJoystickDriveY = (joystickState[joystickNumber].lY/physicalJoystickMaxValue-0.50)*-200;

                    input.drive.x = physicalJoystickDriveX;
                    input.drive.y = physicalJoystickDriveY;
                    input.drive.power = physicalJoystickDrivePower;
                    w.ui->horizontalSlider_power_drive->setSliderPosition(input.drive.power);
                    w.ui->horizontalSlider_x_drive->setSliderPosition(input.drive.x);
                    w.ui->horizontalSlider_y_drive->setSliderPosition(input.drive.y);
                    w.ui->pushButton_joystick->move( w.virtualJoystick.start_pos_X+physicalJoystickDriveX, w.virtualJoystick.start_pos_Y-physicalJoystickDriveY);
                }
            }

            if(w.ui->comboBox_arm_1->currentIndex() == w.buttonFunction)
            {
                w.ui->pushButton_button_function_arm_1->setStyleSheet("background-color: rgba(0, 255, 123, 100); color: grey; color:grey");
            }
            else
            {
                w.ui->pushButton_button_function_arm_1->setStyleSheet("background-color: rgba(235, 0, 0, 150)");
            }
            if(w.ui->comboBox_arm_2->currentIndex() == w.buttonFunction)
            {
                w.ui->pushButton_button_function_arm_2->setStyleSheet("background-color: rgba(0, 255, 123, 100); color: grey");
            }
            else
            {
                w.ui->pushButton_button_function_arm_2->setStyleSheet("background-color: rgba(235, 0, 0, 150)");
            }
            if(w.ui->comboBox_arm_3->currentIndex() == w.buttonFunction)
            {
                w.ui->pushButton_button_function_arm_3->setStyleSheet("background-color: rgba(0, 255, 123, 100); color: grey");
            }
            else
            {
                w.ui->pushButton_button_function_arm_3->setStyleSheet("background-color: rgba(235, 0, 0, 150)");
            }
            if(w.ui->comboBox_arm_4->currentIndex() == w.buttonFunction)
            {
                w.ui->pushButton_button_function_arm_4->setStyleSheet("background-color: rgba(0, 255, 123, 100); color: grey");
            }
            else
            {
                w.ui->pushButton_button_function_arm_4->setStyleSheet("background-color: rgba(235, 0, 0, 150)");
            }
            if(w.ui->comboBox_arm_5->currentIndex() == w.buttonFunction)
            {
                w.ui->pushButton_button_function_arm_5->setStyleSheet("background-color: rgba(0, 255, 123, 100); color: grey");
            }
            else
            {
                w.ui->pushButton_button_function_arm_5->setStyleSheet("background-color: rgba(235, 0, 0, 150)");
            }
            if(w.ui->comboBox_arm_6->currentIndex() == w.buttonFunction)
            {
                w.ui->pushButton_button_function_arm_6->setStyleSheet("background-color: rgba(0, 255, 123, 100); color: grey");
            }
            else
            {
                w.ui->pushButton_button_function_arm_6->setStyleSheet("background-color: rgba(235, 0, 0, 150)");
            }

            connection.adress = w.uiElements.adress;
            connection.port = w.uiElements.port;

            bytesSentInFrame = connection.sendFrame((connection.createFrame(frame, drive.createFrameDrive(input.drive.x, input.drive.y, input.drive.power, wheelSpeeds),arm.createFrameArm(input.arm.x, input.arm.y, input.arm.z, physicalJoystickButtonPressed, input.arm.power, w.buttonFunction, motorSpeeds))),connection.adress,connection.port);

            framesSent+= bytesSentInFrame;
            framesReceived+=connection.readFrame(frameReceived);

            if(bytesSentInFrame != 0)
            {
                w.ui->label_frames_sent_count->setStyleSheet("QLabel { background-color : rgba(0, 255, 123, 100)}");
            }
            else
            {
                w.ui->label_frames_sent_count->setStyleSheet("QLabel { background-color : rgba(235, 0, 0, 150);}");
            }

            if(framesReceived != framesReceivedOld)
            {
                w.ui->label_frames_received_count->setStyleSheet("QLabel { background-color : rgba(0, 255, 123, 100)}");
                w.ui->label_battery_voltage->setText(QString::number(frameReceived.toFloat()));
                cyclesFromLastFrameReceived = 0;
            }
            else if(cyclesFromLastFrameReceived <= 100)
            {
                cyclesFromLastFrameReceived++;
            }
            else
            {
                w.ui->label_frames_received_count->setStyleSheet("QLabel { background-color : rgba(235, 0, 0, 150);}");
            }

            w.ui->label_frames_sent_count->setText(QString::number(framesSent));
            w.ui->label_frames_received_count->setText(QString::number(framesReceived));

            framesReceivedOld = framesReceived;

            w.ui->progressBar_wheel_left_front->setValue(wheelSpeeds[0]);
            w.ui->progressBar_wheel_left_middle->setValue(wheelSpeeds[1]);
            w.ui->progressBar_wheel_left_back->setValue(wheelSpeeds[2]);
            w.ui->progressBar_wheel_right_front->setValue(wheelSpeeds[3]);
            w.ui->progressBar_wheel_right_middle->setValue(wheelSpeeds[4]);
            w.ui->progressBar_wheel_right_back->setValue(wheelSpeeds[5]);
        });

        uiTimer.start(1000 / 60);



    return a.exec();
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSinglePointEvent>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <vector>
#include <QDebug>
#include "mapmodule.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);

        //tworzenie grupy widokowej nr 6
        virtualJoystick.start_pos_X = ui->groupBox_6->x() +  (ui->groupBox_6->width()- ui->pushButton_joystick->width())/2;
        virtualJoystick.start_pos_Y = ui->groupBox_6->y() +  (ui->groupBox_6->height() - ui->pushButton_joystick->height())/2;
        ui->pushButton_joystick->move( virtualJoystick.start_pos_X, virtualJoystick.start_pos_Y);

        //wyłącza automatyczne dodawanie kolumny id(już jest ID zrobiona przezemnie)
        ui->tableWidget_nav->verticalHeader()->setVisible(false);

        //podpięcie mapki do robienia cudów
        mapmodule = new MapModule(this);
        ui->graphicsView->setScene(mapmodule);

        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        scale.viewtransform = ui->graphicsView->transform();
        scale.scale = scale_enum::m1;


}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->groupBox_6 && (event->type() == QEvent::MouseButtonPress) &&  isGroupBox6 == false )
    {
        isGroupBox6 = true;
        mouseevent = static_cast<QMouseEvent *>(event);
        joystickMove(mouseevent);
        QObject::eventFilter(object, event);
        return true;
    }

    if( (event->type() == QEvent::MouseMove) && isGroupBox6 == true )
    {
        mouseevent = static_cast<QMouseEvent *>(event);
        joystickMove(mouseevent);
        QObject::eventFilter(object, event);
        return true;
    }

    if(event->type() == QEvent::MouseButtonRelease && isGroupBox6 == true)
    {
        isGroupBox6 = false;
        mouseevent = static_cast<QMouseEvent *>(event);
        joystickRelease(mouseevent);
        QObject::eventFilter(object, event);
        return true;
    }
    if(object == ui->graphicsView && event->type() == QEvent::MouseButtonPress)//event->type() == QEvent::MouseButtonPress &&)
        {

            int temp = mapmodule->choosePoint(ui->graphicsView->mapToScene(ui->graphicsView->mapFromGlobal(QCursor::pos())),ui->graphicsView->transform());

            if(temp >= 0)
            {
                navigation.choosen_index = temp;
                ui->labelChoosenIndex->setText(QString::number(navigation.choosen_index));
                ui->tableWidget_nav->setCurrentCell(navigation.choosen_index,0);
            }

        }
        QObject::eventFilter(object, event);
        return false;
}

void MainWindow::joystickMove(QMouseEvent *event)
{
    //pobiera gdzie aktuanie jest kursor i odpowiednio modyfikuje tak dane żeby potem środek przycisku pojawił się na czubku kursora
    virtualJoystick.mouse_pos_X = event->position().x() - (ui->pushButton_joystick->width()/2);
    virtualJoystick.mouse_pos_Y = event->position().y() - ui->pushButton_joystick->height();

    //sprawdza czy kursor myszki znajduje się w obramowaniu groupBoxa
    if( ui->groupBox_6->x() <= virtualJoystick.mouse_pos_X &&  virtualJoystick.mouse_pos_X <=  (ui->groupBox_6->x() +  ui->groupBox_6->width()- ui->pushButton_joystick->width()))
    {
        if(ui->groupBox_6->y() <=  virtualJoystick.mouse_pos_Y &&   virtualJoystick.mouse_pos_Y <=  (ui->groupBox_6->y() +  ui->groupBox_6->height() - ui->pushButton_joystick->height()))
        {
           virtualJoystick.diff_X = virtualJoystick.mouse_pos_X - virtualJoystick.start_pos_X;
           virtualJoystick.diff_Y = -(virtualJoystick.mouse_pos_Y - virtualJoystick.start_pos_Y);
            virtualJoystick.ispressed = true;
            ui->pushButton_joystick->move( virtualJoystick.mouse_pos_X, virtualJoystick.mouse_pos_Y);
            return;
        }
    }

    //jak jest klikniety boc ale kursor wyjechał poza obrys ramki w osi Y to blokuje wzrost na osi Y i tylko aktualizuje oś X
    if( ui->groupBox_6->x() <= virtualJoystick.mouse_pos_X && virtualJoystick.mouse_pos_X <= (ui->groupBox_6->x() + ui->groupBox_6->width() - ui->pushButton_joystick->width() ) && virtualJoystick.ispressed == true)
    {
        ui->pushButton_joystick->move( virtualJoystick.mouse_pos_X, ui->pushButton_joystick->y());
        virtualJoystick.diff_X = virtualJoystick.mouse_pos_X - virtualJoystick.start_pos_X;
        return;
    }

    //jak jest klikniety boc ale kursor wyjechał poza obrys ramki w osi X to blokuje wzrost na osi X i tylko aktualizuje oś Y
    if(ui->groupBox_6->y() <=  virtualJoystick.mouse_pos_Y &&   virtualJoystick.mouse_pos_Y <=  (ui->groupBox_6->y() +  ui->groupBox_6->height() - ui->pushButton_joystick->height()) && virtualJoystick.ispressed == true)
    {
        ui->pushButton_joystick->move( ui->pushButton_joystick->x(), virtualJoystick.mouse_pos_Y);
       virtualJoystick.diff_Y = -(virtualJoystick.mouse_pos_Y - virtualJoystick.start_pos_Y);
        return;
    }
}

void MainWindow::joystickRelease(QMouseEvent *event)
{
    //jeśli przycik myszki jest puszczony to gałka jysticka wrca na pozycję 0,0 relatywnie do srodka groupBoxa
    if(virtualJoystick.ispressed == true)
    {
        ui->pushButton_joystick->move(virtualJoystick.start_pos_X, virtualJoystick.start_pos_Y);

        virtualJoystick.ispressed = false;
        virtualJoystick.diff_X = 0;
        virtualJoystick.diff_Y = 0;

        ui->horizontalSlider_x_drive->setSliderPosition(0);
        ui->horizontalSlider_y_drive->setSliderPosition(0);
    }
}

void MainWindow::on_pushButtonUnZoom_clicked()
{
    //zaczyna od zerowej transformacji

    switch(scale.scale)
    {
        case scale_enum::m1:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m10;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("10m");
            ui->graphicsView->scale(0.1,0.1);
            break;
        }
        case scale_enum::m10:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m50;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("50m");
            ui->graphicsView->scale(0.02,0.02);
            break;
        }
        case scale_enum::m50:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m100;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("50m");
            ui->graphicsView->scale(0.01,0.01);
            break;
        }
        case scale_enum::m100:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m500;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("50m");
            ui->graphicsView->scale(0.005,0.005);
            break;
        }
        case scale_enum::m500:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m1000;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("100m");
            ui->graphicsView->scale(0.001,0.001);
            break;

        }

        case scale_enum::m1000:
        {
            break;
        }

        default:
        {
            break;
        }
    }
}

void MainWindow::on_pushButtonZoom_clicked()
{
    //zaczyna od zerowej transformacji


    switch(scale.scale)
    {

        case scale_enum::m1:
        {
            ui->label_scale->setText("1m");
            break;
        }
        case scale_enum::m10:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m1;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("1m");
            ui->graphicsView->scale(1,1);
            break;
        }
        case scale_enum::m50:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m10;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("10m");
            ui->graphicsView->scale(0.1,0.1);
            break;
        }
        case scale_enum::m100:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m50;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("50m");
            ui->graphicsView->scale(0.02,0.02);
            break;
        }
        case scale_enum::m500:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m100;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("50m");
            ui->graphicsView->scale(0.01,0.01);
            break;
        }
        case scale_enum::m1000:
        {
            ui->graphicsView->resetTransform();
            scale.scale = scale_enum::m500;
            mapmodule->scale(scale.scale);
            ui->label_scale->setText("50m");
            ui->graphicsView->scale(0.005,0.005);
            break;
        }

        default:
        {
            break;
        }
    }
}

void MainWindow::on_pushButtonSend_clicked()
{
    mapmodule->UpdatePosition(ui->lineEditPosXRover->text().toDouble(),ui->lineEditPosYRover->text().toDouble());
    ui->graphicsView->centerOn(mapmodule->size_of_map/2,mapmodule->size_of_map/2);
}


void MainWindow::on_pushButtonRotate_clicked()
{
    mapmodule->rover.rotate(ui->lineEditRotate->text().toInt());
}

void MainWindow::on_horizontalSlider_power_drive_valueChanged(int value)
{
    ui->spinBox_power_drive->setValue(value);
    movement.Value[0] = value;
}


void MainWindow::on_horizontalSlider_x_drive_valueChanged(int value)
{
    movement.Value[1] = value;
    ui->label_x_drive->setText(QString::number(value));
}

void MainWindow::on_horizontalSlider_y_drive_valueChanged(int value)
{
    movement.Value[2] = value;
    ui->label_y_drive->setText(QString::number(value));
}

void MainWindow::on_horizontalSlider_x_drive_sliderReleased()
{
    movement.Value[1] = 0;
    ui->horizontalSlider_x_drive->setSliderPosition(movement.Value[1]);
    ui->pushButton_joystick->move( virtualJoystick.start_pos_X, virtualJoystick.start_pos_Y);
}

void MainWindow::on_horizontalSlider_y_drive_sliderReleased()
{
    movement.Value[2] = 0;
    ui->horizontalSlider_y_drive->setSliderPosition(movement.Value[2]);
    ui->pushButton_joystick->move( virtualJoystick.start_pos_X, virtualJoystick.start_pos_Y);
}

void MainWindow::on_comboBox_1_currentTextChanged(const QString &arg1)
{
    if(arg1 == "--None--") buttonFunction = Arm::buttonFunction::none;
    else if(arg1 == "First Segment") buttonFunction = Arm::buttonFunction::first;
    else if(arg1 == "Second Segment") buttonFunction = Arm::buttonFunction::second;
    else if(arg1 == "Third Segment") buttonFunction = Arm::buttonFunction::third;
    else if(arg1 == "Jaws") buttonFunction = Arm::buttonFunction::jaws;
    else if(arg1 == "All") buttonFunction = Arm::buttonFunction::all;
    else if(arg1 == "Inverse Kinematics") buttonFunction = Arm::buttonFunction::inverseKinematics;
}

void MainWindow::on_spinBox_power_drive_valueChanged(int arg1)
{
    ui->horizontalSlider_power_drive->setSliderPosition(arg1);
}

void MainWindow::on_horizontalSlider_power_arm_valueChanged(int value)
{
    ui->spinBox_power_arm->setValue(value);
}


void MainWindow::on_horizontalSlider_x_arm_valueChanged(int value)
{
     ui->label_x_arm->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_y_arm_valueChanged(int value)
{
    ui->label_y_arm->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_z_arm_valueChanged(int value)
{
    ui->label_z_arm->setText(QString::number(value));
}

//--------------------------------------------PLACEHOLDER------------------------------------------------------------

void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_button_function_arm_1_clicked()
{
    //buttonFunction = Arm::buttonFunction::first;

    switch(ui->comboBox_arm_1->currentIndex())
    {
    case 0:
        buttonFunction = Arm::buttonFunction::none;
        break;
    case 1:
        buttonFunction = Arm::buttonFunction::first;
        break;
    case 2:
        buttonFunction = Arm::buttonFunction::second;
        break;
    case 3:
        buttonFunction = Arm::buttonFunction::third;
        break;
    case 4:
        buttonFunction = Arm::buttonFunction::jaws;
        break;
    case 5:
        buttonFunction = Arm::buttonFunction::all;
        break;
    case 6:
        buttonFunction = Arm::buttonFunction::inverseKinematics;
        break;
    }
}


void MainWindow::on_pushButton_button_function_arm_2_clicked()
{
    switch(ui->comboBox_arm_2->currentIndex())
    {
    case 0:
        buttonFunction = Arm::buttonFunction::none;
        break;
    case 1:
        buttonFunction = Arm::buttonFunction::first;
        break;
    case 2:
        buttonFunction = Arm::buttonFunction::second;
        break;
    case 3:
        buttonFunction = Arm::buttonFunction::third;
        break;
    case 4:
        buttonFunction = Arm::buttonFunction::jaws;
        break;
    case 5:
        buttonFunction = Arm::buttonFunction::all;
        break;
    case 6:
        buttonFunction = Arm::buttonFunction::inverseKinematics;
        break;
    }
}


void MainWindow::on_pushButton_button_function_arm_3_clicked()
{
    switch(ui->comboBox_arm_3->currentIndex())
    {
    case 0:
        buttonFunction = Arm::buttonFunction::none;
        break;
    case 1:
        buttonFunction = Arm::buttonFunction::first;
        break;
    case 2:
        buttonFunction = Arm::buttonFunction::second;
        break;
    case 3:
        buttonFunction = Arm::buttonFunction::third;
        break;
    case 4:
        buttonFunction = Arm::buttonFunction::jaws;
        break;
    case 5:
        buttonFunction = Arm::buttonFunction::all;
        break;
    case 6:
        buttonFunction = Arm::buttonFunction::inverseKinematics;
        break;
    }
}


void MainWindow::on_pushButton_button_function_arm_4_clicked()
{
    switch(ui->comboBox_arm_4->currentIndex())
    {
    case 0:
        buttonFunction = Arm::buttonFunction::none;
        break;
    case 1:
        buttonFunction = Arm::buttonFunction::first;
        break;
    case 2:
        buttonFunction = Arm::buttonFunction::second;
        break;
    case 3:
        buttonFunction = Arm::buttonFunction::third;
        break;
    case 4:
        buttonFunction = Arm::buttonFunction::jaws;
        break;
    case 5:
        buttonFunction = Arm::buttonFunction::all;
        break;
    case 6:
        buttonFunction = Arm::buttonFunction::inverseKinematics;
        break;
    }
}


void MainWindow::on_pushButton_button_function_arm_5_clicked()
{
    switch(ui->comboBox_arm_5->currentIndex())
    {
    case 0:
        buttonFunction = Arm::buttonFunction::none;
        break;
    case 1:
        buttonFunction = Arm::buttonFunction::first;
        break;
    case 2:
        buttonFunction = Arm::buttonFunction::second;
        break;
    case 3:
        buttonFunction = Arm::buttonFunction::third;
        break;
    case 4:
        buttonFunction = Arm::buttonFunction::jaws;
        break;
    case 5:
        buttonFunction = Arm::buttonFunction::all;
        break;
    case 6:
        buttonFunction = Arm::buttonFunction::inverseKinematics;
        break;
    }
}


void MainWindow::on_pushButton_button_function_arm_6_clicked()
{
    switch(ui->comboBox_arm_6->currentIndex())
    {
    case 0:
        buttonFunction = Arm::buttonFunction::none;
        break;
    case 1:
        buttonFunction = Arm::buttonFunction::first;
        break;
    case 2:
        buttonFunction = Arm::buttonFunction::second;
        break;
    case 3:
        buttonFunction = Arm::buttonFunction::third;
        break;
    case 4:
        buttonFunction = Arm::buttonFunction::jaws;
        break;
    case 5:
        buttonFunction = Arm::buttonFunction::all;
        break;
    case 6:
        buttonFunction = Arm::buttonFunction::inverseKinematics;
        break;
    }
}

//--------------------------------------------PLACEHOLDER------------------------------------------------------------

void MainWindow::on_lineEdit_IP_adress_editingFinished()
{

}

void MainWindow::on_lineEdit_IP_adress_textChanged(const QString &arg1)
{
    uiElements.adress = arg1;
}

void MainWindow::on_lineEdit_port_textChanged(const QString &arg1)
{
    uiElements.port = arg1.toInt();
}


void MainWindow::on_pushButton_stop_clicked()
{

}


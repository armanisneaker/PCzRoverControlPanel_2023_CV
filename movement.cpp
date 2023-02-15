#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::on_horizontalSlider_power_valueChanged(int value)
{
    ui->spinBox_power->setValue(value);
    movement.Value[0] = value;
    ui->label_10->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_x_valueChanged(int value)
{

    movement.Value[1] = value;
    ui->label_xx->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_y_valueChanged(int value)
{

    movement.Value[2] = value;
    ui->label_yy->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_z_valueChanged(int value)
{

    movement.Value[3] = value;
    ui->label_zz->setText(QString::number(value));
}

void MainWindow::on_spinBox_power_valueChanged(int arg1)
{
    ui->horizontalSlider_power->setValue(arg1);
    movement.Value[0] = arg1;
    ui->label_10->setText(QString::number(arg1));
}

void MainWindow::on_comboBox_1_currentIndexChanged(int index)
{
    movement.Combobox[0] = index;
    ui->label_10->setText(QString::number(index));
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    movement.Combobox[1] = index;
    ui->label_11->setText(QString::number(index));
}


void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    movement.Combobox[2] = index;
    ui->label_12->setText(QString::number(index));
}


void MainWindow::on_comboBox_4_currentIndexChanged(int index)
{
    movement.Combobox[3] = index;
    ui->label_13->setText(QString::number(index));
}


void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    movement.Combobox[4] = index;
    ui->label_14->setText(QString::number(index));
}


void MainWindow::on_comboBox_6_currentIndexChanged(int index)
{
    movement.Combobox[5] = index;
    ui->label_15->setText(QString::number(index));
}

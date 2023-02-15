#ifndef DRIVE_H
#define DRIVE_H

#pragma once

#include <QObject>
#include <QIODevice>
#include <QDebug>

class Drive : public QObject
{
    Q_OBJECT
public:

    explicit Drive(QObject *parent = 0);

    double joyX = 0.00;
    double joyY = 0.00;
    int powerOnWheels = 0; // Przedział prędkości kół to <6400;0> gdzie <max_przód;max_tył>. Maksymalną moc nadajemy w przedziale <0;3200>.

    int wheelSpeedLeft = 0;
    int wheelSpeedRight = 0;

    double radius = 0;
    double width = 0;
    double one_quarter_circuit[2]{0.00, 0.00}; //tab[0] to lewa strona łazika tab[1] to prawa storna
    double time = 0.00;

    double deadzoneX = 0;
    double deadzoneY = 0;

    int16_t wheelSpeedLeft1 = 3200;
    int16_t wheelSpeedLeft2 = 3200;
    int16_t wheelSpeedLeft3 = 3200;

    int16_t wheelSpeedRight1 = 3200;
    int16_t wheelSpeedRight2 = 3200;
    int16_t wheelSpeedRight3 = 3200;

    QByteArray frame;

    QByteArray createFrameDrive( double X, double Y, int powerSlider, int *wheelSpeeds);
private:

signals:

public slots:


};

#endif // DRIVE_H

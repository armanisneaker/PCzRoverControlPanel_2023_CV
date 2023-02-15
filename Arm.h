#ifndef ARM_H
#define ARM_H

#pragma once

#include <QObject>
#include <QIODevice>
#include <QDebug>

class Arm : public QObject
{
public:
    explicit Arm(QObject *parent = 0);

    double joyX = 0.00;
    double joyY = 0.00;
    double joyZ = 0.00;

    int powerOnMotors = 0;

    double deadzone = 0.15;

    int motorX = 0;
    int motorY = 0;
    int motorZ = 0;

    int16_t motorBase = 11392;
    int16_t motorSegment2Middle = 11392;
    int16_t motorSegment1Bottom = 11392;
    int16_t motorJawsClench = 11392;
    int16_t motorJawsRotation = 11392;
    int16_t motorJawsPosition = 11392;

    QByteArray frame;

    enum buttonFunction
    {
        none,
        first,
        second,
        third,
        jaws,
        all,
        inverseKinematics
    };

    QByteArray createFrameArm(int X, int Y, int Z, int buttonPressed, int powerSlider, buttonFunction buttonFunction, int* motorSpeeds);
};

#endif // ARM_H

#include "Arm.h"

Arm::Arm(QObject *parent) : QObject(parent)
{

}

QByteArray Arm::createFrameArm(int X, int Y, int Z, int buttonPressed, int powerSlider, buttonFunction buttonFunction, int*motorSpeeds)
{
    frame.QByteArray::clear();

//    if(X>=99) X=99;
//    if(X<=-99) X=-99;
//    if(Y>=99) Y=99;
//    if(Y<=-99) Y=-99;
//    if(Z>=99) Z=99;
//    if(Z<=-99) Z=-99;

    joyX = X/100.00;
    joyY = Y/100.00;
    joyZ = Z/100.00;

    powerOnMotors = 100*powerSlider;

    if(!(joyX >= -deadzone && joyX <= deadzone && joyY >= -deadzone && joyY <= deadzone))
    {
        motorX = joyX*powerOnMotors;
        motorY = joyY*powerOnMotors;
        if(!(joyZ >= -deadzone && joyZ <= deadzone))
        {
            motorZ = joyZ*powerOnMotors;
        }
        else
        {
            motorZ = 0;
        }
    }
    else
    {
        motorX = 0;
        motorY = 0;
        if(!(joyZ >= -deadzone && joyZ <= deadzone))
        {
             motorZ = joyZ*powerOnMotors;
        }
        else
        {
            motorZ = 0;
        }
    }


    switch(buttonFunction)
    {
    case none:
        break;
    case first:
        motorBase = motorZ + 11392;
        motorSegment1Bottom = motorY + 11392;
        //motorJawsRotation = motorX+11392;
        break;
    case second:
        motorBase = motorZ + 11392;
        motorSegment2Middle = motorY+11392;
        //motorJawsRotation = -motorX+11392;
        break;
    case third:
        motorBase = motorZ + 11392;
        motorJawsPosition = motorY+11392;
        motorJawsRotation = -motorX+11392;
        break;
    case jaws:
        motorBase = motorZ + 11392;
        motorJawsRotation = -motorX+11392;
        motorJawsClench = 2*motorY+11392;
        break;
    case all:
        motorBase = motorZ + 11392;
        switch(buttonPressed)
        {
        case 0:
            motorJawsPosition = -motorY+11392;
            motorJawsClench = 11392;
            motorSegment2Middle = 11392;
            motorSegment1Bottom = 11392;
            break;
        case 1:
            motorSegment1Bottom = motorY+11392;
            motorJawsPosition = 11392;
            motorJawsClench = 11392;
            motorSegment2Middle = 11392;
            break;
        case 2:
            motorSegment2Middle = -motorY+11392;
            motorSegment1Bottom = 11392;
            motorJawsPosition = 11392;
            motorJawsClench = 11392;
            break;
        case 3:
            motorJawsClench = 10*motorY+11392;
            motorSegment2Middle = 11392;
            motorSegment1Bottom = 11392;
            motorJawsPosition = 11392;
            break;
        default:
            motorSegment1Bottom = motorY+11392;
            motorSegment2Middle = -motorY+11392;
            motorJawsPosition = 11392;
            motorJawsClench = 11392;
            break;
        }
        motorJawsRotation = -motorX+11392;
        break;
    default:
        break;
    }

    if(motorJawsClench>22784) motorJawsClench = 22784;
    if(motorJawsClench<-22784) motorJawsClench = -22784;

    QDataStream stream(&frame, QIODevice::WriteOnly);
    stream << motorBase << motorSegment2Middle << motorSegment1Bottom <<motorJawsClench << motorJawsRotation << motorJawsPosition;

    //qDebug() << motorBase << motorSegment2Middle << motorSegment1Bottom <<motorJawsClench << motorJawsRotation << motorJawsPosition;
    return frame;
}


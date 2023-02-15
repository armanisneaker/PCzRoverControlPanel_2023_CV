#include "Drive.h"

Drive::Drive(QObject *parent) : QObject(parent)
{
    //Do fukcji obliczajacej jazde
    radius = 15.0;
    width = 1.1;
    time = 0.00;

    //Deadzone'y joysticka
    deadzoneX = 0.15;
    deadzoneY = 0.15;
}

QByteArray Drive::createFrameDrive( double X, double Y, int powerSlider, int *wheelSpeeds)
{
    frame.QByteArray::clear();

    if(X>=99) X=99;
    if(X<=-99) X=-99;
    joyX = X/100.00;
    joyY = Y/100.00;

    powerOnWheels = 32*powerSlider*joyY; // Przedział prędkości kół to <6400;0> gdzie <max_przód;max_tył>. Maksymalną moc nadajemy w przedziale <0;3200>.

    //Algorytm jazdy oparty na rysowaniu dwoch okregow - dla lewych i prawych kol lazika. Funkcja liczy o ile jedna strona musi wyprzedzac druga
    //aby wykonac porzadany skret lub obrot lazikiem.
    //if ((joyY < -deadzoneY && joyY > deadzoneY) || (joyX > -deadzoneX && joyX < deadzoneX))
    {
        if(joyY <= 0.25 && joyY >=-0.25)
        {
            if(joyX>-0.15 && joyX<0.15)
            {
                wheelSpeedRight = 0;
                wheelSpeedLeft = 0;
            }
            else if(joyX<-0.00)
            {
                wheelSpeedRight = -32*powerSlider*joyX;
                wheelSpeedLeft = 32*powerSlider*joyX;
            }
            else if(joyX>0.00)
            {
                wheelSpeedRight = -32*powerSlider*joyX;
                wheelSpeedLeft = 32*powerSlider*joyX;
            }

            //Bo moce na kolach sa <0;6400>
            wheelSpeedLeft+=3200;
            wheelSpeedRight+=3200;

        }
        else
        {
            if(joyX >= deadzoneX && joyX <= 1.00)//skręt w prawo
            {
                one_quarter_circuit[1] = (((radius - (radius * (joyX))) ) * M_PI) / 2;
                one_quarter_circuit[0] = (((radius - (radius * (joyX))) - width) * M_PI) / 2;
                wheelSpeedLeft = (powerOnWheels);
                time = one_quarter_circuit[1] / wheelSpeedLeft;
                wheelSpeedRight = one_quarter_circuit[0] / time;
            }
            else if(joyX <= -deadzoneX && joyX >= -1.00) //skret w lewo
            {
                one_quarter_circuit[0] = (((radius + (radius * (joyX))) ) * M_PI) / 2;
                one_quarter_circuit[1] = (((radius + (radius * (joyX))) - width) * M_PI) / 2;
                wheelSpeedRight = (powerOnWheels);
                time = one_quarter_circuit[0] / wheelSpeedRight;
                wheelSpeedLeft = (one_quarter_circuit[1] / time);
            }
            else if (joyX > -deadzoneX && joyX < deadzoneX) //nie ma wychylenia więc tylko jedzie przód albo tył
            {
                wheelSpeedLeft = powerOnWheels;
                wheelSpeedRight = powerOnWheels;
            }

            //Bo moce na kolach sa <0;6400>
            wheelSpeedLeft+=3200;
            wheelSpeedRight+=3200;

            //Obcinamy wyniki funkcji obliczajacej predkosci
            if(joyY > 0)
            {
                if(wheelSpeedLeft<6400-wheelSpeedRight) wheelSpeedLeft = 6400-wheelSpeedRight;
                if(wheelSpeedRight<6400-wheelSpeedLeft) wheelSpeedRight = 6400-wheelSpeedLeft;
                if(wheelSpeedLeft>powerOnWheels+3200) wheelSpeedLeft = powerOnWheels+3200;
                if(wheelSpeedRight<3200-powerOnWheels) wheelSpeedRight = 3200-powerOnWheels;
            }
            if(joyY <0)
            {
                if(wheelSpeedLeft>6400-wheelSpeedRight) wheelSpeedLeft = 6400-wheelSpeedRight;
                if(wheelSpeedRight>6400-wheelSpeedLeft) wheelSpeedRight = 6400-wheelSpeedLeft;
                if(wheelSpeedLeft<powerOnWheels+3200) wheelSpeedLeft = powerOnWheels+3200;
                if(wheelSpeedRight>3200-powerOnWheels) wheelSpeedRight = 3200-powerOnWheels;
            }
        }

    }

    // Wszystkie koła po danej stronie mają te same prędkości - po testach zobaczymy czy trzeba dywersyfikować.
    wheelSpeedLeft1 = wheelSpeedLeft;
    wheelSpeedLeft2 = wheelSpeedLeft;
    wheelSpeedLeft3 = wheelSpeedLeft;

    wheelSpeedRight1 = wheelSpeedRight;
    wheelSpeedRight2 = wheelSpeedRight;
    wheelSpeedRight3 = wheelSpeedRight;

    //Pakujemy ramke
    QDataStream stream(&frame, QIODevice::WriteOnly);
    stream << wheelSpeedRight1 << wheelSpeedRight2 << wheelSpeedRight3 << wheelSpeedLeft1 << wheelSpeedLeft2 << wheelSpeedLeft3;

    //qDebug() << "Power on wheels: " <<powerOnWheels+3200 << " = " << powerSlider << "%";
    //qDebug() << "Left Wheel: " << wheelSpeedLeft << "Right Wheel: " << wheelSpeedRight;

    //Aby odczytac moce spoza funkcji
    wheelSpeeds[0] = wheelSpeedLeft;
    wheelSpeeds[1] = wheelSpeedLeft;
    wheelSpeeds[2] = wheelSpeedLeft;
    wheelSpeeds[3] = wheelSpeedRight;
    wheelSpeeds[4] = wheelSpeedRight;
    wheelSpeeds[5] = wheelSpeedRight;

    return frame;
}

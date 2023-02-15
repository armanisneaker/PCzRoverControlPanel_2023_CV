#ifndef INPUT_H
#define INPUT_H

#pragma once

#include <QObject>
#include "Arm.h"

class Input : public QObject
{
    Q_OBJECT
public:
    Input();

        struct Drive
        {
            int x{0};
            int y{0};
            int power{0};
        };
        struct Arm
        {
            int x{0};
            int y{0};
            int z{0};
            int power{0};
            ::Arm::buttonFunction buttonFunction = ::Arm::buttonFunction::first;
        };
        Drive drive;
        Arm arm;
};

#endif // INPUT_H

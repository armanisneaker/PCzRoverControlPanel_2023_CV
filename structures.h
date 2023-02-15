#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <QObject>
#include <QGraphicsItem>
#include <QPoint>
#include <QTableWidgetItem>

enum class scale_enum
{
    m1 = 1,
    m10 = 10,
    m50 = 50,
    m100 = 100,
    m500 = 500,
    m1000 = 1000
};


struct Fast_Settings
{
    int clicked = 0;
    std::string combobox[3];
};


struct Navigation
{
    int index_number = 0;
    int choosen_index = 0;
    std::vector<QTableWidgetItem *> itemID;
    std::vector<QTableWidgetItem *> itemRow;
    std::vector<QTableWidgetItem *> itemColumn;
    std::vector<double> pos_X;
    std::vector<double> pos_Y;
};

struct Scale
{
    QTransform viewtransform;
    scale_enum scale;

};





#endif // STRUCTURES_H

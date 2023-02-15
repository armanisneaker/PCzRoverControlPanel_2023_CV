#ifndef ROVER_H
#define ROVER_H

#include <QWidget>
#include <QGraphicsPixmapItem>

class Rover : public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Rover(QGraphicsPixmapItem *parent = nullptr);

signals:

private:

};

#endif // ROVER_H

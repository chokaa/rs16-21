#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "powerups.h"

class Bomb: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bomb(QGraphicsItem * parent=0);
    powerups * powerup;
public slots:
    void explode();
};

#endif // BOMB_H

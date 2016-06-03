#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bomb: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bomb(QGraphicsItem * parent=0);
public slots:
    void explode();
};

#endif // BOMB_H

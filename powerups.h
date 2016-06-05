#ifndef POWERUPS_H
#define POWERUPS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class powerups:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    powerups(QGraphicsItem * parent=0);
};

#endif // POWERUPS_H


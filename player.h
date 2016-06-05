#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

extern int duzina_eksplozije;
extern int tip_powerupa;

class Player:public QObject, public QGraphicsPixmapItem{
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H

#include "bomb.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"

extern Game * game;

Bomb::Bomb(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw the bomb
    setPixmap(QPixmap(":/images/bomb.png"));
}

void Bomb::explode(){
    // TODO timer
}

#include "bomb.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QPixmap>
#include <QLabel>
#include "game.h"

extern Game * game;

Bomb::Bomb(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw the bomb
    setPixmap(QPixmap(":/images/bomb.png"));
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this,SLOT(explode()));
    timer->start(2750);

    QTimer *timer1 = new QTimer(this);
    timer1->setSingleShot(true);
    connect(timer1,SIGNAL(timeout()),this,SLOT(fire()));
    timer1->start(2000);



}

void Bomb::explode(){
    scene()->removeItem(this);
}

void Bomb::fire()
{
    setPixmap(QPixmap(":/images/faja.png"));
    sleep(0);
    moveBy(50,0);
    setPixmap(QPixmap(":/images/faja.png"));
}

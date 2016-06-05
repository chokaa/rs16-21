#include "fire.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QList>
#include "game.h"
#include "bomb.h"


extern Game * game;

Fire::Fire(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/faja.png"));

    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n=colliding_items.size();
    for(int i=0;i<n;++i){
        setPixmap(QPixmap(":/images/bomb.png"));

    }

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this,SLOT(extinguish()));
    timer->start(500);
}

void Fire::extinguish(){
    scene()->removeItem(this);
}

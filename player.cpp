#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bomb.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/osama.jpg"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-50,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 <= 800)
            setPos(x()+50,y());
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0)
            setPos(x(),y()-50);
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 <= 600)
            setPos(x(),y()+50);
    }

    // place bomb with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bomb
        Bomb * bomb = new Bomb();
        bomb->setPos(x(),y());
        scene()->addItem(bomb);
    }

}

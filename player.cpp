#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bomb.h"
#include <typeinfo>
#include "fixedwall.h"
#include "normalwall.h"
#include <QList>
#include <iostream>
#include "powerups.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/osama.jpg"));
}

int duzina_eksplozije=2;

void Player::keyPressEvent(QKeyEvent *event){
    // move the player

    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0 && !scene()->itemAt(x()-50,y(), QTransform()))
            setPos(x()-50,y());
        else if((scene()->itemAt(x()-50,y(), QTransform())))
            if(!((typeid(*(scene()->itemAt(x()-50,y(), QTransform())))) == typeid(fixedWall)) &&
               !((typeid(*(scene()->itemAt(x()-50,y(), QTransform())))) == typeid(normalWall))){
                if((typeid(*(scene()->itemAt(x()-50,y(), QTransform())))) == typeid(powerups)){
                    scene()->removeItem((scene()->itemAt(x()-50,y(), QTransform())));

                }
                setPos(x()-50,y());
                duzina_eksplozije++;
            }
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 <= 800 && !(scene()->itemAt(x()+50,y(), QTransform()))){
                setPos(x()+50,y());
        }
        else if((scene()->itemAt(x()+50,y(), QTransform())))
            if(!((typeid(*(scene()->itemAt(x()+50,y(), QTransform())))) == typeid(fixedWall)) &&
               !((typeid(*(scene()->itemAt(x()+50,y(), QTransform())))) == typeid(normalWall))){
                if((typeid(*(scene()->itemAt(x()+50,y(), QTransform())))) == typeid(powerups)){
                    scene()->removeItem((scene()->itemAt(x()+50,y(), QTransform())));

                }
                setPos(x()+50,y());
                duzina_eksplozije++;
            }
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0 && !scene()->itemAt(x(),y()-50, QTransform()))
            setPos(x(),y()-50);
        else if((scene()->itemAt(x(),y()-50, QTransform())))
            if(!((typeid(*(scene()->itemAt(x(),y()-50, QTransform())))) == typeid(fixedWall)) &&
               !((typeid(*(scene()->itemAt(x(),y()-50, QTransform())))) == typeid(normalWall))){
                if((typeid(*(scene()->itemAt(x(),y()-50, QTransform())))) == typeid(powerups)){
                    scene()->removeItem((scene()->itemAt(x(),y()-50, QTransform())));

                }
                setPos(x(),y()-50);
                duzina_eksplozije++;
            }
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 <= 600 && !scene()->itemAt(x(),y()+50, QTransform()))
            setPos(x(),y()+50);
        else if((scene()->itemAt(x(),y()+50, QTransform())))
            if(!((typeid(*(scene()->itemAt(x(),y()+50, QTransform())))) == typeid(fixedWall)) &&
               !((typeid(*(scene()->itemAt(x(),y()+50, QTransform())))) == typeid(normalWall))){
                if((typeid(*(scene()->itemAt(x(),y()+50, QTransform())))) == typeid(powerups)){
                    scene()->removeItem((scene()->itemAt(x(),y()+50, QTransform())));

                }
                setPos(x(),y()+50);
                duzina_eksplozije++;
            }
    }

    // place bomb with the spacebar
    else if (event->key() == Qt::Key_Space){

        QList<QGraphicsItem *> scene_items = scene()->items();
        int a=0;

        // check whether there is another bomb on the scene
        foreach(QGraphicsItem *item, scene_items){
            if((typeid(*item) == typeid(Bomb)))
                a++;
        }

        // create a bomb if there isnt another bomb present
        if(a==0){
            Bomb * bomb = new Bomb();
            bomb->setPos(x(),y());
            scene()->addItem(bomb);
        }
    }
}

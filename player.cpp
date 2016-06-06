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
#include "fire.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/osama.jpg"));
}
extern int tip_powerupa;

int duzina=2;

void Player::dead(){
    setPixmap(QPixmap(":/images/dead.jpg"));
    this->clearFocus();
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player

    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0 && !scene()->itemAt(x()-50,y(), QTransform()))
            setPos(x()-50,y());

        else if((scene()->itemAt(x()-50,y(), QTransform())))
            if(!((typeid(*(scene()->itemAt(x()-50,y(), QTransform())))) == typeid(fixedWall)) &&
               !((typeid(*(scene()->itemAt(x()-50,y(), QTransform())))) == typeid(Bomb)) &&
               !((typeid(*(scene()->itemAt(x()-50,y(), QTransform())))) == typeid(normalWall))){
                //ulazak u vatru
                if((typeid(*(scene()->itemAt(x()-50,y(), QTransform())))) == typeid(Fire)){
                  setPos(x()-50,y());
                  this->dead();
                }
                if((typeid(*(scene()->itemAt(x()-50,y(), QTransform())))) == typeid(powerups)){
                        if (((powerups*)(scene()->itemAt(x()-50,y(), QTransform())))->redni_broj_powerupa==1){
                        duzina=duzina+1;
                        }
                        if(((powerups*)(scene()->itemAt(x()-50,y(), QTransform())))->redni_broj_powerupa==2){
                        this->broj_bombi++;
                        }
                        scene()->removeItem((scene()->itemAt(x()-50,y(), QTransform())));
                        setPos(x()-50,y());

                }

              }
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 <= 800 && !(scene()->itemAt(x()+50,y(), QTransform()))){
                setPos(x()+50,y());
        }
        else if((scene()->itemAt(x()+50,y(), QTransform())))
            if(!((typeid(*(scene()->itemAt(x()+50,y(), QTransform())))) == typeid(fixedWall)) &&
               !((typeid(*(scene()->itemAt(x()+50,y(), QTransform())))) == typeid(Bomb)) &&
               !((typeid(*(scene()->itemAt(x()+50,y(), QTransform())))) == typeid(normalWall))){
                if((typeid(*(scene()->itemAt(x()+50,y(), QTransform())))) == typeid(powerups)){
                    //ulazak u vatru
                    if((typeid(*(scene()->itemAt(x()+50,y(), QTransform())))) == typeid(Fire)){
                      setPos(x()+50,y());
                      this->dead();
                    }
                    if (((powerups*)(scene()->itemAt(x()+50,y(), QTransform())))->redni_broj_powerupa==1){
                    duzina=duzina+1;
                    }
                    if(((powerups*)(scene()->itemAt(x()+50,y(), QTransform())))->redni_broj_powerupa==2){
                    this->broj_bombi++;
                    }
                    scene()->removeItem((scene()->itemAt(x()+50,y(), QTransform())));
                    setPos(x()+50,y());
                }
            }
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0 && !scene()->itemAt(x(),y()-50, QTransform()))
            setPos(x(),y()-50);
        else if((scene()->itemAt(x(),y()-50, QTransform())))
            if(!((typeid(*(scene()->itemAt(x(),y()-50, QTransform())))) == typeid(fixedWall)) &&
               !((typeid(*(scene()->itemAt(x(),y()-50, QTransform())))) == typeid(Bomb)) &&
               !((typeid(*(scene()->itemAt(x(),y()-50, QTransform())))) == typeid(normalWall))){
                if((typeid(*(scene()->itemAt(x(),y()-50, QTransform())))) == typeid(powerups)){
                    //ulazak u vatru
                    if((typeid(*(scene()->itemAt(x(),y()-50, QTransform())))) == typeid(Fire)){
                      setPos(x(),y()-50);
                      this->dead();
                    }
                    if (((powerups*)(scene()->itemAt(x(),y()-50, QTransform())))->redni_broj_powerupa==1){
                    duzina=duzina+1;
                    }
                    if(((powerups*)(scene()->itemAt(x(),y()-50, QTransform())))->redni_broj_powerupa==2){
                    this->broj_bombi++;
                    }
                    scene()->removeItem((scene()->itemAt(x(),y()-50, QTransform())));
                    setPos(x(),y()-50);
                }
            }
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 <= 600 && !scene()->itemAt(x(),y()+50, QTransform()))
            setPos(x(),y()+50);
        else if((scene()->itemAt(x(),y()+50, QTransform())))
            if(!((typeid(*(scene()->itemAt(x(),y()+50, QTransform())))) == typeid(fixedWall)) &&
               !((typeid(*(scene()->itemAt(x(),y()+50, QTransform())))) == typeid(Bomb)) &&
               !((typeid(*(scene()->itemAt(x(),y()+50, QTransform())))) == typeid(normalWall))){
                if((typeid(*(scene()->itemAt(x(),y()+50, QTransform())))) == typeid(powerups)){
                    //ulazak u vatru
                    if((typeid(*(scene()->itemAt(x(),y()+50, QTransform())))) == typeid(Fire)){
                      setPos(x(),y()+50);
                      this->dead();
                    }
                    if (((powerups*)(scene()->itemAt(x(),y()+50, QTransform())))->redni_broj_powerupa==1){
                    duzina=duzina+1;
                    }
                    if(((powerups*)(scene()->itemAt(x(),y()+50, QTransform())))->redni_broj_powerupa==2){
                    this->broj_bombi++;
                    }
                    scene()->removeItem((scene()->itemAt(x(),y()+50, QTransform())));
                    setPos(x(),y()+50);
                }
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
        if(a<this->broj_bombi){
            Bomb * bomb = new Bomb();
            bomb->setPos(x(),y());
            bomb->duzina_eksplozije=duzina;
            scene()->addItem(bomb);
        }
    }
}

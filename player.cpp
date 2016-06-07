#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bomb.h"
#include <typeinfo>
#include "fixedwall.h"
#include "normalwall.h"
#include <QList>
#include "powerups.h"
#include "fire.h"
#include "game.h"
#include "score.h"

extern Game * game;

Player::Player(int x,QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    this->br=x;
    if(this->br==1)
        setPixmap(QPixmap(":/images/img/p1_dole.png"));
    else if(this->br==2)
        setPixmap(QPixmap(":/images/img/p2_dole.png"));
}


void Player::dead(){
    setPixmap(QPixmap(":/images/dead.jpg"));
    this->clearFocus();
}

void Player::move(int s){

    switch(s){
        case 1:
            if(this->br==1)
                setPixmap(QPixmap(":/images/img/p1_levo.png"));
            else if(this->br==2)
                setPixmap(QPixmap(":/images/img/p2_levo.png"));
            if (pos().x() > 0 && !scene()->itemAt(x()-25,y()+25, QTransform()))
                        setPos(x()-50,y());
                    else if((scene()->itemAt(x()-25,y()+25, QTransform())))
                        if(!((typeid(*(scene()->itemAt(x()-25,y()+25, QTransform())))) == typeid(fixedWall)) &&
                           !((typeid(*(scene()->itemAt(x()-25,y()+25, QTransform())))) == typeid(Bomb)) &&
                           !((typeid(*(scene()->itemAt(x()-25,y()+25, QTransform())))) == typeid(normalWall))){
                            //ulazak u vatru
                            if((typeid(*(scene()->itemAt(x()-25,y()+25, QTransform())))) == typeid(Fire)){
                              setPos(x()-50,y());
                              this->dead();
                            }
                            else if((typeid(*(scene()->itemAt(x()-25,y()+25, QTransform())))) == typeid(powerups)){
                                    if (((powerups*)(scene()->itemAt(x()-25,y()+25, QTransform())))->redni_broj_powerupa==1){
                                    this->duzina_vatre++;
                                    }
                                    if(((powerups*)(scene()->itemAt(x()-25,y()+25, QTransform())))->redni_broj_powerupa==2){
                                    this->broj_bombi++;
                                    }
                                    scene()->removeItem((scene()->itemAt(x()-25,y()+25, QTransform())));
                                    setPos(x()-50,y());

                        }

                      }
            break;
        case 2:
            if(this->br==1)
                setPixmap(QPixmap(":/images/img/p1_desno.png"));
            else if(this->br==2)
                setPixmap(QPixmap(":/images/img/p2_desno.png"));
            if (pos().x() + 100 <= 800 && !(scene()->itemAt(x()+75,y()+25, QTransform()))){
                           setPos(x()+50,y());
                   }
                   else if((scene()->itemAt(x()+75,y()+25, QTransform())))
                       if(!((typeid(*(scene()->itemAt(x()+75,y()+25, QTransform())))) == typeid(fixedWall)) &&
                          !((typeid(*(scene()->itemAt(x()+75,y()+25, QTransform())))) == typeid(Bomb)) &&
                          !((typeid(*(scene()->itemAt(x()+75,y()+25, QTransform())))) == typeid(normalWall))){
                           //ulazak u vatru
                           if((typeid(*(scene()->itemAt(x()+75,y()+25, QTransform())))) == typeid(Fire)){
                             setPos(x()+50,y());
                             this->dead();
                           }
                           else if((typeid(*(scene()->itemAt(x()+75,y()+25, QTransform())))) == typeid(powerups)){

                               if (((powerups*)(scene()->itemAt(x()+75,y()+25, QTransform())))->redni_broj_powerupa==1){
                               this->duzina_vatre++;
                               }
                               if(((powerups*)(scene()->itemAt(x()+75,y()+25, QTransform())))->redni_broj_powerupa==2){
                               this->broj_bombi++;
                               }
                               scene()->removeItem((scene()->itemAt(x()+75,y()+25, QTransform())));
                               setPos(x()+50,y());
                           }
                   }
            break;
        case 3:
            if(this->br==1)
                setPixmap(QPixmap(":/images/img/p1_gore.png"));
            else if(this->br==2)
                setPixmap(QPixmap(":/images/img/p2_gore.png"));
            if (pos().y() > 0 && !scene()->itemAt(x()+25,y()-25, QTransform()))
                       setPos(x(),y()-50);
                   else if((scene()->itemAt(x()+25,y()-25, QTransform())))
                       if(!((typeid(*(scene()->itemAt(x()+25,y()-25, QTransform())))) == typeid(fixedWall)) &&
                          !((typeid(*(scene()->itemAt(x()+25,y()-25, QTransform())))) == typeid(Bomb)) &&
                          !((typeid(*(scene()->itemAt(x()+25,y()-25, QTransform())))) == typeid(normalWall))){
                           //ulazak u vatru
                           if((typeid(*(scene()->itemAt(x()+25,y()-25, QTransform())))) == typeid(Fire)){
                             setPos(x(),y()-50);
                             this->dead();
                           }
                           else if((typeid(*(scene()->itemAt(x()+25,y()-25, QTransform())))) == typeid(powerups)){
                               if (((powerups*)(scene()->itemAt(x()+25,y()-25, QTransform())))->redni_broj_powerupa==1){
                               this->duzina_vatre++;
                               }
                               if(((powerups*)(scene()->itemAt(x()+25,y()-25, QTransform())))->redni_broj_powerupa==2){
                               this->broj_bombi++;
                               }
                               scene()->removeItem((scene()->itemAt(x()+25,y()-25, QTransform())));
                               setPos(x(),y()-50);
                       }
                   }
            break;
        case 4:
                if(this->br==1)
                    setPixmap(QPixmap(":/images/img/p1_dole.png"));
                else if(this->br==2)
                    setPixmap(QPixmap(":/images/img/p2_dole.png"));
                if (pos().y() + 100 <= 600 && !scene()->itemAt(x()+25,y()+75, QTransform()))
                            setPos(x(),y()+50);
                        else if((scene()->itemAt(x()+25,y()+75, QTransform())))
                            if(!((typeid(*(scene()->itemAt(x()+25,y()+75, QTransform())))) == typeid(fixedWall)) &&
                               !((typeid(*(scene()->itemAt(x()+25,y()+75, QTransform())))) == typeid(Bomb)) &&
                               !((typeid(*(scene()->itemAt(x()+25,y()+75, QTransform())))) == typeid(normalWall))){
                                //ulazak u vatru
                                if((typeid(*(scene()->itemAt(x()+25,y()+75, QTransform())))) == typeid(Fire)){
                                  setPos(x(),y()+50);
                                  this->dead();
                                }
                                else if((typeid(*(scene()->itemAt(x()+25,y()+75, QTransform())))) == typeid(powerups)){
                                    if (((powerups*)(scene()->itemAt(x()+25,y()+75, QTransform())))->redni_broj_powerupa==1){
                                    this->duzina_vatre++;
                                    }
                                    if(((powerups*)(scene()->itemAt(x()+25,y()+75, QTransform())))->redni_broj_powerupa==2){
                                    this->broj_bombi++;
                                    }
                                    scene()->removeItem((scene()->itemAt(x()+25,y()+75, QTransform())));
                                    setPos(x(),y()+50);
                            }
                    }
            break;
        case 5:
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
                bomb->duzina_eksplozije=this->duzina_vatre;
                scene()->addItem(bomb);
            }
        break;
    }
}



#include "bomb.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QPixmap>
#include <QLabel>
#include "game.h"
#include "fire.h"
#include "fixedwall.h"
#include "normalwall.h"
#include "powerups.h"
#include <typeinfo>

extern int duzina_eksplozije;

extern Game * game;

Bomb::Bomb(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw the bomb
    setPixmap(QPixmap(":/images/bomb.png"));
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this,SLOT(explode()));
    timer->start(2000);
}

void Bomb::explode(){

    Fire * fire = new Fire();
    fire->setPos(x(),y());
    scene()->addItem(fire);

    for (int i=1; i<duzina_eksplozije; i++){
      if(!scene()->itemAt(x()+i*50,y(), QTransform())){
          Fire * fire = new Fire();
          fire->setPos(x()+i*50,y());
          scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x()+i*50,y(), QTransform())))) == typeid(fixedWall)){
          break;
      }
      else if((typeid(*(scene()->itemAt(x()+i*50,y(), QTransform())))) == typeid(normalWall)){
          int number = 17;
          int randomValue = qrand() % number;
          if(!(randomValue % 3==0)){
          scene()->removeItem((scene()->itemAt(x()+i*50,y(), QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x()+i*50,y());
          scene()->addItem(fire);
          }
          else{
          scene()->removeItem((scene()->itemAt(x()+i*50,y(), QTransform())));
          powerup = new powerups();
          powerup->setPos(x()+i*50,y());
          scene()->addItem(powerup);
          }
          break;
      }
      // game over
      else if((typeid(*(scene()->itemAt(x()+i*50,y(), QTransform())))) == typeid(Player)){
          scene()->removeItem((scene()->itemAt(x()+50,y(), QTransform())));
      }
    }

    for (int i=1; i<duzina_eksplozije; i++){
      if(!scene()->itemAt(x()-i*50,y(), QTransform())){
          Fire * fire = new Fire();
          fire->setPos(x()-i*50,y());
          scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x()-i*50,y(), QTransform())))) == typeid(fixedWall)){
        break;
      }
      else if((typeid(*(scene()->itemAt(x()-i*50,y(), QTransform())))) == typeid(normalWall)){
          int number = 17;
          int randomValue = qrand() % number;
          if(!(randomValue % 3==0)){
          scene()->removeItem((scene()->itemAt(x()-i*50,y(), QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x()-i*50,y());
          scene()->addItem(fire);
          }
          else{
          scene()->removeItem((scene()->itemAt(x()-i*50,y(), QTransform())));
          powerup = new powerups();
          powerup->setPos(x()-i*50,y());
          scene()->addItem(powerup);
          }
          break;
      }
      // game over
      else if((typeid(*(scene()->itemAt(x()-i*50,y(), QTransform())))) == typeid(Player)){
          scene()->removeItem((scene()->itemAt(x()-i*50,y(), QTransform())));
      }
    }

    for (int i=1; i<duzina_eksplozije; i++){
      if(!scene()->itemAt(x(),y()+i*50, QTransform())){
          Fire * fire = new Fire();
          fire->setPos(x(),y()+i*50);
          scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x(),y()+i*50, QTransform())))) == typeid(fixedWall)){
        break;
      }
      else if((typeid(*(scene()->itemAt(x(),y()+i*50, QTransform())))) == typeid(normalWall)){
          int number = 17;
          int randomValue = qrand() % number;
          if(!(randomValue % 3==0)){
          scene()->removeItem((scene()->itemAt(x(),y()+i*50, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x(),y()+i*50);
          scene()->addItem(fire);
          }
          else{
          scene()->removeItem((scene()->itemAt(x(),y()+i*50, QTransform())));
          powerup = new powerups();
          powerup->setPos(x(),y()+i*50);
          scene()->addItem(powerup);
          }
          break;
      }
      // game over
      else if((typeid(*(scene()->itemAt(x(),y()+i*50, QTransform())))) == typeid(Player)){
          scene()->removeItem((scene()->itemAt(x(),y()+i*50, QTransform())));
      }
    }

    for (int i=1; i<duzina_eksplozije; i++){
      if(!scene()->itemAt(x(),y()-i*50, QTransform())){
          Fire * fire = new Fire();
          fire->setPos(x(),y()-i*50);
          scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x(),y()-i*50, QTransform())))) == typeid(fixedWall)){
        break;
      }
      else if((typeid(*(scene()->itemAt(x(),y()-i*50, QTransform())))) == typeid(normalWall)){
          int number = 17;
          int randomValue = qrand() % number;
          if(!(randomValue % 3==0)){
          scene()->removeItem((scene()->itemAt(x(),y()-i*50, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x(),y()-i*50);
          scene()->addItem(fire);
          }
          else{
          scene()->removeItem((scene()->itemAt(x(),y()-i*50, QTransform())));
          powerup = new powerups();
          powerup->setPos(x(),y()-i*50);
          scene()->addItem(powerup);
          }

          break;
      }
      // game over
      else if((typeid(*(scene()->itemAt(x(),y()-i*50, QTransform())))) == typeid(Player)){
          scene()->removeItem((scene()->itemAt(x(),y()-i*50, QTransform())));
      }
    }

    scene()->removeItem(this);
}

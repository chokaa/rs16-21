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

Bomb::Bomb(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // draw the bomb
    setPixmap(QPixmap(":/images/bomb.jpg"));
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this,SLOT(explode()));
    timer->start(1500);
}

void Bomb::StopTimer(){
   timer->stop();
   explode();
}

void Bomb::explode(){
    if((typeid(*(scene()->itemAt(x(),y(), QTransform())))) == typeid(Bomb)){

    Fire * fire = new Fire();
    fire->setPos(x(),y());
    scene()->addItem(fire);

    for (int i=1; i<this->duzina_eksplozije; i++){
      if(!scene()->itemAt(x()+i*50,y(), QTransform())){
          Fire * fire = new Fire();
          fire->setPos(x()+i*50,y());
          scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x()+i*50,y(), QTransform())))) == typeid(fixedWall)){
          break;
      }
      else if((typeid(*(scene()->itemAt(x()+i*50,y(), QTransform())))) == typeid(powerups)){
          scene()->removeItem((scene()->itemAt(x()+i*50,y(), QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x()+i*50,y());
          scene()->addItem(fire);
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
          powerups * powerup = new powerups();
          powerup->setPos(x()+i*50,y());
          scene()->addItem(powerup);
          }
          break;
      }
      else if((typeid(*(scene()->itemAt(x()+i*50,y(), QTransform())))) == typeid(Bomb)){
        Bomb *bomb = (Bomb*)(scene()->itemAt(x()+i*50,y(), QTransform()));
        bomb->StopTimer();
      }
      // game over
      else if((typeid(*(scene()->itemAt(x()+i*50,y(), QTransform())))) == typeid(Player)){
          Player *player= (Player*)(scene()->itemAt(x()+i*50,y(), QTransform()));
          player->dead();
          Fire * fire = new Fire();
          fire->setPos(x()+i*50,y());
          scene()->addItem(fire);
      }
    }

    for (int i=1; i<this->duzina_eksplozije; i++){
      if(!scene()->itemAt(x()-i*50,y(), QTransform())){
          Fire * fire = new Fire();
          fire->setPos(x()-i*50,y());
          scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x()-i*50,y(), QTransform())))) == typeid(fixedWall)){
        break;
      }
      else if((typeid(*(scene()->itemAt(x()-i*50,y(), QTransform())))) == typeid(powerups)){
          scene()->removeItem((scene()->itemAt(x()-i*50,y(), QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x()-i*50,y());
          scene()->addItem(fire);
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
          powerups * powerup = new powerups();
          powerup->setPos(x()-i*50,y());
          scene()->addItem(powerup);
          }
          break;
      }
      else if((typeid(*(scene()->itemAt(x()-i*50,y(), QTransform())))) == typeid(this)){
           scene()->removeItem((scene()->itemAt(x()-i*50,y(), QTransform())));
      }
      else if((typeid(*(scene()->itemAt(x()-i*50,y(), QTransform())))) == typeid(Bomb)){
        Bomb *bomb = (Bomb*)(scene()->itemAt(x()-i*50,y(), QTransform()));
        bomb->StopTimer();
      }
      // game over
      else if((typeid(*(scene()->itemAt(x()-i*50,y(), QTransform())))) == typeid(Player)){
          Player *player= (Player*)(scene()->itemAt(x()-i*50,y(), QTransform()));
          player->dead();
      }
    }

    for (int i=1; i<this->duzina_eksplozije; i++){
      if(!scene()->itemAt(x(),y()+i*50, QTransform())){
          Fire * fire = new Fire();
          fire->setPos(x(),y()+i*50);
          scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x(),y()+i*50, QTransform())))) == typeid(fixedWall)){
        break;
      }
      else if((typeid(*(scene()->itemAt(x(),y()+i*50, QTransform())))) == typeid(powerups)){
          scene()->removeItem((scene()->itemAt(x(),y()+i*50, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x(),y()+i*50);
          scene()->addItem(fire);
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
          powerups * powerup = new powerups();
          powerup->setPos(x(),y()+i*50);
          scene()->addItem(powerup);
          }
          break;
      }
      else if((typeid(*(scene()->itemAt(x(),y()+i*50, QTransform())))) == typeid(Bomb)){
        Bomb *bomb = (Bomb*)(scene()->itemAt(x(),y()+i*50, QTransform()));
        bomb->StopTimer();
      }
      // game over
      else if((typeid(*(scene()->itemAt(x(),y()+i*50, QTransform())))) == typeid(Player)){
          Player *player= (Player*)(scene()->itemAt(x(),y()+i*50, QTransform()));
          player->dead();
      }
    }

    for (int i=1; i<this->duzina_eksplozije; i++){
      if(!scene()->itemAt(x(),y()-i*50, QTransform())){
          Fire * fire = new Fire();
          fire->setPos(x(),y()-i*50);
          scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x(),y()-i*50, QTransform())))) == typeid(fixedWall)){
        break;
      }
      else if((typeid(*(scene()->itemAt(x(),y()-i*50, QTransform())))) == typeid(powerups)){
          scene()->removeItem((scene()->itemAt(x(),y()-i*50, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x(),y()-i*50);
          scene()->addItem(fire);
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
          powerups * powerup = new powerups();
          powerup->setPos(x(),y()-i*50);
          scene()->addItem(powerup);
          }

          break;
      }
      else if((typeid(*(scene()->itemAt(x(),y()-i*50, QTransform())))) == typeid(Bomb)){
        Bomb *bomb = (Bomb*)(scene()->itemAt(x(),y()-i*50, QTransform()));
        bomb->StopTimer();
      }
      // game over
      else if((typeid(*(scene()->itemAt(x(),y()-i*50, QTransform())))) == typeid(Player)){
          Player *player= (Player*)(scene()->itemAt(x(),y()-i*50, QTransform()));
          player->dead();
      }
    }

    scene()->removeItem(this);

}
}

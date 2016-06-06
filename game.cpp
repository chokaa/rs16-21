#include "game.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>
#include <QKeyEvent>
#include <stdlib.h>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the players

    player1 = new Player();
    player2 = new Player();
    player1->setPos(750, 550);
    player2->setPos(0,0);
    // make the players focusable
      // add the players to the scene
    scene->addItem(player1);
    scene->addItem(player2);

    // add fixed walls (walls that can't be destroyed)
    for(int i=50; i<=350; i+=100){
        for(int j=50; j<=250; j+=100){
            if(i==350 && j==250)
                continue;
            wall = new fixedWall();
            wall->setPos(i,j);
            scene->addItem(wall);

        }
    }
    for(int i=400; i<=750; i+=100){
        for(int j=50; j<=250; j+=100){
            wall = new fixedWall();
            wall->setPos(i,j);
            scene->addItem(wall);
        }
    }
    for(int i=50; i<=350; i+=100){
        for(int j=300; j<=550; j+=100){
            wall = new fixedWall();
            wall->setPos(i,j);
            scene->addItem(wall);
        }
    }
    for(int i=400; i<=750; i+=100){
        for(int j=300; j<=550; j+=100){
            if(i==400 && j==300)
                continue;
            wall = new fixedWall();
            wall->setPos(i,j);
            scene->addItem(wall);
        }
    }

    // normal wall
    for(int i=0;i<16;i++){
        for(int j=0;j<12;j++){
            if(!(scene->itemAt(i*50,j*50, QTransform()))){
            int r=rand() % 10 + 1;
                if(r!=1){
                    nwall = new normalWall();
                    nwall->setPos(i*50,j*50);
                    scene->addItem(nwall);
                }
            }
        }
    }

    //ciscenje zidova oko igraca na pocetku
    if(scene->itemAt(50, 0, QTransform()))
        scene->removeItem((scene->itemAt(50,0, QTransform())));
    if(scene->itemAt(100, 0, QTransform()))
        scene->removeItem((scene->itemAt(100,0, QTransform())));
    if(scene->itemAt(0, 50, QTransform()))
        scene->removeItem((scene->itemAt(0,50, QTransform())));
    if(scene->itemAt(0, 100, QTransform()))
        scene->removeItem((scene->itemAt(0,100, QTransform())));
    if(scene->itemAt(650, 550, QTransform()))
        scene->removeItem((scene->itemAt(650,550, QTransform())));
    if(scene->itemAt(700, 550, QTransform()))
        scene->removeItem((scene->itemAt(700,550, QTransform())));
    if(scene->itemAt(750, 500, QTransform()))
        scene->removeItem((scene->itemAt(750,500, QTransform())));
    if(scene->itemAt(750, 450, QTransform()))
        scene->removeItem((scene->itemAt(750,450, QTransform())));
}

void Game::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left)
        this->player1->move(1);
    else if (event->key() == Qt::Key_Right)
        this->player1->move(2);
    else if (event->key() == Qt::Key_Up)
        this->player1->move(3);
    else if (event->key() == Qt::Key_Down)
        this->player1->move(4);

    else if (event->key() == Qt::Key_A)
        this->player2->move(1);
    else if (event->key() == Qt::Key_D)
        this->player2->move(2);
    else if (event->key() == Qt::Key_W)
        this->player2->move(3);
    else if (event->key() == Qt::Key_S)
        this->player2->move(4);

    else if (event->key() == Qt::Key_Space)
        this->player1->move(5);
    else if (event->key() == Qt::Key_G)
        this->player2->move(5);
}

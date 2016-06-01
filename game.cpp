#include "game.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->setPos(0,0); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

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

    show();
}

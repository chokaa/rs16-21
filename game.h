#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "fixedwall.h"
#include "normalwall.h"
#include "bomb.h"
#include "test.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    fixedWall * wall;
    normalWall * nwall;
    Bomb *bomb;
    Test *test;
};

#endif // GAME_H

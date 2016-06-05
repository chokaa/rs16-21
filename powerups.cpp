#include "powerups.h"
#include <QGraphicsScene>

int tip_powerupa = 0;

powerups::powerups(QGraphicsItem *parent)
{

    int number = 17;
    int randomValue = qrand() % number;

    if(!(randomValue % 3==0)){
    setPixmap(QPixmap(":/images/firepowerup.jpg"));
    tip_powerupa = 1;
    }
    else if(!((randomValue % 3)!=0)){
    setPixmap(QPixmap(":/images/bombpowerup.jpg"));
    tip_powerupa = 2;
    }

}

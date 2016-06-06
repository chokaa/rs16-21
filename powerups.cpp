#include "powerups.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

powerups::powerups(QGraphicsItem *parent)
{

    int number = 17;
    int randomValue = qrand() % number;

    if(!(randomValue % 3==0)){
    setPixmap(QPixmap(":/images/firepowerup.jpg"));
    this->redni_broj_powerupa=1;
    }
    else if(!((randomValue % 3)!=0)){
    setPixmap(QPixmap(":/images/bombpowerup.jpg"));
    this->redni_broj_powerupa=2;
    }
}

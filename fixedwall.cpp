#include "fixedwall.h"
#include <QGraphicsScene>

fixedWall::fixedWall(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/fixedWall.jpg"));
}

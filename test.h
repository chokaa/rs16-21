#ifndef TEST_H
#define TEST_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

#include "powerups.h"

class Test:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Test(QGraphicsItem * parent=0);
      powerups * powerup;
public slots:
    void testic();

};


#endif // TEST_H

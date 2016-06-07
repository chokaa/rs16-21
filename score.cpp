#include <score.h>
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){
    bombs = 1;

    setPlainText(QString("Broj bombi: ") + QString::number(bombs));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 20));
}

void Score::increase()
{
    bombs++;
    setPlainText(QString("Broj bombi: ") + QString::number(bombs));
}


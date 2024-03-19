#ifndef BULLET_H
#define BULLET_H
#include "score.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Bullet();

public slots:
    void move();
};

#endif // BULLET_H

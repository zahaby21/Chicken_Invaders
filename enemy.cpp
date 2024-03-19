#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "game.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <stdlib.h>

extern Game * game;

Enemy::Enemy() :QObject(), QGraphicsPixmapItem() {


    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}

void Enemy:: move(){

    setPos(x(),y()+5);

    if(y()>600)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}


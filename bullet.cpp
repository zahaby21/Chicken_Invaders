#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "score.h"
#include "game.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include <QDebug>
#include <QObject>

extern Game * game;

Bullet::Bullet(): QObject(), QGraphicsPixmapItem() {



    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet:: move()
{

    QList<QGraphicsItem *> collison = collidingItems();
    for (int i = 0; i<collison.size(); i++){
        if (typeid(*(collison[i])) == typeid (Enemy)){

            QMediaPlayer * cd = new QMediaPlayer();
            QAudioOutput* vol = new QAudioOutput();
            cd->setSource(QUrl ("qrc:/sounds/chickenDeath.mp3"));
            cd->setAudioOutput(vol);
            vol->setVolume(15000);
            cd->play();

            game->score->increase();

            scene()->removeItem(collison[i]);
            scene()->removeItem(this);

            delete collison[i];
            delete this;



            return;

        } 
    }
    setPos(x(),y()-10);
    if (y() + 10 < 0){
        scene()->removeItem(this);
        delete this;
    }
}

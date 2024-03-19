#include "game.h"
#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include "main.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QBrush>
#include <QImage>
#include <stdlib.h>

Game::Game(QWidget *parent) {

    scene =  new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    setBackgroundBrush(QBrush(QImage(":/Images/Background.jpg")));

    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);

    QPixmap ship(":/Images/ship.png");
    ship = ship.scaled(75, 75, Qt::KeepAspectRatio);

    player = new Player();
    player->setPixmap(ship);
    player->setPos(360, 525);
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    score = new Score();
    score->setPos(670,10);
    scene->addItem(score);

    health = new Health();
    health->setPos(670,40);
    scene->addItem(health);

    QMediaPlayer * bg = new QMediaPlayer();
    QAudioOutput* vol = new QAudioOutput();
    bg->setSource(QUrl ("qrc:/sounds/bgmusic.wav"));
    bg->setAudioOutput(vol);
    vol->setVolume(50);
    bg->setLoops(QMediaPlayer::Infinite);
    bg->play();



    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(spawn()));
    time->start(2000);

    show();
}

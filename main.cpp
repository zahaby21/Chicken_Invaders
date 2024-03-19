#include <QApplication>
#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "score.h"
#include "game.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <stdlib.h>

Game * game;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}

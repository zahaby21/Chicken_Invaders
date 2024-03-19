#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "score.h"
#include "player.h"
#include "health.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent=0);
    Player* player;
    Score * score;
    Health * health;
    QGraphicsScene * scene;
};

#endif // GAME_H

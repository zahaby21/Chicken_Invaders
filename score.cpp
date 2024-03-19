#include "score.h"
#include <QGraphicsTextItem>
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {

    score = 0;
    setFont(QFont("times", 16));
    setDefaultTextColor(Qt::blue);
    setPlainText("Score:  " + QString::number(score));
}

void Score::increase()
{
    score += 10;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}

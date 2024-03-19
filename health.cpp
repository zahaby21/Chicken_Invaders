#include "health.h"
#include "score.h"
#include "game.h"
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QPushButton>
#include <QFont>
#include <QApplication>
#include <QProcess>


extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent) {

    health = 3;
    setFont(QFont("times", 16));
    setDefaultTextColor(Qt::red);
    setPlainText("Health: " + QString::number(health));
}

void Health::decrease()
{
    health--;
    setPlainText("Health: " + QString::number(health));

    if(health==0){
        QGraphicsTextItem * over = new QGraphicsTextItem;
        over->setFont(QFont("times", 44));
        over->setDefaultTextColor(Qt::red);
        over->setPlainText("GAME OVER");
        over->setPos(230,150);
        scene()->addItem(over);

        QMessageBox * lost = new QMessageBox;
        lost->setText("Unfortunate Loss! Your score was " + QString::number(game->score->getScore()));
        lost->setWindowTitle("GAME OVER");
        QPushButton* exitButton = lost->addButton(tr("Exit"), QMessageBox::ActionRole);
        QPushButton* restartButton = lost->addButton(tr("Restart"), QMessageBox::ActionRole);
        lost->exec();
        if (lost->clickedButton() == exitButton) {
            game->close();
        }
        else if(lost->clickedButton() == restartButton){

            QProcess::startDetached(QApplication::applicationFilePath());
            exit(12);
        }

    }
}

int Health::getHealth()
{
    return health;
}

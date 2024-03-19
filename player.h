#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QTimer>
#include <QDebug>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
public:
    void keyPressEvent(QKeyEvent * event);
    void collisonPlayer();
public slots:
    void spawn();
private:
    QMediaPlayer* BulletSound;
};

#endif // PLAYER_H

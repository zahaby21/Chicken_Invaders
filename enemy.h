#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Enemy();

public slots:
    void move();
};

#endif // ENEMY_H

#ifndef MAIN_H
#define MAIN_H
#include "score.h"
#include <QGraphicsWidget>
#include <QWidget>
#include <QGraphicsView>

class Main: public QGraphicsView{
public:
    Main(QWidget * parent =0);
    Score * score;
};

#endif // MAIN_H

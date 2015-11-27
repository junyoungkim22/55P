#ifndef DISPLAY_H
#define DISPLAY_H

#include "piecelist.h"
#include "user.h"
#include "board.h"
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>

class Display : public QGraphicsView
{
private:
    QGraphicsScene *scene;
    Board* board;
    PieceList* piece;
    User* user;
    QPushButton* yout_button;
public:
    Display();
    void game();
    void draw();
};

#endif // DISPLAY_H


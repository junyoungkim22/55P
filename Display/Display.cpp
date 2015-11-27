#include "display.h"
#include <QObject>
#include <QDebug>

Display::Display()
{
    scene = new QGraphicsScene();
    board = new Board();
    piece = new PieceList();
    user = new User();

    setFixedSize(1000, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0, 0, 1000, 600);

    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++)
        {
           scene->addWidget(piece->getPiece(i, j));
           piece->getPiece(i, j)->QPushButton::move(100 +100*i, 100 + 100*j);
        }

    scene->addWidget(user->getbutton());
    user->getbutton()->move(800, 100);
    //위의 것들을 scene에다 넣기

    setScene(scene);
}

void Display::game()
{
    int team = 0;
    int position[2][3] = {0};

    //draw();//전체 그리기

    //while(1)
    //{
    user->setLocation(position[team][0], position[team][1], position[team][2]);
    QObject::connect(user->getbutton(), SIGNAL(clicked(bool)), user, SLOT(ThrowYout()));
    /*if(user->getYout() != 0)
        QObject::disconnect(yout_button, SIGNAL(clicked(bool)), user, SLOT(ThrowYout()));*/

    int move_num = user->getYout();
    //qDebug() <<endl << move_num;

        /*QObject::connect(piece->getPiece(team, 0), SIGNAL(clicked(bool)), piece, SLOT(select0()));
        QObject::connect(piece->getPiece(team, 1), SIGNAL(clicked(bool)), piece, SLOT(select1()));
        QObject::connect(piece->getPiece(team, 2), SIGNAL(clicked(bool)), piece, SLOT(select2()));*/
    int piece_num = piece->getChoice();

        //position[team][piece_num] = piece->turn_action(team, piece_num, move_num);
        //draw();//말만 그리기

        //std::string type = board->getSpace(position[team][piece_num])->getSpaceType();
        /*if(type == "Building")
            piece->build_action(team, piece_num, board->getSpace(position[team][piece_num]));
        else if(type == "Healing")
            piece->heal_action(team, piece_num, board->getSpace(position[team][piece_num]));
        else
            int a;//황금카드 칸*/

    if(user->getYout() < 4 /*&& 못 잡을 경우*/ )
        team = !team;
    //}
}

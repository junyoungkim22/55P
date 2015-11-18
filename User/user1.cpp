#include "user1.h"
#include "ui_user1.h"
#include "showyout.h"
#include <QtGlobal>
#include <QTime>

User1::User1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::User1)
{
    ui->setupUi(this);
    connect(ui->throwButton, SIGNAL(clicked(bool)), this, SLOT(ThrowYout()));
    connect(ui->piece1, SIGNAL(clicked(bool)), this, SLOT(selectPiece1()));
    connect(ui->piece2, SIGNAL(clicked(bool)), this, SLOT(selectPiece2()));
    connect(ui->piece3, SIGNAL(clicked(bool)), this, SLOT(selectPiece3()));
    connect(ui->straight, SIGNAL(clicked(bool)), this, SLOT(selectNode_s()));
    connect(ui->curved, SIGNAL(clicked(bool)), this, SLOT(selectNode_c()));
}

int User1::ThrowYout()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    ShowYout *syout = new ShowYout();

    int yout = qrand()%16;
    if(yout < 1)
        yout = -1;
    else if(yout < 4)
        yout = 1;//도
    else if(yout < 10)
        yout = 2;//개
    else if(yout < 14)
        yout = 3;//걸
    else if(yout < 15)
        yout = 4;//윷
    else
        yout = 5;//모

    if(location1<2 && location2<2 && location3<2)
        if(yout == -1)
            yout = 1;   //빽도 안되는 경우
    
    syout->printyout(yout);
    syout->show();

    return yout;
}

void User1::selectPiece1()
{
    piece = 1;
}
void User1::selectPiece2()
{
    piece = 2;
}
void User1::selectPiece3()
{
    piece = 3;
}

void User1::selectNode_s()
{
    way = 0;
}
void User1::selectNode_c()
{
    way = 1;
}

int User1::isFinished()
{
    if(turnedPiece == 3)
        return 1;
    else
        return 0;
}

User1::~User1()
{
    delete ui;
}

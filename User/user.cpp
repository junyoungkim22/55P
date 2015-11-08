#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

int User::ThrowYout()
{
    srand(time(NULL));
    int yout = rand()%16;
    if(yout < 4)
        yout = 0;//도
    else if(yout < 10)
        yout = 1;//개
    else if(yout < 14)
        yout = 2;//걸
    else if(yout < 15)
        yout = 3;//윷
    else
        yout = 4;//모
    
    return yout;
}

int User::selectPiece()
{
    if()
        return 1;
    else if()
        return 2;
    else if()
        return 3;
}

int User::selectNode(int index)
{
    if(index)
    {
        if()
            return 0;
        else
            return 1;
    }
}

int User::isFinished()
{
    if(turnedPiece == 3)
        return 1;
    else
        return 0;
}

User::~User()
{
    delete ui;
}

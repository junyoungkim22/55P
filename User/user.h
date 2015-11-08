#ifndef USER_H
#define USER_H

#include <QMainWindow>

namespace Ui {
class User;
}

class User : public QMainWindow
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = 0);

    int ThrowYout();
    int getYout() { return yout; }
    
    int selectPiece();
    
    int selectNode(int index);  //이 method안에서 검사할지, 아니면 검사해서 이 method를 실행시킬지
    
    int isFinished();

    ~User();

private:
    Ui::User *ui;
    int yout;
    int turnedPiece;    //다 돈 말
    int piece1, piece2, piecc3;
};

#endif // USER_H

#ifndef USER1_H
#define USER1_H

#include <QMainWindow>

namespace Ui {
class User1;
}

class User1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit User1(QWidget *parent = 0);
    ~User1();

    int getYout() { return yout; }
    int getPiece() { return piece; }
    int getWay() { return way; }
    int isFinished();

private slots:
    int ThrowYout();
    void selectPiece1();
    void selectPiece2();
    void selectPiece3();
    void selectNode_s();  //이 method안에서 검사할지, 아니면 검사해서 이 method를 실행시킬지
    void selectNode_c();

private:
    Ui::User1 *ui;
    int yout;
    int turnedPiece;
    int piece;
    int way;
};

#endif // USER1_H

#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Piece : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int HP, maxHP, position, team, num;
public:
    Piece(int HP, int position, int team, int num);
    int move(int move_num);
    bool get_damage(int damage);
    void get_heal(int heal);
    void finish();
    void setMaxHP(int maxHP);
    void setPosition(int position);
    int getHP();
    int getPosition();
    int getTeam();
    void show();
public slots:
    int choose();
};

#endif // PIECE_H


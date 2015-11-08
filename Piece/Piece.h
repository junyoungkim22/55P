#ifndef PIECE_H
#define PIECE_H

class Piece
{
private:
    int HP, maxHP, position, team;
public:
    Piece(int HP, int position, int team);
    int move(int move_num);
    void get_damage(int damage);
    void get_heal(int heal);
    void finish();
    void setMaxHP(int maxHP);
    void setPosition(int position);
    int getHP();
    int getPosition();
    int getTeam();
};

#endif // PIECE_H


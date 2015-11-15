#include "piece.h"

Piece::Piece(int HP, int position, int team, int num)
{
    if(team == 0)
        setPixmap(QPixmap(":/images/piece1.png"));
    else
        setPixmap(QPixmap(":/images/piece2.png"));

    this->HP = HP;
    maxHP = 100;
    this->position = position;
    this->team = team;
    this->num = num;
}

int Piece::move(int move_num)
{
    position += move_num;
    return position;
}

bool Piece::get_damage(int damage)
{
    HP -= damage;
    if(HP <= 0)
        return true;
    else
        return false;
}

void Piece::get_heal(int heal)
{
    HP += heal;
    if(HP > maxHP)
        HP = 100;
}

void Piece::finish()
{

}

void Piece::setMaxHP(int maxHP)
{
    this->maxHP = maxHP;
}

void Piece::setPosition(int position)
{
    this->position = position;
}

int Piece::getHP()
{
    return HP;
}

int Piece::getPosition()
{
    return position;
}

int Piece::getTeam()
{
    return team;
}

int Piece::choose()
{
    return num;
}

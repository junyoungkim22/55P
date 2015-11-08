#include "piece.h"

Piece::Piece(int HP, int position, int team)
{
    this->HP = HP;
    maxHP = 100;
    this->position = position;
    this->team = team;
}

int Piece::move(int move_num)
{
    position += move_num;
    return position;
}

void Piece::get_damage(int damage)
{
    HP -= damage;
    if(HP <= 0)
        die();
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

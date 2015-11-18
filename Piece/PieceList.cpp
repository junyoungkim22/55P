#include "piecelist.h"
#include "twopiece.h"
#include "threepiece.h"
#include <typeinfo>
#include <stdlib.h>
#include <iostream>

PieceList::PieceList()
{
    for(int i=0; i<3; i++)
    {
        piece[0][i] = new Piece(100, 0, 0, i);
        piece[1][i] = new Piece(100, 0, 1, i);
    }
}

//윷의 값을 받아서 말을 움직이는 과정(잡거나 말을 합치는 경우도 포함)
void PieceList::turn_action(int team, int piece_num , int move_num)
{
    int position, check = 0, i;

    position = piece[team][piece_num]->move(move_num);

    for(i=0; i<3; i++)
    {
        if(position == piece[team][i]->getPosition() && i != piece_num)
            check = 1;

        else if(position == piece[!team][i]->getPosition())
            check = 2;

        if(check != 0)
            break;
    }

    if(check == 1)
        unite(piece_num, i, team);
    else if(check == 2)
        capture(i, !team);
}

//healing space에 도착했을때
void PieceList::heal_action(int team, int piece_num, HealingSpace *space)
{
    int heal_num = space->getheal();

    piece[team][piece_num]->get_heal(heal_num);
}

//평번한 칸에 도착했을 때
void PieceList::build_action(int team, int piece_num, BuildingSpace *space)
{
    bool death_check;
    int owner = space->getTire();

    if(owner == team)
        return;

    else if(owner == !team)
    {
        popUp *steal = new ShowYout();  //생성자를 이용하여 초기화 시켜야 사용가능

        death_check = piece[team][piece_num]->get_damage(space->getDamagecost());
        if(death_check == true)
        {
            die(piece_num, team);
            return;
        }

        if(piece[team][piece_num]->getHP() > space->getStealcost())
        {
            steal->show();
            if(steal->getSelect() == 1)
                piece[team][piece_num]->get_damage(space->getStealcost());
            space->setTire(team);
        }
    }

    else
    {
        popUp *buy = new ShowYout();  //생성자를 이용하여 초기화 시켜야 사용가능

        if(piece[team][piece_num]->getHP() > space->getBuycost())
        {
            buy->show();
            if(buy->getSelect() == 1)
                piece[team][piece_num]->get_damage(space->getBuycost());
            space->setTire(team);
        }
    }
}

void PieceList::capture(int captured_piece, int team)
{
    die(captured_piece, team);
}

void PieceList::unite(int p1, int p2, int team)
{
    int HP = piece[team][p1]->getHP() + piece[team][p2]->getHP();
    int position = piece[team][p1]->getPosition();

    if(typeid(*piece[team][p1]) == typeid(TwoPiece) || typeid(*piece[team][p2]) == typeid(TwoPiece))
    {
        delete piece[team][p1];
        delete piece[team][p2];

        piece[team][p1] = new ThreePiece(HP, position, team, p1);
    }
    else
    {
        delete piece[team][p1];
        delete piece[team][p2];

        piece[team][p1] = new TwoPiece(HP, position, team, p1);
    }
}

void PieceList::die(int piece_num, int team)
{
    if(typeid(*piece[team][piece_num]) == typeid(Piece))
    {
        delete piece[team][piece_num];
        piece[team][piece_num] = new Piece(100, 0, team, piece_num);
    }

    else  if(typeid(*piece[team][piece_num]) == typeid(TwoPiece))
    {
        delete piece[team][piece_num];
        for(int i=0; i<3; i++)
            if(piece[team][i] == NULL)
                piece[team][i] = new Piece(100, 0, team, i);
    }

    else
    {
        delete piece[team][piece_num];
        for(int i=0; i<3; i++)
            piece[team][i] = new Piece(100, 0, team, i);
    }
}

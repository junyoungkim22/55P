#include "piecelist.h"
#include "twopiece.h"
#include "threepiece.h"
#include <typeinfo>
#include <stdlib.h>

PieceList::PieceList()
{
    for(int i=0; i<3; i++)
    {
        team1[i] = new Piece(100, 0, 0, i);
        team2[i] = new Piece(100, 0, 1, i);
    }
}

void PieceList::turn_action(int team, int piece_num , int move_num)
{
    int position, check = 0, i;

    if(team == 0)
        position = team1[piece_num]->move(move_num);
    else
        position = team2[piece_num]->move(move_num);


    for(i=0; i<3; i++)
    {
        if(position == team1[i]->getPosition() && (team != 0 || piece_num != i))
        {
            if(team == 0)
                check = 1;
            else
                check = 2;
        }

        else if(position == team2[i]->getPosition() && (team != 1 || piece_num != i))
        {
            if(team == 1)
                check = 2;
            else
                check = 1;
        }

        if(check != 0)
            break;
    }

    if(check == 1)
        unite(piece_num, i, team);
    else if(check == 2)
        capture(i, !team);
}

void PieceList::capture(int captured_piece, int team)
{
    die(captured_piece, team);
}

void PieceList::unite(int p1, int p2, int team)
{
    int HP, position;

    if(team == 0)
    {
        HP = team1[p1]->getHP() + team1[p1]->getHP();
        position = team1[p1]->getPosition();

        delete team1[p1];
        delete team1[p2];

        if(typeid(*team1[p1]) == typeid(TwoPiece) || typeid(*team1[p2]) == typeid(TwoPiece))
            team1[p1] = new ThreePiece(HP, position, team, p1);
        else
            team1[p1] = new TwoPiece(HP, position, team, p1);
    }

    else
    {
        HP = team2[p1]->getHP() + team2[p1]->getHP();
        position = team2[p1]->getPosition();

        delete team2[p1];
        delete team2[p2];

        if(typeid(*team2[p1]) == typeid(TwoPiece) || typeid(*team2[p2]) == typeid(TwoPiece))
            team2[p1] = new ThreePiece(HP, position, team, p1);
        else
            team2[p1] = new TwoPiece(HP, position, team, p1);
    }

}

void PieceList::die(int piece_num, int team)
{
    if(team == 0)
    {
        if(typeid(*team1[piece_num]) == typeid(Piece))
        {
            delete team1[piece_num];
            team1[piece_num] = new Piece(100, 0, team, piece_num);
        }

        else if(typeid(*team1[piece_num]) == typeid(TwoPiece))
        {
            delete team1[piece_num];
            for(int i=0; i<3; i++)
                if(team1[i] == NULL)
                    team1[i] = new Piece(100, 0, team, i);
        }

        else
        {
            delete team1[piece_num];
            for(int i=0; i<3; i++)
                team1[i] = new Piece(100, 0, team, i);
        }
    }

    else
    {
        if(typeid(*team2[piece_num]) == typeid(Piece))
        {
            delete team2[piece_num];
            team2[piece_num] = new Piece(100, 0, team, piece_num);
        }

        else if(typeid(*team2[piece_num]) == typeid(TwoPiece))
        {
            delete team2[piece_num];
            for(int i=0; i<3; i++)
                if(team2[i] == NULL)
                    team2[i] = new Piece(100, 0, team, i);
        }

        else
        {
            delete team2[piece_num];
            for(int i=0; i<3; i++)
                team2[i] = new Piece(100, 0, team, i);
        }
    }
}

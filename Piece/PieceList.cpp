#include "piecelist.h"
#include "twopiece.h"
#include "threepiece.h"
#include <typeinfo>

PieceList::PieceList()
{
    for(int i=0; i<3; i++)
        piece[i] = new Piece(100, 0, 1);
    for(int i=3; i<6; i++)
        piece[i] = new Piece(100, 0, 2);
}

void PieceList::turn_action(int piece_num, int move_num)
{
    int position, check = 0, i;

    position = piece[piece_num]->move(move_num);

    for(i=0; i<6; i++)
    {
        if(i == piece_num)
            continue;

        else
        {
            if(position == piece[i]->getPosition())
            {
                if(piece[i]->getTeam() == piece[piece_num]->getTeam())
                    check = 1;
                else
                    check = 2;
            }
        }

        if(check != 0)
            break;
    }

    if(check == 1)
        unite(piece_num, i);
    else if(check == 2)
        capture(i);


}

void PieceList::capture(int captured_piece)
{
    piece[captured_piece]->die();
}

void PieceList::unite(int p1, int p2)
{
    int HP = piece[p1]->getHP() + piece[p2]->getHP();
    int position = piece[p1]->getPosition();
    int team = piece[p1]->getTeam();

    delete piece[p1];
    delete piece[p2];

    if(typeid(*piece[p1]) == typeid(TwoPiece) || typeid(*piece[p2]) == typeid(TwoPiece))
        piece[p1] = new ThreePiece(HP, position, team);

    else
        piece[p1] = new TwoPiece(HP, position, team);
}

void PieceList::die(int p)
{
    if(typeid(*piece[p] == typeid(Piece)))
    {
        team = piece[p]->getTeam();
        piece[p] = new Piece(100, 0, team);
    }

    else if(typeid(*piece[p]) == typeid(TwoPiece))
}

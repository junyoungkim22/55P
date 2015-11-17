#ifndef PIECELIST_H
#define PIECELIST_H

#include "piece.h"
#include "space.h"
#include "buildingspace.h"
#include "healingspace.h"
#include "popup.h"

class PieceList
{
private:
    Piece *piece[2][3];
public:
    PieceList();
    void turn_action(int team, int piece_num, int move_num);
    void heal_action(int team, int piece_num, HealingSpace *space);
    void build_action(int team, int piece_num, BuildingSpace *space);
    void capture(int captured_piece, int team);
    void unite(int p1, int p2, int team);
    void die(int piece_num, int team);
};

#endif // PIECELIST_H


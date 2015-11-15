#ifndef PIECELIST_H
#define PIECELIST_H

#include "piece.h"

class PieceList
{
private:
    Piece *team1[3], *team2[3];
public:
    PieceList();
    void turn_action(int team, int piece_num, int move_num);
    void capture(int captured_piece, int team);
    void unite(int p1, int p2, int team);
    void die(int piece_num, int team);
};

#endif // PIECELIST_H


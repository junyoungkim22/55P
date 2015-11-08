#ifndef PIECELIST_H
#define PIECELIST_H

#include "piece.h"

class PieceList
{
private:
    Piece *piece[6];
public:
    PieceList();
    void turn_action(int piece_num, int move);
    void capture(int captured_piece);
    void unite(int p1, int p2);
    void die(int p);
};

#endif // PIECELIST_H

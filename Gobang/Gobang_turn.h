
#define Gobang_turn_
#include "Gobang_point.h"
#include "ChessBoard.hpp"
#include <QDebug>
class Nextmove
{
public:
    void Initialize(ChessBoard * const , int a[15][15]);
	int Search_tree(int a[15][15], int count, int const& k);
    int max0, min0, max1;
    int Gobang_turn(ChessBoard * const B, const int BW);

};

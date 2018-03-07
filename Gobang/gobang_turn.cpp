#include"Gobang_turn.h"

int Nextmove::Gobang_turn(ChessBoard * const B, const int BW)
{
    int a[15][15];
    int k = (BW == Black )?1:-1;
    Initialize(B,a);
    int count = 0;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
        {
            if (a[i][j] != 0) count++;
        }
    if (!count) return 707;
    if (count==1)
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                if (a[i][j] != 0)
                {
                    if (i < 7 && j < 7) return (i + 1) * 100 + (j + 1);
                    if (i < 7 && j >= 7) return (i + 1) * 100 + (j - 1);
                    if (i >= 7 && j < 7) return (i - 1) * 100 + (j + 1);
                    if (i >= 7 && j >= 7) return (i - 1) * 100 + (j - 1);
                }

    max0 = -WIN;
    int maxi = -1, maxj = -1;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
        {
            if (a[i][j] == 0)
            {
                Gobangpoint Mybang;
                int point = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);
                a[i][j] = k;
                if (Mybang.Gobang_Havefive(a, k)) { return i * 100 + j; }
                int point2 = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);
                if (point == point2) { a[i][j] = 0; continue; }
                if (!Mybang.Gobang_Havefour(a, -k) && point2 > 400000)
                {
                    return i * 100 + j;
                }
                int result = Search_tree(a, 0, k);
                if (result == -500000) { a[i][j] = 0; continue; }
                if (result > max0)
                {
                    max0 = result;
                    maxi = i;
                    maxj = j;
                }
                a[i][j] = 0;
            }
        }
    return maxi * 100 + maxj;
}


int Nextmove:: Search_tree(int a[15][15], int count, const int& k)
{
    if (count == 0)
    {
        min0 = WIN;
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
            {
                if (a[i][j] == 0)
                {
                    Gobangpoint Mybang;
                    int point = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);
                    a[i][j] = -k;
                    int point2 = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);
                    if (point == point2) { a[i][j] = 0; continue; }
                    if (Mybang.Gobang_point(a, -k) >= 500000) { a[i][j] = 0; return -WIN; }
                    point = Search_tree(a, count + 1, k);
                    if (min0 > point) min0 = point;
                    if (min0 <= max0) { a[i][j] = 0; continue; }
                    a[i][j] = 0;
                }
            }
        return min0;
    }
    if (count == 1)
    {

        int max = -WIN;
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
            {
                if (a[i][j] == 0)
                {
                    Gobangpoint Mybang;
                    a[i][j] = k;
                    int point = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);
                    if (Mybang.Gobang_Havefive(a, k)) { a[i][j] = 0; return WIN; }
                    if (Mybang.Gobang_point(a, k) >= 500000) { a[i][j] = 0; return WIN; }
                    if (Mybang.Gobang_Havefour(a, k)) { a[i][j] = 0; continue; }
                    if (max < point) max = point;
                    a[i][j] = 0;
                }
            }
        return max;
    }
    return 0;
}

void Nextmove::Initialize(ChessBoard * const B, int a[15][15])
{
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            if (B->board[i][j] == Black) a[i][j] = 1; else if (B->board[i][j] == White) a[i][j] = -1; else a[i][j] = 0;
}

#include"Gobang_point.h"

int Gobangpoint::Gobang_point(const int a[15][15], const int& k)
{
        int ans = 0;
        int count3 = 0, count2 = 0;
        int di[4] = { 1,1,0,-1 };
        int dj[4] = { 0,1,1,1 };
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                if (a[i][j] == k)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        if (i - di[l] < 0 || j - dj[l] < 0 || a[i - di[l]][j - dj[l]] != k)
                        {
                            int ii = i + di[l], jj = j + dj[l];
                            while (a[ii][jj] == k && ii < 15 && jj < 15) { ii += di[l]; jj += dj[l]; }
                            if (ii == 15) ii--;
                            if (jj == 15) jj--;
                            int length;
                            if (ii - i > jj - j) length = ii - i; else length = jj - j;
                            if (length == 5) ans = WIN;	//������
                            int obstacle = 0;
                            if (i - di[l] < 0 || j - dj[l] < 0 || a[i - di[l]][j - dj[l]] == -k) obstacle++;
                            if (ii + di[l] > 14 || jj + dj[l] > 14 || a[ii][jj] == -k) obstacle++;
                            if (length == 4)
                            {
                                if (obstacle == 0) ans = WIN;		//����
                                if (obstacle == 1) { ans += 100; count3++; }		//����
                                if (obstacle == 2) ans += 50;		//����
                            }
                            if (length == 3)
                            {
                                if (obstacle == 0) { ans += 100; count3++; }		//����
                                if (obstacle == 1) { ans += 20; count2++; }		//����
                                if (obstacle == 2) ans += 5;		//����
                            }
                            if (length == 2)
                            {
                                if (obstacle == 0) { ans += 15; count2++; }		//����
                                if (obstacle == 1) ans += 6;		//�߶�
                                if (obstacle == 2) ans += 3;		//����
                            }
                        }

                    }

                }
        if (count3 >= 2) ans += 1500;
        if (count2 >= 2) ans += count2 * 20;
        return ans;
}

bool Gobangpoint::Gobang_Havefour(int a[15][15], const int& k)
{
    int di[4] = { 1,1,0,-1 };
    int dj[4] = { 0,1,1,1 };
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            if (a[i][j] == k)
            {
                for (int l = 0; l < 4; l++)
                {
                    if (i - di[l] < 0 || j - dj[l] < 0 || a[i - di[l]][j - dj[l]] != k)
                    {
                        int ii = i + di[l], jj = j + dj[l];
                        while (a[ii][jj] == k && ii < 15 && jj < 15) { ii += di[l]; jj += dj[l]; }
                        if (ii == 15) ii--;
                        if (jj == 15) jj--;
                        int length;
                        if (ii - i > jj - j) length = ii - i; else length = jj - j;
                        int obstacle = 0;
                        if (i - di[l] < 0 || j - dj[l] < 0 || a[i - di[l]][j - dj[l]] == -k) obstacle++;
                        if (ii + di[l] > 14 || jj + dj[l] > 14 || a[ii][jj] == -k) obstacle++;
                        if (length == 4 && obstacle < 2)
                        {
                            return true;
                        }
                    }

                }

            }
    return false;
}

bool Gobangpoint::Gobang_Havefive(int a[15][15], const int& k)
{
    int di[4] = { 1,1,0,-1 };
    int dj[4] = { 0,1,1,1 };
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            if (a[i][j] == k)
            {
                for (int l = 0; l < 4; l++)
                {
                    if (i - di[l] < 0 || j - dj[l] < 0 || a[i - di[l]][j - dj[l]] != k)
                    {
                        int ii = i + di[l], jj = j + dj[l];
                        while (a[ii][jj] == k && ii < 15 && jj < 15) { ii += di[l]; jj += dj[l]; }
                        if (ii == 15) ii--;
                        if (jj == 15) jj--;
                        int length;
                        if (ii - i > jj - j) length = ii - i; else length = jj - j;
                        if (length == 5)
                        {
                            return true;
                        }
                    }

                }

            }
    return false;
}

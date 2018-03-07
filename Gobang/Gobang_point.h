#ifndef Gobang_point_
#define Gobang_point_

#define WIN 500000;

class Gobangpoint
{
public:
    int Gobang_point(const int a[15][15], const int& k);
    bool Gobang_Havefour(int a[15][15], const int& k);
    bool Gobang_Havefive(int a[15][15], const int& k);
};

#endif

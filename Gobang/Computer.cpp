#include "Computer.hpp"
#include "Gobang_turn.h"

Computer::Computer(ChessBoard * const B, const int BW){
    name="Computer";
    lastx=lasty=-1;
    PlayerBoard=B;
    BlackWhite=BW;
}

void Computer::NextChess(int& x, int& y){     //神经网络，机器学习等等都放这里就好了
    int tempx=-1, tempy=-1;
    if(!PlayerBoard->LegalStep(tempx, tempy)){
        Nextmove Mycomputer;//qDebug()<<123;
        int result = Mycomputer.Gobang_turn(PlayerBoard, BlackWhite);
		tempx = result / 100;
		tempy = result % 100;
        if (result<0)
		{
			tempx = rand() % ROW;
			tempy = rand() % COL;
		}
    }
    lastx=tempx;
    lasty=tempy;
    PlayerBoard->SetLast(tempx, tempy, BlackWhite);
    PlayerBoard->Set(tempx, tempy, BlackWhite);
    x=tempx;
    y=tempy;
}

#include "ChessBoard.hpp"

ChessBoard::ChessBoard(){
    int i, j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++)
            board[i][j]=Empty;
    }
    lastx=lasty=-1;
}

void ChessBoard::PrintBoard()const{
    int i, j;
    for(i=-1;i<ROW;i++){
        for(j=-1;j<COL;j++){
            if(i==-1){
                if(j==-1)
                    cout << "  ";
                else
                    printf("%X ", j);
            }
            else if(j==-1){
                printf("%X ", i);
            }
            else
                cout << int(board[i][j]) << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void ChessBoard::Set(const int x, const int y, const int Chess){
    board[x][y]=Chess;
}

void ChessBoard::SetLast(const int x, const int y, const int BW){
    lastx=x;
    lasty=y;
    lastBW=BW;
}

int ChessBoard::GetlastW()const{
    return lastBW;
}

int ChessBoard::Getlastx()const{
    return lastx;
}

int ChessBoard::Getlasty()const{
    return lasty;
}

bool ChessBoard::InBoard(const int x, const int y)const{
    if(x<ROW && x>-1 && y<COL && y>-1)
        return true;
    else
        return false;
}

bool ChessBoard::LegalStep(const int x, const int y)const{
    if(board[x][y]==Empty && x<ROW && x>-1 && y<COL && y>-1)
        return true;
    else
        return false;
}

bool ChessBoard::HorizontalCheck()const{
    int i, count=0;
    for(i=-4;i<=4;i++){
        if(!InBoard(lastx, lasty+i))
            continue;
        if(board[lastx][lasty+i]==lastBW){
            count++;
            if(count==5)
                return true;
        }
        else
            count=0;
    }
    return false;
}

bool ChessBoard::VerticalCheck()const{
    int i, count=0;
    for(i=-4;i<=4;i++){
        if(!InBoard(lastx+i, lasty))
            continue;
        if(board[lastx+i][lasty]==lastBW){
            count++;
            if(count==5)
                return true;
        }
        else
            count=0;
    }
    return false;
}

bool ChessBoard::DiagonalCheck()const{
    int i, count=0;
    for(i=-4;i<=4;i++){
        if(!InBoard(lastx+i, lasty+i))
            continue;
        if(board[lastx+i][lasty+i]==lastBW){
            count++;
            if(count==5)
                return true;
        }
        else
            count=0;
    }
    count=0;
    for(i=-4;i<=4;i++){
        if(!InBoard(lastx+i, lasty-i))
            continue;
        if(board[lastx+i][lasty-i]==lastBW){
            count++;
            if(count==5)
                return true;
        }
        else
            count=0;
    }
    return false;
}














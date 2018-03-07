#include "piece.h"
#include <QDebug>

PieceList::PieceList(QWidget *p)
{
    head = NULL;
    tail = NULL;
    parent = p;
}
void PieceList::AddPiece(const PieceType& type, const int& x, const int& y)
{
    Piece *temp;
    if(type==white)
        temp = new WhitePiece(parent);
    else
        temp = new BlackPiece(parent);
    temp->SetPiece(x,y);
    if(head==NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void PieceList::ClearBoard()
{
    Piece *temp;
    temp = head;
    while(temp!=NULL)
    {
        head = temp;
        temp = temp->next;
        head->DeletePiece();
    }
    head = NULL;
    tail = NULL;
}
PieceList::~PieceList()
{
    ClearBoard();
}

Piece::Piece(QWidget *p)
{
    next = NULL;
    label = new QLabel(p); //label由于有父类 不delete也会自动释放
    label->resize(35,35);
}
void Piece::DeletePiece()
{
    delete label;
}

void BlackPiece::SetPiece(const int& x, const int& y)
{
    label->setPixmap(QPixmap(":/image/black.png"));
    label->move(x*33+2,y*33);
    label->show();
}
void WhitePiece::SetPiece(const int& x, const int& y)
{
    label->setPixmap(QPixmap(":/image/white.png"));
    label->move(x*33+2,y*33);
    label->show();
}



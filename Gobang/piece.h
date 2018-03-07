#ifndef PIECE_H
#define PIECE_H

#include <QDebug>

#include <QLabel>
#include <QString>

enum PieceType {white, black};

class Piece;

class PieceList
{
public:
    PieceList(QWidget *p);
    void AddPiece(const PieceType& type, const int& x, const int& y);
    void ClearBoard();
    ~PieceList();
private:
    QWidget *parent;
    Piece *head, *tail;
};

class Piece
{
public:
    Piece(QWidget *p);
    virtual void SetPiece(const int& x, const int& y) = 0;
    void DeletePiece();
    Piece *next;
protected:
    int x,y;
    QLabel *label;
};

class BlackPiece : public Piece
{
public:
    BlackPiece(QWidget *p=nullptr):Piece(p){}
    void SetPiece(const int& x, const int& y);
};

class WhitePiece : public Piece
{
public:
    WhitePiece(QWidget *p=nullptr):Piece(p){}
    void SetPiece(const int& x, const int& y);
};

#endif // PIECE_H

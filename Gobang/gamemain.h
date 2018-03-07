#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include "ChessBoard.hpp"
#include "Player.hpp"
#include "piece.h"
#include <QMainWindow>

namespace Ui {
class GameMain;
}

class QLabelToBeClick : public QLabel
{
    Q_OBJECT
public:
    QLabelToBeClick(QWidget *parent = 0);
protected:
    //void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);
signals:
    void clicked(const int& x, const int& y);
};

class QLabelToBeClickSometimes : public QLabel
{
    Q_OBJECT
public:
    QLabelToBeClickSometimes(QWidget *parent = 0);
protected:
    //void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);
signals:
    void clicked();
};

class GameMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameMain(QWidget *parent = 0);
    ~GameMain();
    void SetGame(const int& mode, const int& first = 0);
    void delay();

private:
    Ui::GameMain *ui;
    PieceList list;
    PieceType now;
    Player *P[2];
    ChessBoard *TheBoard;
    int Mode,First;

public slots:
    void ExecPlay(const int& x, const int& y);
    void NextPlay();
    void return_start();
    void print_winner(const int& winner);
};


#endif // GAMEMAIN_H

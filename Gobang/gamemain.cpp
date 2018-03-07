
#include "start.h"
#include "Gobang.h"
#include "ChessBoard.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "Computer.hpp"

#include "piece.h"
#include "gamemain.h"
#include "ui_gamemain.h"
#include <QDebug>
#include <QIcon>
#include <QLabel>
#include <QMouseEvent>
#include <QTime>
#include <QMessageBox>
#include <QPushButton>

QLabelToBeClick::QLabelToBeClick(QWidget *parent):QLabel(parent)
{
    this->setMouseTracking(true);
}
//void QLabelToBeClick::mouseMoveEvent(QMouseEvent *event);
void QLabelToBeClick::mousePressEvent(QMouseEvent *event)
{
    int x, y;
    x = event->x()-2;
    y = event->y();
    event->accept();
    emit clicked(x/33, y/33);
}

//void QLabelToBeClick::mouseReleaseEvent(QMouseEvent *event);

QLabelToBeClickSometimes::QLabelToBeClickSometimes(QWidget *parent):QLabel(parent)
{
    this->setMouseTracking(true);
}
void QLabelToBeClickSometimes::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    emit clicked();
}

GameMain::GameMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameMain),
    list(this)
{
    ui->setupUi(this);
    now=black;
    setWindowIcon(QIcon(":/image/gobang.ico"));
    setWindowTitle("Gobang");
    setFixedSize(800,500);
    QLabelToBeClick *label = new QLabelToBeClick(this);
    label->setPixmap(QPixmap(":/image/board.jpg"));
    label->resize(500,500);
    label->show();
    connect(label,&QLabelToBeClick::clicked,this,&GameMain::ExecPlay);

    QLabelToBeClick *label2 = new QLabelToBeClick(this);
    label2->setPixmap(QPixmap(":/image/buttonback.jpg"));
    label2->move(500,0);
    label2->resize(300,500);
    label2->show();

    QPushButton *labelS1 = new QPushButton(this);
    labelS1->setText("下一局");
    labelS1->resize(100,50);
    labelS1->move(610,200);
    connect(labelS1,&QPushButton::clicked,this,&GameMain::NextPlay);
    QPushButton *labelS2 = new QPushButton(this);
    labelS2->setText("主菜单");
    labelS2->resize(100,50);
    labelS2->move(610,300);
    connect(labelS2,&QPushButton::clicked,this,&GameMain::return_start);

    QPalette palette=this->palette();
    this->setPalette(palette);
    labelS1->setStyleSheet("QPushButton{background-color:black;\
                           color: white;   border-radius: 10px;  border: 2px groove gray;\
                           border-style: outset;}"
                           "QPushButton:hover{background-color:white; color: black;}"
                           "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                           border-style: inset; }");
    labelS2->setStyleSheet("QPushButton{background-color:black;\
                            color: white;   border-radius: 10px;  border: 2px groove gray;\
                            border-style: outset;}"
                            "QPushButton:hover{background-color:white; color: black;}"
                            "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                            border-style: inset; }");
}

GameMain::~GameMain()
{
    delete ui;
}

void GameMain::SetGame(const int& mode,const int& first)
{
    TheBoard=new ChessBoard();
    Mode=mode;
    First=first;
    string tempname, tempname2;

    switch(Mode){
        case PVC:
            tempname="PH";
            //first 1 人类先行

            P[first]=new Human(tempname, TheBoard, first==black?Black:White);
            P[1-first]=new Computer(TheBoard, first==white?Black:White);

            break;
        case PVP:
            tempname="P1";
            tempname2="P2";

            P[black]=new Human(tempname, TheBoard, Black);
            P[white]=new Human(tempname2, TheBoard, White);

            break;
        default:
            break;
    }
    if(P[black]->GetName().compare("Computer")==0)
    {
        int tx, ty;
        P[now]->NextChess(tx,ty);
        list.AddPiece(now,tx,ty);
        now=white;
    }
}

void GameMain::ExecPlay(const int& x, const int& y)
{
    int tx=x, ty=y;
    list.AddPiece(now,tx,ty);
    P[now]->NextChess(tx,ty);
    if(now==black)
        now=white;
    else
        now=black;
    if(TheBoard->DiagonalCheck() || TheBoard->HorizontalCheck() || TheBoard->VerticalCheck()){
        int Winner=TheBoard->GetlastW();
        print_winner(Winner);
        delay();
        NextPlay();
        return;
    }
    if(Mode==PVC)
    {
        P[now]->NextChess(tx,ty);
        list.AddPiece(now,tx,ty);
        if(now==black)
            now=white;
        else
            now=black;
        if(TheBoard->DiagonalCheck() || TheBoard->HorizontalCheck() || TheBoard->VerticalCheck()){
            int Winner=TheBoard->GetlastW();
            print_winner(Winner);
            delay();
            NextPlay();
            return;
        }
    }
}

void GameMain::NextPlay()
{
    list.ClearBoard();
    now=black;
    delete TheBoard;
    delete P[0];
    delete P[1];
    SetGame(Mode,First);
}

void GameMain::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void GameMain::print_winner(const int& winner)
{
    char w[2][40]={"The winner is Player Black!","The winner is Player White!"};
    int ret = QMessageBox::question(this,tr("提示"),tr(w[winner-1]),QMessageBox::Yes);
    if(ret == QMessageBox::Yes)
    {
        NextPlay();
    }
}

void GameMain::return_start()
{
    this->close();
    Start *w=new Start();
    w->show();
}

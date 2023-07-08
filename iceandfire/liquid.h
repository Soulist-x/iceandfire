#ifndef LIQUID_H
#define LIQUID_H
#include <QLabel>
#include <QMovie>
#include <icegirl.h>
#include <fireboy.h>
#include <die.h>

class liquid:public QLabel
{
public:
    int _x,_y;
    int _dx,_dy;
    QMovie *movie_01;//中间
    QMovie *movie_02;//左边角
    QMovie *movie_03;//右边角
public:
    liquid();
    void Stay1(int x,int y);
    void Stay2(int x,int y);
    void Stay3(int x,int y);
};
#endif // LIQUID_H

class lava:public liquid
{
public:
    lava() ;
    void Die(const Block &x, icegirl &_icegirl, die &_die) ;
};

class water:public liquid
{
public:
    water() ;
    void Die(const Block &x, fireboy &_fireboy,die &_die) ;
};

class poison:public liquid {
public:
    poison() ;
    void Die(const Block &x, icegirl &_icegirl, fireboy &_fireboy,die &_die) ;
} ;

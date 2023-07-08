#ifndef OBJECT_H
#define OBJECT_H


#include <QImage>
#include <QPixmap>
#include <QMovie>
#include <config.h>
#include <QString>
#include <block.h>
#include <QLabel>
#include <icegirl.h>
#include <fireboy.h>

class object : public QLabel
{
public:
    int _x,_y;
    int _dx,_dy;//碰撞体积
    int _del, _ins ;
    QPixmap img ;
    friend class icegirl ;
    friend class fireboy ;
    friend class level;
    object();
    void Stay2(int x, int y, Block &map_block) ;
    void Resize(int x, int y, Block &map_block) ;
    void del(Block &x) ;
    void ins(Block &x) ;
};



class diamond : public object
{
public:
    int _flag ;
    diamond() ;
};
class ice_diamond : public diamond
{
public:
    ice_diamond() ;
    ice_diamond(Block &map_block) ;
    void Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) ;
};
class fire_diamond : public diamond
{
public:
    fire_diamond() ;
    fire_diamond(Block &map_block) ;
    void Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) ;
};


class door:public object
{
public:
    int _flag ;
    door();
    void Resize(int x, int y) ;
};
class ice_door:public door {
public:
    ice_door() ;
    void Stay(Block &x, icegirl &_icegirl) ;
};
class fire_door:public door{
public:
    fire_door() ;
    void Stay(Block &x, fireboy &_fireboy) ;
};


class mechanism : public object
{
public:
    int speed_x,speed_y,_count;
    int _limit ;
    mechanism() ;
};

class mechanism1 : public mechanism
{
public:
    mechanism1() ;
    mechanism1(Block &x) ;
    void init() ;
    void Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) ;
};

class mechanism2 : public mechanism
{
public:
    int Speed_x, Speed_y, LS, RS ;
    QString S1, S2 ;
    mechanism2() ;
    mechanism2(Block &x) ;
    mechanism2(Block &x, int dx, int dy, int BSx, int BSy, int _LS, int _RS, QString _S1, QString _S2) ;
    void init() ;
    void Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) ;
};


class mechanismbegin : public object
{
public:
    int _flag ;
    mechanismbegin() ;
};

class mechanismbegin1 : public mechanismbegin
{
public:
    friend class mechanism1 ;
    mechanismbegin1() ;
    mechanismbegin1(Block &x) ;
    void Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy, mechanism1 &u) ;

};


class mechanismbegin2 : public mechanismbegin
{
public:
    friend class mechanism2 ;
    QString S ;
    mechanismbegin2() ;
    mechanismbegin2(Block &x, QString _S) ;
    void Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy, mechanism2 &u) ;

};

class wind : public object {
public:
    QMovie *movie = nullptr ;
    wind() ;
    wind(Block &x) ;
    void Stay(int x, int y) ;
    void Ins(Block &x) ;
};

#endif // OBJECT_H

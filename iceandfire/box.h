#ifndef BOX_H
#define BOX_H
#include <QImage>
#include <QPixmap>
#include <QMovie>
#include <config.h>
#include <QString>
#include <block.h>
#include <QLabel>
#include <icegirl.h>
#include <fireboy.h>

class box:public QLabel
{
public:
    int _x,_y;
    int _dx,_dy;//碰撞体积
    int speed_x,speed_y,_count;
    QPixmap img ;
    friend class icegirl ;
    friend class fireboy ;
    friend class level;
public:
    box();
    box(Block& map_block);
    void del(Block &map_block) ;
    void ins(Block &map_block) ;
    void Resize(int x,int y);
    void Stay(int x,int y, Block &map_block);
    void Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) ;
    void be_pushed(Block &map_block, icegirl &_icegirl, fireboy &_fireboy);

    //碰撞体积
    void check_r(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) ;
    void check_l(Block &map_block) ;
};

#endif // BOX_H

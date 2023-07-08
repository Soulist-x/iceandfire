#include "box.h"
#include <QApplication>
#include <QLabel>
#include <QPainter>
#include <QTimer>

box::box(Block& map_block)
{
    img.load(BOX);
    _x=_y=0;
    speed_x=speed_y=_count=0;
    Resize(45,45);
    for(int i=_x;i<_x+_dx;++i){
        for(int j=_y;j<_y+_dy;++j){
            map_block.block[i][j] = 3 ;
        }
    }
}
void box::Resize(int x, int y) {
    this->resize(x, y) ;
    _dx = x, _dy = y ;
}
void box::Stay(int x, int y, Block &map_block) {
    del(map_block) ;
    _x = x, _y = y ;
    move(x, y) ;
    ins(map_block) ;
    this->setPixmap(img);
    this->setScaledContents(true);
    this->show() ;
}
void box::del(Block &map_block) {
    for(int i=_x;i<_x+_dx;++i){
        for(int j=_y;j<_y+_dy;++j){
            map_block.block[i][j] = 0 ;
        }
    }
}
void box::ins(Block &map_block) {
    for(int i=_x;i<_x+_dx;++i){
        for(int j=_y;j<_y+_dy;++j){
            map_block.block[i][j] = 3 ;
        }
    }
}
void box::check_r(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) {
    if(_icegirl.check_box(map_block) && _icegirl.speed_x < 0) _icegirl.speed_x = -1, speed_x = -1, _count = 0 ;
    if(_fireboy.check_box(map_block) && _fireboy.speed_x < 0) _fireboy.speed_x = -1, speed_x = -1, _count = 0 ;
}
void box::be_pushed(Block &map_block, icegirl &_icegirl, fireboy &_fireboy){//被小人推动之后速度向左变成-1
    check_r(map_block, _icegirl, _fireboy) ;
}
void box::check_l(Block &map_block) {
    for(int i = 3; i < 24; ++ i)
        if(map_block.block[_x][_y + i] == 1) {
            _x ++ ; return ;
        }
}
void box::Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) { //每次行动，刷新当前图像，被计时器 _Show 绑定
    be_pushed(map_block, _icegirl, _fireboy) ;
    del(map_block) ;
    _x += speed_x, _y += speed_y, _count ++ ;
    check_l(map_block) ;
    ins(map_block) ;
    if(_count == 10) speed_x = 0 ;
    move(_x, _y) ;
    this->show() ;
}

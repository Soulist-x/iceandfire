#include "object.h"
#include <stdlib.h>
object::object()
{
    _x = _y = _dx = _dy = 0 ;
    _ins = 1, _del = 0 ;
}
void object::del(Block &map_block) {
    for(int i=_x;i<_x+_dx;++i){
        for(int j=_y;j<_y+_dy;++j){
            map_block.block[i][j] = _del ;
        }
    }
}
void object::ins(Block &map_block) {
    for(int i=_x;i<_x+_dx;++i){
        for(int j=_y;j<_y+_dy;++j){
            map_block.block[i][j] = _ins ; //0 空气，1 地板，2 水池，3 箱子，4 表示机关
        }
    }
}
void object::Resize(int x, int y, Block &map_block) {
    this->resize(x, y) ;
    _dx = x, _dy = y ;
}

void object::Stay2(int x, int y, Block &map_block) {
    _x = x, _y = y ;
    move(x, y) ;
    del(map_block) ;
    this->setPixmap(img);
    this->setScaledContents(true);
    this->show() ;
}
mechanismbegin::mechanismbegin()
{
    _flag = 0 ;
    _ins = 4, _del = 1 ;
}

mechanismbegin1::mechanismbegin1(Block &x)
{
    img.load(MECHANISM1_4) ;
    _x = _y = _flag = 0 ;
    Resize(43, 16, x) ;
}
void mechanismbegin1::Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy, mechanism1 &u) { //每次行动，刷新当前图像，被计时器 _Show 绑定
    ins(map_block) ; img.load(MECHANISM1_4) ;
    if(_icegirl.check_mechanism1(map_block)|| _fireboy.check_mechanism1(map_block) || _flag) {
        u.speed_y = 1, _flag = 1, img.load(MECHANISM1_3) ;
    }
    this->setPixmap(img);
    this->setScaledContents(true);
    this->show() ;
    del(map_block) ;
}
mechanismbegin2::mechanismbegin2(Block &x, QString _S)
{
    S = _S ;
    img.load(S) ;
    _x = _y = _del = 0 ;
    Resize(44, 16, x) ;
}
void mechanismbegin2::Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy, mechanism2 &u) { //每次行动，刷新当前图像，被计时器 _Show 绑定
    ins(map_block) ;
    if(_icegirl.check_mechanism2(map_block) || _fireboy.check_mechanism2(map_block)) {
        u.speed_y = -u.Speed_y, u.speed_x = -u.Speed_x, u.img.load(u.S2) ; this->close() ;
    }
    else this->show() ;
    del(map_block) ;
}


diamond::diamond() {
    _flag = 0, _del = 0, _ins = 6 ;
}
ice_diamond::ice_diamond(Block &map_block)
{
    img.load(ICE_DIAMOND) ;
    _x = _y = _flag = 0 ;
    Resize(30, 26, map_block) ;
}
fire_diamond::fire_diamond(Block &map_block)
{
    img.load(FIRE_DIAMOND) ;
    _x = _y = _flag = 0 ;
    Resize(30, 26, map_block) ;
}
void ice_diamond::Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) { //每次行动，刷新当前图像，被计时器 _Show 绑定
    ins(map_block) ;
    if(_icegirl.check_diamond(map_block) || _flag) {
        _flag ++, this -> close() ;
        if(_flag == 1) _icegirl._get_diamond ++ ;
    }
    else this->show() ;
    del(map_block) ;
}
void fire_diamond::Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) { //每次行动，刷新当前图像，被计时器 _Show 绑定
    ins(map_block) ;
    if(_fireboy.check_diamond(map_block) || _flag) {
        _flag ++, this -> close() ;
        if(_flag == 1) _fireboy._get_diamond ++ ;
    }
    else this->show() ;
    del(map_block) ;
}



door::door()
{
    _x = _y = _flag = 0 ;
    _ins = 6, _del = 0 ;
    Resize(50,60);
}
void door::Resize(int x, int y) {
    this->resize(x, y) ;
    _dx = x, _dy = y ;
}

fire_door::fire_door() {
    img.load(_FIRE_DOOR) ;
}
ice_door::ice_door() {
    img.load(_ICE_DOOR);
}
void ice_door::Stay(Block &map_block, icegirl &_icegirl) {
    ins(map_block) ;
    if(_icegirl.check_diamond(map_block)) _flag = 1 ;
    else _flag = 0 ;
    this->show() ;
    del(map_block) ;
}
void fire_door::Stay(Block &map_block, fireboy &_fireboy) {
    ins(map_block) ;
    if(_fireboy.check_diamond(map_block)) _flag = 1 ;
    else _flag = 0 ;
    this->show() ;
    del(map_block) ;
}


mechanism::mechanism() {
    _x = _y = _count = 0 ; _limit = 70 ;
    speed_x = 0, speed_y = 0 ;
}
void mechanism1::init() {
    speed_y = 0 ;
}
mechanism1::mechanism1(Block &x)
{
    img.load(MECHANISM1_1) ;
    _x = _y = _count = 0 ; _limit = 70 ;
    speed_x = 0, speed_y = 0 ;
    Resize(120, 25, x) ;
}
void mechanism1::Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) { //每次行动，刷新当前图像，被计时器 _Show 绑定
    del(map_block) ;
    _x += speed_x ;
    if(speed_y < 0 && _count > 0) _y += speed_y, _count += speed_y ;
    if(speed_y > 0 && _count < _limit) img.load(MECHANISM1_2), _y += speed_y, _count += speed_y ;
    ins(map_block) ;
    move(_x, _y) ;
    this->setPixmap(img);
    this->setScaledContents(true);
    this->show() ;
}

mechanism2::mechanism2(Block &x)
{
    S1 = S2 = MECHANISM2_1 ;
    img.load(MECHANISM2_1) ;
    _x = _y = _count = 0 ; _limit = 90 ;
    LS = 0, RS = 90 ;
    speed_x = 0, speed_y = 0 ;
    Speed_y = -1, Speed_x = 0 ;
    Resize(120, 20, x) ;
}
mechanism2::mechanism2(Block &x, int dx, int dy, int BSx, int BSy, int _LS, int _RS, QString _S1, QString _S2) {
    S1 = _S1, S2 = _S2 ;
    img.load(S1) ;
    _x = _y = _count = 0 ; _limit = 0 ;
    LS = _LS, RS = _RS ;
    speed_x = 0, speed_y = 0 ;
    Speed_x = BSx, Speed_y = BSy ;
    Resize(dx, dy, x) ;
}
void mechanism2::init() {
    img.load(S1) ;
    speed_x = Speed_x, speed_y = Speed_y ;
}
void mechanism2::Stay(Block &map_block, icegirl &_icegirl, fireboy &_fireboy) { //每次行动，刷新当前图像，被计时器 _Show 绑定
    del(map_block) ;
    if(speed_x < 0 && _count > LS) _x += speed_x, _count += speed_x ;
    if(speed_x > 0 && _count < RS) _x += speed_x, _count += speed_x ;
    if(speed_y < 0 && _count > LS) _y += speed_y, _count += speed_y ;
    if(speed_y > 0 && _count < RS) _y += speed_y, _count += speed_y ;
    ins(map_block) ;
    move(_x, _y) ;

    this->setPixmap(img);
    this->setScaledContents(true);
    this->show() ;
}

wind::wind(Block &x) {
    movie = new QMovie(WIND) ;
    Resize(70, 260, x) ;
}
void wind::Stay(int x, int y) {
    _x = x, _y = y ;
    move(x, y) ;
    this->setMovie(movie) ;
    movie->start() ;
    this->show() ;
}
//48, 84
void wind::Ins(Block &x) {
    //50 对应中值点
    //
    for(int j = _y; j < _y + _dy; ++ j) for(int i = _x; i < _x + _dx; ++ i) {
            int u = j - _y ;
            u /= 40 ;
            if(u == 0) x.block[i][j] = 20 ;
            else x.block[i][j] = 20 + ((u + 1) / 2) - rand() % 2 ;
    }
}

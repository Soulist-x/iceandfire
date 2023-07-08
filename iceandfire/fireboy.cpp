#include "config.h"
#include "fireboy.h"
#include <QPainter>
#include <QPixmap>
#define rep( i, s, t ) for(int i = (s); i <= (t); ++ i)
fireboy::fireboy()
{
    movie = new QMovie(FIREBOY_STAND) ;
    _x = _y = alive = _get_diamond = 0 ;
    speed_x = speed_y = _count = _limit = 0 ;
    _dx = 24, _dy = 51 ;
    for(int i = 0; i < 8; ++ i) dq_x[i] = dq_y[i] = 0 ;
    dq_y[fireboy_up] = +19 ;
    dq_y[fireboy_down] = 0 ;
    dq_y[fireboy_jump_right] = 14 ;
    dq_y[fireboy_jump_left] = 14 ;
    dq_y[fireboy_run_left] = 14 ;
    dq_y[fireboy_run_right] = 14 ;
    dq_x[fireboy_jump_right] = -12 ;
    dq_x[fireboy_run_right] = -12 ;
    State = 0 ;
}
int fireboy::lx() {
    return _x + dq_x[State] ;
}
int fireboy::ly() {
    return _y + dq_y[State] ;
}
void fireboy::Resize(int x, int y) {
    this->resize(x, y) ;
    _dx = x, _dy = y ;
}
void fireboy::Stay(int x, int y) {
    _x = x, _y = y ;
    move(x, y) ;
    this->setMovie(movie) ;
    movie->start() ;
    this->show() ;
}
void fireboy::Change_S(QString gif, int x, int y, int if_hair) { //改变图层
    movie = new QMovie(gif), this->Resize(x, y) ;
    _hair = if_hair ;
    this->setMovie(movie) ;
    movie->start() ;
}
int fireboy::if_stay_sky(const Block &map_block) {
    int ll = 9, rr = 18 ;
    if(State == fireboy_run_right || State == fireboy_jump_right) ll = 22, rr = 28 ;
    if(State == fireboy_run_left || State == fireboy_jump_left) ll = 7, rr = 13 ;
    for(int i = ll; i < rr; ++ i)
        for(int k = -2; k <= 0; ++ k)
            if(check(map_block.block[lx() + i][ly() + _dy + k])) {
                _y += k ;
                return 1 ;
            }
    return 0 ;
}
void fireboy::Run(int x) { //跑步动作
    speed_x = 2 * x ;
}
void fireboy::Jump(const Block &map_block) { // 跳跃动作
    if(if_stay_sky(map_block)) speed_y = -3, _count = 0 ;
}
void fireboy::Stop_x(int x) { //运动停止函数
    if(speed_x * x <= 0) return ; //表示 AD 键同时被按下，此时不做暂停。
    speed_x = 0 ;
}
void fireboy::Change_State() { //改变当前人物的图像
    int newState = 0 ;
    if(speed_x == 0 && speed_y == 0) newState = fireboy_stand ;
    if(speed_x == 0 && speed_y < 0) newState = fireboy_up ;
    if(speed_x == 0 && speed_y > 0) newState = fireboy_down ;
    if(speed_x > 0 && speed_y == 0) newState = fireboy_run_right ;
    if(speed_x < 0 && speed_y == 0) newState = fireboy_run_left ;
    if(speed_x > 0 && speed_y != 0) newState = fireboy_jump_right ;
    if(speed_x < 0 && speed_y != 0) newState = fireboy_jump_left ;
    if(newState == State) return ;
    State = newState ;
    if(State == fireboy_stand) Change_S(FIREBOY_STAND, 24, 51, 0) ;
    if(State == fireboy_up) Change_S(FIREBOY_UP, 24, 37, 0) ;
    if(State == fireboy_down) Change_S(FIREBOY_DOWN, 24, 51, 1) ;
    if(State == fireboy_jump_left) Change_S(FIREBOY_JUMP_LEFT, 36, 37, 0) ;
    if(State == fireboy_jump_right) Change_S(FIREBOY_JUMP_RIGHT, 36, 37, 0) ;
    if(State == fireboy_run_left) Change_S(FIREBOY_RUN_LEFT, 36, 37, 0) ;
    if(State == fireboy_run_right) Change_S(FIREBOY_RUN_RIGHT, 36, 37, 0) ;
}
int fireboy::check(int x) {
    return (x == 1) || (x == 3) ;
}
void fireboy::check_r(const Block &x) {
    for(int i = 2; i < 20; ++ i) for(int j = 2; j >= 1; -- j)
            if(check(x.block[lx() + _dx - j][ly() + i])) {
                _x -= j ; return ;
            }
}
void fireboy::check_l(const Block &x) {
    for(int i = 2; i < 20; ++ i) for(int j = 2; j >= 1; -- j)
            if(check(x.block[lx() + j - 1][ly() + i])) {
                _x += j ; return ;
            }
}
void fireboy::check_u(const Block &x) {
    int ll = 4, rr = 20 ;
    if(State == fireboy_jump_right) ll = 19, rr = 33 ;
    if(State == fireboy_jump_left) ll = 5, rr = 21 ;
    for(int i = ll; i < rr; ++ i) for(int j = 2; j >= 0; -- j)
            if(check(x.block[lx() + i][ly() + j - 1])) {
                _y += j, speed_y = -speed_y, _count = 0 ; return ;
            }
}
void fireboy::check(const Block &map_block) {
    if(State == fireboy_run_right || State == fireboy_jump_right) check_r(map_block) ;
    if(State == fireboy_run_left || State == fireboy_jump_left) check_l(map_block) ;
    if(State == fireboy_up || State == fireboy_jump_left || State == fireboy_jump_right) check_u(map_block) ;
}
void fireboy::Stay(const Block &map_block) { //每次行动，刷新当前图像，被计时器 _Show 绑定
    if(alive) return ;
    _x += speed_x, _y += speed_y ;
    check(map_block) ;
    if(if_stay_sky(map_block)) speed_y = _count = 0 ;
    else {
        _count ++ ;
        if(_count == 10) speed_y ++, _count = 0 ;
        if(speed_y == 4) speed_y = 3 ;
    }
    Change_State() ;
    move(lx(), ly()) ;

    this->show() ;
}
void fireboy::Change(int x, int y, const Block &map_block) {
    if(x) Run(x) ;
    if(y == -1) Jump(map_block) ;
}
int fireboy::check_box(const Block &x) {
    for(int i = 3; i < 24; ++ i) for(int j = 2; j >= -1; -- j)
            if(x.block[lx() + j - 1][ly() + i] == 3) {
                return 1 ;
            }
    return 0 ;
}
int fireboy::check_mechanism2(const Block &x) {
    int ll = 4, rr = 20 ;
    if(State == fireboy_run_right || State == fireboy_jump_right) ll = 19, rr = 33 ;
    if(State == fireboy_run_left || State == fireboy_jump_left) ll = 5, rr = 21 ;
    for(int i = ll; i < rr; ++ i) for(int j = 10; j >= 1; -- j)
            if(x.block[lx() + i][ly() + _dy - j] == 4) {
                return 1 ;
            }
    return 0 ;
}
int fireboy::check_mechanism1(const Block &x) {
    int ll = 4, rr = 20 ;
    if(State == fireboy_run_right || State == fireboy_jump_right) ll = 19, rr = 33 ;
    if(State == fireboy_run_left || State == fireboy_jump_left) ll = 5, rr = 21 ;
    for(int i = ll; i < rr; ++ i) for(int j = 5; j >= -5; -- j)
            if(x.block[lx() + i][ly() + _dy - j] == 4) {
                return 1 ;
            }
    return 0 ;
}
int fireboy::check_water(const Block &x, int c) {
    int ll = 4, rr = 20 ;
    if(State == fireboy_run_right || State == fireboy_jump_right) ll = 19, rr = 33 ;
    if(State == fireboy_run_left || State == fireboy_jump_left) ll = 5, rr = 21 ;
    for(int i = ll; i < rr; ++ i) for(int j = 0; j <= 1; ++ j)
            if(x.block[lx() + i][ly() + _dy + j] == c) {
                return 1 ;
            }
    return 0 ;
}
int fireboy::check_diamond(const Block &x) {
    for(int i = 0; i < _dx; ++ i) for(int j = 0; j < _dy; ++ j)
            if(x.block[lx() + i][ly() + j] == 6) return 1 ;
    return 0 ;
}
void fireboy::dead() {
    alive = 1 ;
    Change_S(DEAD, 72, 46, 0) ;
    move(lx(), ly() - 12) ;
    this -> show() ;
}

void fireboy::check_wind(const Block &x) {
    int d = x.block[_x + 10][_y + _dy] ;
    if(d >= 20) {
        _limit += (d - 20) ;
        while(_limit >= 10) _limit -= 10, -- speed_y ;
    }
}

//void fireboy::paintEvent(QPaintEvent *event){

//}

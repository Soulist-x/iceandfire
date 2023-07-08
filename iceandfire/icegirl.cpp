#include "config.h"
#include "icegirl.h"
#include <QPainter>
#include <QPixmap>
#define rep( i, s, t ) for(int i = (s); i <= (t); ++ i)
icegirl::icegirl()
{
    movie = new QMovie(ICEGIRL_STAND) ;
    _x = _y = alive = _get_diamond = 0 ;
    speed_x = speed_y = _count = _limit = 0 ;
    _dx = 26, _dy = 42 ;
    for(int i = 0; i < 8; ++ i) dq_x[i] = dq_y[i] = 0 ;
    dq_y[icegirl_down] = -19 ;
    dq_x[icegirl_jump_right] = -19 ;
    dq_x[icegirl_run_right] = -19 ;
    State = 0 ;
}
int icegirl::lx() {
    return _x + dq_x[State] ;
}
int icegirl::ly() {
    return _y + dq_y[State] ;
}
void icegirl::Resize(int x, int y) {
    this->resize(x, y) ;
    _dx = x, _dy = y ;
}
void icegirl::Stay(int x, int y) {
    _x = x, _y = y ;
    move(x, y) ;
    this->setMovie(movie) ;
    movie->start() ;
    this->show() ;
}
void icegirl::Change_S(QString gif, int x, int y, int if_hair) { //改变图层
    movie = new QMovie(gif), this->Resize(x, y) ;
    _hair = if_hair ;
    this->setMovie(movie) ;
    movie->start() ;
}
int icegirl::if_stay_sky(const Block &map_block) {
    int ll = 9, rr = 18 ;
    if(State == icegirl_run_right || State == icegirl_jump_right) ll = 30, rr = 35 ;
    if(State == icegirl_run_left || State == icegirl_jump_left) ll = 10, rr = 15 ;
    for(int i = ll; i < rr; ++ i)
        for(int k = -2; k <= 0; ++ k)
            if(check(map_block.block[lx() + i][ly() + _dy + k])) {
                _y += k ;
                return 1 ;
            }
    return 0 ;
}
void icegirl::Run(int x) { //跑步动作
    speed_x = 2 * x ;
}
void icegirl::Jump(const Block &map_block) { // 跳跃动作
    if(if_stay_sky(map_block)) speed_y = -3, _count = 0 ;
}
void icegirl::Stop_x(int x) { //运动停止函数
    if(speed_x * x <= 0) return ; //表示 AD 键同时被按下，此时不做暂停。
    speed_x = 0 ;
}
void icegirl::Change_State() { //改变当前人物的图像
    int newState = 0 ;
    if(speed_x == 0 && speed_y == 0) newState = icegirl_stand ;
    if(speed_x == 0 && speed_y < 0) newState = icegirl_up ;
    if(speed_x == 0 && speed_y > 0) newState = icegirl_down ;
    if(speed_x > 0 && speed_y == 0) newState = icegirl_run_right ;
    if(speed_x < 0 && speed_y == 0) newState = icegirl_run_left ;
    if(speed_x > 0 && speed_y != 0) newState = icegirl_jump_right ;
    if(speed_x < 0 && speed_y != 0) newState = icegirl_jump_left ;
    if(newState == State) return ;
    State = newState ;
    if(State == icegirl_stand) Change_S(ICEGIRL_STAND, 26, 42, 0) ;
    if(State == icegirl_up) Change_S(ICEGIRL_UP, 26, 42, 0) ;
    if(State == icegirl_down) Change_S(ICEGIRL_DOWN, 26, 61, 1) ;
    if(State == icegirl_jump_left) Change_S(ICEGIRL_JUMP_LEFT, 44, 42, 0) ;
    if(State == icegirl_jump_right) Change_S(ICEGIRL_JUMP_RIGHT, 44, 42, 0) ;
    if(State == icegirl_run_left) Change_S(ICEGIRL_RUN_LEFT, 44, 42, 0) ;
    if(State == icegirl_run_right) Change_S(ICEGIRL_RUN_RIGHT, 44, 42, 0) ;
}
int icegirl::check(int x) {
    return (x == 1) || (x == 3) ;
}
void icegirl::check_r(const Block &x) {
    for(int i = 3; i < 24; ++ i) for(int j = 2; j >= 1; -- j)
            if(check(x.block[lx() + _dx - j][ly() + i])) {
            _x -= j ; return ;
        }
}
void icegirl::check_l(const Block &x) {
    for(int i = 3; i < 24; ++ i) for(int j = 2; j >= 1; -- j)
        if(check(x.block[lx() + j - 1][ly() + i])) {
            _x += j ; return ;
        }
}
void icegirl::check_u(const Block &x) {
    int ll = 9, rr = 20 ;
    if(State == icegirl_jump_right) ll = 19, rr = 40 ;
    if(State == icegirl_jump_left) ll = 3, rr = 24 ;
    for(int i = ll; i < rr; ++ i) for(int j = 2; j >= 0; -- j)
        if(check(x.block[lx() + i][ly() + j - 1])) {
            _y += j, speed_y = -speed_y, _count = 0 ; return ;
        }
}
void icegirl::check(const Block &map_block) {
    if(State == icegirl_run_right || State == icegirl_jump_right) check_r(map_block) ;
    if(State == icegirl_run_left || State == icegirl_jump_left) check_l(map_block) ;
    if(State == icegirl_up || State == icegirl_jump_left || State == icegirl_jump_right) check_u(map_block) ;
}
void icegirl::Stay(const Block &map_block) { //每次行动，刷新当前图像，被计时器 _Show 绑定
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
void icegirl::Change(int x, int y, const Block &map_block) {
    if(x) Run(x) ;
    if(y == -1) Jump(map_block) ;
}
int icegirl::check_box(const Block &x) {
    for(int i = 3; i < 24; ++ i) for(int j = 2; j >= -1; -- j)
        if(x.block[lx() + j - 1][ly() + i] == 3) {
            return 1 ;
        }
    return 0 ;
}
int icegirl::check_mechanism2(const Block &x) {
    int ll = 9, rr = 20 ;
    if(State == icegirl_run_right || State == icegirl_jump_right) ll = 19, rr = 40 ;
    if(State == icegirl_run_left || State == icegirl_jump_left) ll = 3, rr = 24 ;
    for(int i = ll; i < rr; ++ i) for(int j = 10; j >= 1; -- j)
        if(x.block[lx() + i][ly() + _dy - j] == 4) {
            return 1 ;
        }
    return 0 ;
}
int icegirl::check_mechanism1(const Block &x) {
    int ll = 9, rr = 20 ;
    if(State == icegirl_run_right || State == icegirl_jump_right) ll = 19, rr = 40 ;
    if(State == icegirl_run_left || State == icegirl_jump_left) ll = 3, rr = 24 ;
    for(int i = ll; i < rr; ++ i) for(int j = 5; j >= -5; -- j)
        if(x.block[lx() + i][ly() + _dy - j] == 4) {
            return 1 ;
        }
    return 0 ;
}
int icegirl::check_water(const Block &x, int c) {
    int ll = 9, rr = 20 ;
    if(State == icegirl_run_right || State == icegirl_jump_right) ll = 19, rr = 40 ;
    if(State == icegirl_run_left || State == icegirl_jump_left) ll = 3, rr = 24 ;
    for(int i = ll; i < rr; ++ i) for(int j = 0; j <= 1; ++ j)
        if(x.block[lx() + i][ly() + _dy + j] == c) {
            return 1 ;
        }
    return 0 ;
}
int icegirl::check_diamond(const Block &x) {
    for(int i = 0; i < _dx; ++ i) for(int j = 0; j < _dy; ++ j)
        if(x.block[lx() + i][ly() + j] == 6) return 1 ;
    return 0 ;
}
void icegirl::dead() {
    alive = 1 ;
    Change_S(DEAD, 72, 46, 0) ;
    move(lx(), ly() - 12) ;
    this -> show() ;
}

void icegirl::check_wind(const Block &x) {
    int d = x.block[_x + 10][_y + _dy] ;
    if(d >= 20) {
        _limit += (d - 20) ;
        while(_limit >= 10) _limit -= 10, -- speed_y ;
    }
}

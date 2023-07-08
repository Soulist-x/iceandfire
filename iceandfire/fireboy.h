#ifndef FIREBOY_H
#define FIREBOY_H

#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QMovie>
#include <config.h>
#include <QString>
#include <block.h>

#define fireboy_stand 0
#define fireboy_up 1
#define fireboy_down 2
#define fireboy_run_left 3
#define fireboy_run_right 4
#define fireboy_jump_left 5
#define fireboy_jump_right 6

class fireboy:public QLabel
{

public:
    fireboy();
    int _x, _y ;
    int speed_x, speed_y, _count, _limit ; //速度向量
    //动作包括：站立，上跳，下跳，左跑，右跑，左跳，右跳 7 类
    //依次用 0，1，2，3，4，5，6，7 表示
    int State, alive ;
    int dq_y[8], dq_x[8] ; //对齐参数
    int lx() ;
    int ly() ;
    int if_stay_sky(const Block &map_block) ;
    void Resize(int x, int y) ;
    void Stay(int x, int y) ;
    void Stay(const Block &x) ;
    void Change_S(QString gif, int x, int y, int if_hair) ;
    void Change_State() ;
    void Stop_x(int x) ;
    void Jump(const Block &map_block) ;
    void Run(int x) ;
    void Change(int x, int y, const Block &map_block) ;
    //碰撞体积
    //_x+dq_x[State], _x+_dy
    //_y, _y+_dy 为所围对象
    int _dx, _dy, _hair ; //是否要判断穿模的头发
    int check(int x) ;
    void check(const Block &x) ;
    void check_r(const Block &x) ;
    void check_l(const Block &x) ;
    //void check_d(const Block &x) ;
    void check_u(const Block &x) ;
    int check_box(const Block &x) ;
    int check_mechanism2(const Block &x) ;
    int check_mechanism1(const Block &x) ;
    int check_water(const Block &x, int c) ;
    int check_diamond(const Block &x) ;
    void check_wind(const Block &x) ;
    int _get_diamond ;
    void dead() ;
    //void paintEvent(QPaintEvent *event);
    QMovie *movie = nullptr ;


};

#endif // FIREBOY_H

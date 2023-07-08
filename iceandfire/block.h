#ifndef BLOCK_H
#define BLOCK_H
#include <string.h>

class Block //地图类
{
public:
    Block();
    //绘制地图的函数
    void draw(int x,int y,int xx,int yy);
    void draw_(int x,int y,int xx,int yy);
    void draw2_(int x,int y,int xx,int yy);
    void draw1(int x,int y,int xx,int yy);
    void draw21(int x,int y,int xx,int yy);
    void draw_water(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4, int c) ;
    void draw_wind(int x,int y,int xx,int yy) ;
    int block[1130][830] ;
    void Block2() ;
    void Block3() ;
};

#endif // BLOCK_H

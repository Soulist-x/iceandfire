#include "pic.h"

pic::pic(QString u, int x, int y)
{
    img.load(u) ;
    this->resize(x, y) ;
    _dx = x, _dy = y ;
}
void pic::Stay(int x, int y) {
    _x = x, _y = y ;
    move(x, y) ;
    this->setPixmap(img);
    this->setScaledContents(true);
    this->show() ;
}
void pic::ins(Block &map_block) {
    for(int i=_x;i<_x+_dx;++i){
        for(int j=_y;j<_y+_dy;++j){
            map_block.block[i][j] = 1 ; //0 空气，1 地板，2 水池，3 箱子，4 表示机关
        }
    }
}

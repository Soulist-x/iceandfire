#include "die.h"
#include <config.h>
#include <QPixmap>

die::die()
{
    img.load(GAMEOVER);
    move(0, 0), _count = 0, _flag = 0 ;
}
void die::DIE(){
    ++ _count ;
    if(_count == 130) {
        move(0, 0) ;
        this->resize(1024, 720) ;
        this->setPixmap(img);
        this->setScaledContents(true);
        this->show() ;
    }
}

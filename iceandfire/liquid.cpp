#include "liquid.h"
#include <config.h>
#include <QLabel>

liquid::liquid()
{
    _x=_y=0;
}
void liquid::Stay1(int x,int y){
    _x = x, _y = y ;
    move(x, y) ;
    this->setMovie(movie_01) ;
    movie_01->start() ;
    this->show() ;
}
void liquid::Stay2(int x,int y){
    _x = x, _y = y ;
    move(x, y) ;
    this->setMovie(movie_02) ;
    movie_02->start() ;
    this->show() ;
}
void liquid::Stay3(int x,int y){
    _x = x, _y = y ;
    move(x, y) ;
    this->setMovie(movie_03) ;
    movie_03->start() ;
    this->show() ;
}

poison::poison()
{
    movie_01 = new QMovie(POISON_01);
    movie_02 = new QMovie(POISON_02);
    movie_03 = new QMovie(POISON_03);
    _x=_y=0;
}

water::water()
{
    movie_01 = new QMovie(WATER_01);
    movie_02 = new QMovie(WATER_02);
    movie_03 = new QMovie(WATER_03);
    _x=_y=0;
}

lava::lava()
{
    movie_01 = new QMovie(LAVA_01);
    movie_02 = new QMovie(LAVA_02);
    movie_03 = new QMovie(LAVA_03);
    _x=_y=0;
}
void lava::Die(const Block &x, icegirl &_icegirl, die &_die){
    if(_icegirl.check_water(x, 10)) _die.DIE(), _icegirl.dead() ;
}

void water::Die(const Block &x, fireboy &_fireboy,die &_die){
    if(_fireboy.check_water(x, 11)) _die.DIE(), _fireboy.dead() ;
}
void poison::Die(const Block &x, icegirl &_icegirl, fireboy &_fireboy,die &_die) {
    if(_icegirl.check_water(x, 12)) _die.DIE(), _icegirl.dead() ;
    if(_fireboy.check_water(x, 12)) _die.DIE(), _fireboy.dead() ;
}

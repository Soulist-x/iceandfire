#ifndef DIE_H
#define DIE_H
#include <icegirl.h>
#include <fireboy.h>

class die:public QLabel
{
public:
    QPixmap img;
public:
    int _count, _flag ;
    die();
    void DIE();
};

#endif // DIE_H

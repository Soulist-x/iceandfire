#ifndef PIC_H
#define PIC_H
#include<QPixmap>
#include<QString>
#include<QLabel>
#include<block.h>

class pic : public QLabel
{
public:
    QPixmap img;
    int _dx, _dy ;
    int _x, _y ;
    friend class Block ;
public:
    pic() ;
    pic(QString u, int x, int y) ;
    void Stay(int x, int y) ;
    void ins(Block &x) ;
};

#endif // PIC_H

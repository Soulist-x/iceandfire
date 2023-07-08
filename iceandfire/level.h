#ifndef LEVEL_H
#define LEVEL_H

#include <config.h>
#include <QWidget>
#include <map.h>
#include <icegirl.h>
#include <QKeyEvent>
#include <QTimer>
#include <block.h>
#include <box.h>
#include <icegirl.h>
#include <fireboy.h>
#include <object.h>
#include <liquid.h>
#include <pic.h>

class QLabel_C: public QLabel{
    Q_OBJECT
public:
    QLabel_C(QWidget* parent = nullptr) : QLabel(parent) {}
    virtual void mousePressEvent(QMouseEvent* event) override{
        if (event->button() == Qt::LeftButton){
            emit clicked();
            //printf("Label clicked!\n");
        }
        QLabel::mousePressEvent(event);
    }
signals:
    void clicked();
};

class level : public QWidget
{
    Q_OBJECT

public:
    level(QWidget *parent = nullptr, int type = 0, int n1 = 0, int n2 = 0, int A = 0, int B = -1, int C = -1);
    ~level() ;
private:
    void paintEvent(QPaintEvent *event) ;
    void paintEvent(QPaintEvent *event, int x, int y) ;
    Map m_map ; //背景地图
    icegirl *_icegirl = nullptr ;
    fireboy *_fireboy = nullptr ;

    //按键相关：
protected:
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);

private:
    QTimer *_Show; //计时器
    void toShow() ; //刷新屏幕函数
    QList<int> keys;
    QTimer* keyRespondTimer;
    void slotTimeOut();
    //map - 相关
public: //背景地图
    Block map_block ;

    //机关
public:
    box *_box;
    mechanism1 *_mechanism1 ;
    mechanism2 *_mechanism2 ;
    mechanismbegin2 *_mechanismbegin2, *_mechanismbegin02 ;
    mechanismbegin1 *_mechanismbegin1 ;
    mechanism2 *_mechanism3 ;
    mechanismbegin2 *_mechanismbegin3, *_mechanismbegin03 ;

    ice_door *_ice_door;
    fire_door *_fire_door;
    poison *_poison[20] ;
    lava *_lava[20] ;
    water *_water[20] ;
    die *_die ;
    ice_diamond *_ice_diamond[5] ;
    fire_diamond *_fire_diamond[5] ;

    //按钮+结算页面
    QLabel_C *button = nullptr, *button2 = nullptr, *button3 = nullptr ;
    pic *number_ice = nullptr, *number_fire = nullptr, *number_S = nullptr ;
    pic *cover1 = nullptr, *cover2 = nullptr, *cover3 = nullptr ;
    //关卡
    int nowlevel = 0, beflevel = 0 ;
    void level1() ;
    void level2() ;
    void level3() ;
    int rkA = 0, rkB = -1, rkC = -1, rank = 0 ;
    wind *_wind1 = nullptr, *_wind2 = nullptr ;
};

#endif // LEVEL_H

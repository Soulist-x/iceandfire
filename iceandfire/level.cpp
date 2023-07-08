#include "level.h"
#include <qpainter>
#include <stdio.h>
#define rep(i, s, t) for(int i = (s); i <= (t); ++ i)
void level::level1() {
    keyRespondTimer = new QTimer(this);
    connect(keyRespondTimer, &QTimer::timeout, this, &level::slotTimeOut);//设置按键的计时器
    _Show = new QTimer(this) ;
    connect(_Show, &QTimer::timeout, this, &level::toShow) ;
    _Show -> start(14) ; //每 14 间隔刷新人物图像
    _mechanism1 = new mechanism1(map_block) ;//mechanism2 的初始位置
    _mechanism1 -> setParent(this) ;
    _mechanism1 -> Stay2(51, 370, map_block) ;

    _mechanismbegin1 = new mechanismbegin1(map_block) ;//mechanism1 的初始位置
    _mechanismbegin1 -> setParent(this) ;
    _mechanismbegin1 -> Stay2(254, 505, map_block) ;

    _mechanism2 = new mechanism2(map_block, 120, 20, 0, -1, 0, 90, MECHANISM2_1, MECHANISM2_2) ;//mechanism2 的初始位置
    _mechanism2 -> setParent(this) ;
    _mechanism2 -> Stay2(880, 285, map_block) ;


    _mechanismbegin2 = new mechanismbegin2(map_block, MECHANISM2_3) ;//mechanism2 的初始位置
    _mechanismbegin2 -> setParent(this) ;
    _mechanismbegin2 -> Stay2(750, 264, map_block) ;

    _mechanismbegin02 = new mechanismbegin2(map_block, MECHANISM2_3) ;//mechanism2 的初始位置
    _mechanismbegin02 -> setParent(this) ;
    _mechanismbegin02 -> Stay2(320, 353, map_block) ;

    _box = new box(map_block) ; //设置box的初始位置
    _box -> setParent(this) ;
    _box -> Stay(300, 237, map_block) ;
    _ice_door=new ice_door(); //设置icedoor的初始位置
    _ice_door->setParent(this);
    _ice_door->Stay2(860,95,map_block);

    _fire_door=new fire_door();
    _fire_door->setParent(this);
    _fire_door->Stay2(940,95,map_block);



    _icegirl = new icegirl ;//设置冰人的初始位置
    _icegirl -> setParent(this) ;
    _icegirl -> Stay(110, 555) ;
    //_icegirl -> Stay(110, 140) ;

    _fireboy = new fireboy ;//设置火人的初始位置
    _fireboy -> setParent(this) ;
    _fireboy -> Stay(110, 640) ;
    //_fireboy -> Stay(110, 140) ;

    for(int i = 0; i <= 4; ++ i)
        _ice_diamond[i] = new ice_diamond(map_block), _ice_diamond[i] -> setParent(this) ;
    _ice_diamond[0] -> Stay2(748, 655, map_block) ;
    _ice_diamond[1] -> Stay2(655, 325, map_block) ;
    _ice_diamond[2] -> Stay2(90, 60, map_block) ;
    _ice_diamond[3] -> Stay2(635, 114, map_block) ;

    for(int i = 0; i <= 4; ++ i)
        _fire_diamond[i] = new fire_diamond(map_block), _fire_diamond[i] -> setParent(this) ;
    _fire_diamond[0] -> Stay2(541, 655, map_block) ;
    _fire_diamond[1] -> Stay2(218, 325, map_block) ;
    _fire_diamond[2] -> Stay2(250, 53, map_block) ;
    _fire_diamond[3] -> Stay2(495, 114, map_block) ;

    //毒池子
    rep( i, 0, 4 )
        _poison[i] = new poison, _poison[i] -> setParent(this) ;
    _poison[0]->Stay2(595,543),_poison[1] -> Stay1(622,543),_poison[2]->Stay1(654,543),_poison[3]->Stay1(660,543),_poison[4]->Stay3(685,543);
    //岩浆

    rep( i, 0, 4 )
        _lava[i] = new lava, _lava[i] -> setParent(this) ;
    _lava[0]->Stay2(490,679),_lava[1] -> Stay1(522,679),_lava[2]->Stay1(542,679),_lava[3]->Stay1(562,679),_lava[4]->Stay3(587,679);
    //冰水
    rep( i, 0, 4 )
    _water[i] = new water, _water[i] -> setParent(this) ;
    _water[0]->Stay2(700,679),_water[1] -> Stay1(732,679),_water[2]->Stay1(752,679),_water[3]->Stay1(772,679),_water[4]->Stay3(797,679);


    _die = new die ;
    _die -> setParent(this) ;
}
void level::level2() {
    map_block.Block2() ;

    keyRespondTimer = new QTimer(this);
    connect(keyRespondTimer, &QTimer::timeout, this, &level::slotTimeOut);//设置按键的计时器
    _Show = new QTimer(this) ;
    connect(_Show, &QTimer::timeout, this, &level::toShow) ;
    _Show -> start(14) ; //每 14 间隔刷新人物图像

    _mechanism2 = new mechanism2(map_block, 16, 90, 0, 1, -90, 0, MECHANISM3_1, MECHANISM3_2) ;//mechanism2 的初始位置
    _mechanism2 -> setParent(this) ;
    _mechanism2 -> Stay2(500, 422, map_block) ;


    _mechanismbegin2 = new mechanismbegin2(map_block, MECHANISM3_3) ;//mechanism2 的初始位置
    _mechanismbegin2 -> setParent(this) ;
    _mechanismbegin2 -> Stay2(310, 499, map_block) ;

    _mechanismbegin02 = new mechanismbegin2(map_block, MECHANISM3_3) ;//mechanism2 的初始位置
    _mechanismbegin02 -> setParent(this) ;
    _mechanismbegin02 -> Stay2(690, 499, map_block) ;

    _mechanism3 = new mechanism2(map_block, 120, 20, 1, 0, -110, 0, MECHANISM2_1, MECHANISM2_2) ;//mechanism2 的初始位置
    _mechanism3 -> setParent(this) ;
    _mechanism3 -> Stay2(450 + 110, 130, map_block) ;

    _mechanismbegin3 = new mechanismbegin2(map_block, MECHANISM2_3) ;//mechanism2 的初始位置
    _mechanismbegin3 -> setParent(this) ;
    _mechanismbegin3 -> Stay2(684, 114, map_block) ;

    _mechanismbegin03 = new mechanismbegin2(map_block, MECHANISM2_3) ;//mechanism2 的初始位置
    _mechanismbegin03 -> setParent(this) ;
    _mechanismbegin03 -> Stay2(250, 114, map_block) ;

    cover1 = new pic(COVER1, 64, 51) ;
    cover1 -> setParent(this) ;
    cover1 -> Stay(474, 371) ;

    cover2 = new pic(COVER2, 137, 29) ;
    cover2 -> setParent(this) ;
    cover2 -> Stay(572, 130) ;

    _ice_door=new ice_door(); //设置icedoor的初始位置
    _ice_door->setParent(this);
    _ice_door->Stay2(128,67,map_block);

    _fire_door=new fire_door();
    _fire_door->setParent(this);
    _fire_door->Stay2(53,67,map_block);


    _icegirl = new icegirl ;//设置冰人的初始位置
    _icegirl -> setParent(this) ;
    _icegirl -> Stay(70, 620) ;
    //_icegirl -> Stay(110, 140) ;

    _fireboy = new fireboy ;//设置火人的初始位置
    _fireboy -> setParent(this) ;
    _fireboy -> Stay(100, 620) ;

    for(int i = 0; i <= 4; ++ i)
        _ice_diamond[i] = new ice_diamond(map_block), _ice_diamond[i] -> setParent(this) ;
    _ice_diamond[0] -> Stay2(267, 586, map_block) ;
    _ice_diamond[1] -> Stay2(670, 661, map_block) ;
    _ice_diamond[2] -> Stay2(585, 465, map_block) ;
    _ice_diamond[3] -> Stay2(535, 70, map_block) ;

    for(int i = 0; i <= 4; ++ i)
        _fire_diamond[i] = new fire_diamond(map_block), _fire_diamond[i] -> setParent(this) ;
    _fire_diamond[0] -> Stay2(670, 586, map_block) ;
    _fire_diamond[1] -> Stay2(267, 661, map_block) ;
    _fire_diamond[2] -> Stay2(400, 465, map_block) ;
    _fire_diamond[3] -> Stay2(455, 70, map_block) ;

    //毒池子（右）
    rep( i, 0, 6 )
        _poison[i] = new poison, _poison[i] -> setParent(this) ;
    _poison[0]->Stay2(581,380),_poison[1] -> Stay1(610,380),_poison[2]->Stay1(642,380),_poison[3]->Stay1(674,380),
        _poison[4]->Stay3(746,380),_poison[5]->Stay1(714,380),_poison[6]->Stay1(685,380);
    //毒池子（左）
    rep( i, 7, 13 )
        _poison[i] = new poison, _poison[i] -> setParent(this) ;
    _poison[7]->Stay2(221,380),_poison[8] -> Stay1(253,380),_poison[9]->Stay1(285,380),_poison[10]->Stay1(317,380),
        _poison[11]->Stay3(413,380),_poison[12]->Stay1(349,380),_poison[13]->Stay1(381,380);

    //火池子（右上）
    rep( i, 0, 6 )
        _lava[i] = new lava, _lava[i] -> setParent(this) ;
    _lava[0]->Stay2(579,596),_lava[1] -> Stay1(610,596),_lava[2]->Stay1(640,596),_lava[3]->Stay1(672,596),
        _lava[4]->Stay3(744,596),_lava[5]->Stay1(712,596),_lava[6]->Stay1(683,596);
    //火池子（左下）

    rep( i, 7, 13 )
        _lava[i] = new lava, _lava[i] -> setParent(this) ;
    _lava[7]->Stay2(221-52,668),_lava[8] -> Stay1(253-52,668),_lava[9]->Stay1(285-52,668),_lava[10]->Stay1(317-52,668),
        _lava[11]->Stay3(413-52,668),_lava[12]->Stay1(349-52,668),_lava[13]->Stay1(381-52,668);

    //水池子（右下）
    rep( i, 0, 6 )
        _water[i] = new water, _water[i] -> setParent(this) ;
    _water[0]->Stay2(579,668),_water[1] -> Stay1(610,668),_water[2]->Stay1(640,668),_water[3]->Stay1(672,668),
        _water[4]->Stay3(744,668),_water[5]->Stay1(712,668),_water[6]->Stay1(683,668);
    //水池子（左上）
    rep( i, 7, 13 )
        _water[i] = new water, _water[i] -> setParent(this) ;
    _water[7]->Stay2(221-52,596),_water[8] -> Stay1(253-52,596),_water[9]->Stay1(285-52,596),_water[10]->Stay1(317-52,596),
        _water[11]->Stay3(413-52,596),_water[12]->Stay1(349-52,596),_water[13]->Stay1(381-52,596);
    _die = new die ;
    _die -> setParent(this) ;
}

void level::level3() {
    map_block.Block3() ;

    keyRespondTimer = new QTimer(this);
    connect(keyRespondTimer, &QTimer::timeout, this, &level::slotTimeOut);//设置按键的计时器
    _Show = new QTimer(this) ;
    connect(_Show, &QTimer::timeout, this, &level::toShow) ;
    _Show -> start(14) ; //每 14 间隔刷新人物图像

    _ice_door=new ice_door(); //设置icedoor的初始位置
    _ice_door->setParent(this);
    _ice_door->Stay2(670,383,map_block);

    _fire_door=new fire_door();
    _fire_door->setParent(this);
    _fire_door->Stay2(310,383,map_block);


    _wind1 = new wind(map_block) ;
    _wind1 -> setParent(this) ;
    _wind1 -> Stay(48, 84) ;
    _wind1 -> Ins(map_block) ;

    _wind2 = new wind(map_block) ;
    _wind2 -> setParent(this) ;
    _wind2 -> Stay(913, 84) ;
    _wind2 -> Ins(map_block) ;
    //474, 371

    _icegirl = new icegirl ;//设置冰人的初始位置
    _icegirl -> setParent(this) ;
    _icegirl -> Stay(935, 640) ;
    //_icegirl -> Stay(110, 140) ;

    _fireboy = new fireboy ;//设置火人的初始位置
    _fireboy -> setParent(this) ;
    _fireboy -> Stay(70, 633) ;

    for(int i = 0; i <= 4; ++ i)
        _ice_diamond[i] = new ice_diamond(map_block), _ice_diamond[i] -> setParent(this) ;
    _ice_diamond[0] -> Stay2(763, 657, map_block) ;
    _ice_diamond[1] -> Stay2(96, 85, map_block) ;
    _ice_diamond[2] -> Stay2(417, 234, map_block) ;
    _ice_diamond[3] -> Stay2(680, 295, map_block) ;

    for(int i = 0; i <= 4; ++ i)
        _fire_diamond[i] = new fire_diamond(map_block), _fire_diamond[i] -> setParent(this) ;
    _fire_diamond[0] -> Stay2(262, 657, map_block) ;
    _fire_diamond[1] -> Stay2(897, 85, map_block) ;
    _fire_diamond[2] -> Stay2(582, 234, map_block) ;
    _fire_diamond[3] -> Stay2(320, 295, map_block) ;

    //火池子（右中）
    rep( i, 0, 6 )
        _lava[i] = new lava, _lava[i] -> setParent(this) ;
    _lava[0]->Stay2(653,523),_lava[1] -> Stay1(685,523),_lava[2]->Stay1(717,523),_lava[3]->Stay1(749,523),
        _lava[4]->Stay3(843,523),_lava[5]->Stay1(811,523),_lava[6]->Stay1(779,523);
    //火池子（左下）
    rep( i, 7, 13 )
        _lava[i] = new lava, _lava[i] -> setParent(this) ;
    _lava[7]->Stay2(221-52,668),_lava[8] -> Stay1(253-52,668),_lava[9]->Stay1(285-52,668),_lava[10]->Stay1(317-52,668),
        _lava[11]->Stay3(390-52,668),_lava[12]->Stay1(349-52,668),_lava[13]->Stay1(359-52,668);
    //火池子（左上）
    rep( i, 14, 17 )
        _lava[i] = new lava, _lava[i] -> setParent(this) ;
    _lava[14]->Stay2(271,310),_lava[15] -> Stay1(303,310),_lava[16]->Stay1(335,310),_lava[17]->Stay3(367,310);
    //水池子（右下）
    rep( i, 0, 6 )
        _water[i] = new water, _water[i] -> setParent(this) ;
    _water[0]->Stay2(657,668),_water[1] -> Stay1(689,668),_water[2]->Stay1(721,668),_water[3]->Stay1(753,668),
        _water[4]->Stay3(844,668),_water[5]->Stay1(812,668),_water[6]->Stay1(783,668);
    //水池子（左中）
    rep( i, 7, 13 )
        _water[i] = new water, _water[i] -> setParent(this) ;
    _water[7]->Stay2(221-52,523),_water[8] -> Stay1(253-52,523),_water[9]->Stay1(285-52,523),_water[10]->Stay1(317-52,523),
        _water[11]->Stay3(390-52,523),_water[12]->Stay1(349-52,523),_water[13]->Stay1(359-52,523);
    //水池子（右上）
    rep( i, 14, 17 )
        _water[i] = new water, _water[i] -> setParent(this) ;
    _water[14]->Stay2(632,310),_water[15] -> Stay1(664,310),_water[16]->Stay1(696,310),_water[17]->Stay3(718,310);
    _die = new die ;
    _die -> setParent(this) ;
}
int max(int x, int y) {
    return (x > y) ? x : y ;
}
level::level(QWidget *parent, int type, int n1, int n2, int A, int B, int C) :
    QWidget(parent)
{
    setFixedSize(GAME_WIDTH, GAME_HEIGHT) ;
    setWindowTitle(GAME_TITLE) ;
    setAttribute(Qt::WA_DeleteOnClose);
    this -> rkA = A, this -> rkB = B, this -> rkC = C, this->rank = 0 ;
    if(type == 1) { //关卡1
        nowlevel = 1 ;
        level1() ;
    }
    else if(type == 2) {
        m_map.m_map2.load(MAP3_PATH) ;
        update() ;
        nowlevel = 2 ;
        level2() ;
    }
    else if(type == 3) {
        m_map.m_map2.load(MAP4_PATH) ;
        update() ;
        nowlevel = 3 ;
        level3() ;
    }
    else if(type < 0) { // 0 表示初始页面，10 表示选关页面，1x 表示结算页面，-1 表示失败页面。
        m_map.m_map2.load(GAMEOVER) ;
        update() ;
        button = new QLabel_C ;
        button -> setParent(this) ;
        button -> move(375, 360) ;
        button -> resize(280, 50) ;


        beflevel = -type ;
        connect(button,&QLabel_C::clicked,this,[&](){
            level *l = new level(nullptr, this->beflevel, 0, 0, this->rkA, this->rkB, this->rkC) ;
            l->show() ;
            this->close() ;
        }) ;
        button2 = new QLabel_C ;
        button2 -> setParent(this) ;
        button2 -> move(425, 455) ;
        button2 -> resize(170, 40) ;
        connect(button2,&QLabel_C::clicked,this,[&](){
            level *l = new level(nullptr, 0, 0, 0, this->rkA, this->rkB, this->rkC) ;
            l->show() ;
            this->close() ;
        }) ;
    } else if(type >= 10) {
        m_map.m_map2.load(GAMEWIN) ;
        update() ;

        if(n1 == 0) number_ice = new pic(NUMBER0, 31, 50) ;
        else if(n1 == 1) number_ice = new pic(NUMBER1, 31, 50) ;
        else if(n1 == 2) number_ice = new pic(NUMBER2, 31, 50) ;
        else if(n1 == 3) number_ice = new pic(NUMBER3, 31, 50) ;
        else  number_ice = new pic(NUMBER4, 31, 50) ;
        number_ice -> setParent(this) ;
        number_ice -> Stay(567, 270) ;

        if(n2 == 0) number_fire = new pic(NUMBER0, 31, 50) ;
        else if(n2 == 1) number_fire = new pic(NUMBER1, 31, 50) ;
        else if(n2 == 2) number_fire = new pic(NUMBER2, 31, 50) ;
        else if(n2 == 3) number_fire = new pic(NUMBER3, 31, 50) ;
        else number_fire = new pic(NUMBER4, 31, 50) ;
        number_fire -> setParent(this) ;
        number_fire -> Stay(567, 328) ;

        int z = n1 + n2 ;
        if(z >= 8) number_S = new pic(RANK_A, 51, 60), this->rank = 3 ;
        else if(z >= 5) number_S = new pic(RANK_B, 51, 60), this->rank = 2 ;
        else number_S = new pic(RANK_C, 51, 60), this->rank = 1 ;
        number_S -> setParent(this) ;
        number_S -> Stay(570, 410) ;
        button = new QLabel_C ;
        button -> setParent(this) ;
        button -> move(410, 500) ;
        button -> resize(230, 50) ;
        beflevel = type - 10 ;
        connect(button,&QLabel_C::clicked,this,[&](){
            int d = 0 ;
            if((this -> beflevel) < 3) d = (this -> beflevel) + 1 ;
            if(d == 3) this->rkC = max(this->rkC, 0), this->rkB = max(this->rkB, this->rank) ;
            if(d == 2) this->rkB = max(this->rkB, 0), this->rkA = max(this->rkA, this->rank) ;

            level *l = new level(nullptr, 5, 0, 0, this->rkA, this->rkB, this->rkC) ;
            l->show() ;
            this->close() ;
        }) ;
    } else if(type == 0) {
        m_map.m_map2.load(MAP_PATH) ;
        update() ;
        button = new QLabel_C ;
        button -> setParent(this) ;
        button -> move(365, 420) ;
        button -> resize(295, 60) ;
        connect(button,&QLabel_C::clicked,this,[&](){
            level *l = new level(nullptr, 5, 0, 0, this->rkA, this->rkB, this->rkC) ;
            l->show() ;
            this->close() ;
        }) ;
    } else {
        m_map.m_map2.load(MAP5_PATH) ;
        update() ;
        QString AA, BB, CC ;
        AA = GAMERANK1DARK, BB = GAMERANK2DARK, CC = GAMERANK3DARK ;
        if(this->rkA == 0) AA = GAMERANK1 ;
        if(this->rkA == 1) AA = GAMERANK1C ;
        if(this->rkA == 2) AA = GAMERANK1B ;
        if(this->rkA == 3) AA = GAMERANK1A ;
        if(this->rkB == 0) BB = GAMERANK2 ;
        if(this->rkB == 1) BB = GAMERANK2C ;
        if(this->rkB == 2) BB = GAMERANK2B ;
        if(this->rkB == 3) BB = GAMERANK2A ;
        if(this->rkC == 0) CC = GAMERANK3 ;
        if(this->rkC == 1) CC = GAMERANK3C ;
        if(this->rkC == 2) CC = GAMERANK3B ;
        if(this->rkC == 3) CC = GAMERANK3A ;
        cover1 = new pic(AA, 300, 220) ;
        cover1 -> setParent(this) ;
        cover1 -> Stay(30, 500) ;

        cover2 = new pic(BB, 300, 220) ;
        cover2 -> setParent(this) ;
        cover2 -> Stay(360, 500) ;

        cover3 = new pic(CC, 300, 220) ;
        cover3 -> setParent(this) ;
        cover3 -> Stay(690, 500) ;
        if(this->rkA >= 0) {
            button = new QLabel_C ;
            button -> setParent(this) ;
            button -> move(30, 500) ;
            button -> resize(300, 220) ;
            connect(button,&QLabel_C::clicked,this,[&](){
                level *l = new level(nullptr, 1, 0, 0, this->rkA, this->rkB, this->rkC) ;
                l->show() ;
                this->close() ;
            }) ;
        }
        if(this->rkB >= 0) {
            button2 = new QLabel_C ;
            button2 -> setParent(this) ;
            button2 -> move(330, 500) ;
            button2 -> resize(300, 220) ;
            connect(button2,&QLabel_C::clicked,this,[&](){
                level *l = new level(nullptr, 2, 0, 0, this->rkA, this->rkB, this->rkC) ;
                l->show() ;
                this->close() ;
            }) ;
        }
        if(this->rkC >= 0) {
            button3 = new QLabel_C ;
            button3 -> setParent(this) ;
            button3 -> move(690, 500) ;
            button3 -> resize(300, 220) ;
            connect(button3,&QLabel_C::clicked,this,[&](){
                level *l = new level(nullptr, 3, 0, 0, this->rkA, this->rkB, this->rkC) ;
                l->show() ;
                this->close() ;
            }) ;
        }


    }
}

level::~level() {
    delete keyRespondTimer;
}

void level::paintEvent(QPaintEvent *event) {
    QPainter painter(this) ;
    painter.drawPixmap(0, m_map.m_map_posY, m_map.m_map2) ;
}

void level::keyPressEvent(QKeyEvent* event) {
    //parent()->event((QEvent *)event);
    if(!event->isAutoRepeat())  //判断如果不是长按时自动触发的按下,就将key值加入容器
        keys.append(event->key());
    if(keyRespondTimer && !keyRespondTimer->isActive()) //如果定时器不在运行，就启动一下
        keyRespondTimer->start(6);
}

void level::keyReleaseEvent(QKeyEvent *event){
    //parent()->event((QEvent *)event);
    if(!event->isAutoRepeat())  //判断如果不是长按时自动触发的释放,就将key值从容器中删除
    {
        if(event->key() == Qt::Key_A && (_icegirl)) _icegirl -> Stop_x(-1) ;
        if(event->key() == Qt::Key_D && (_icegirl)) _icegirl -> Stop_x(1) ;
        if(event->key() == Qt::Key_Left && (_fireboy)) _fireboy -> Stop_x(-1) ;
        if(event->key() == Qt::Key_Right && (_fireboy)) _fireboy -> Stop_x(1) ;
        //keys.removeAll(event->key());
    }
    if(keys.isEmpty() && keyRespondTimer) //容器空了，关闭定时器
        keyRespondTimer->stop();
}
void level::slotTimeOut(){
    foreach (int key, keys) {
        if(key == Qt::Key_W && _icegirl) _icegirl -> Change(0, -1, map_block) ;
        if(key == Qt::Key_A && _icegirl) _icegirl -> Change(-1, 0, map_block) ;
        if(key == Qt::Key_D && _icegirl) _icegirl -> Change(1, 0, map_block) ;
        if(key == Qt::Key_Up && _fireboy) _fireboy -> Change(0, -1, map_block) ;
        if(key == Qt::Key_Left && _fireboy) _fireboy -> Change(-1, 0, map_block) ;
        if(key == Qt::Key_Right && _fireboy) _fireboy -> Change(1, 0, map_block) ;
    }
    keys.clear() ;
}
void level::toShow() {
    if(_die -> _flag > 0) {
        ++ _die -> _flag ;
        if((_die -> _flag) == 10) {
            int x = _icegirl -> _get_diamond, y = _fireboy -> _get_diamond ;
            level *l = new level(nullptr, 10 + nowlevel, x, y, this->rkA, this->rkB, this->rkC) ;
            l -> show() ;
            this -> close() ;
        }
    }
    else {
        if(_die -> _count == 0) {

            if(nowlevel == 1) _box -> Stay(map_block, *_icegirl, *_fireboy) ;
            if(nowlevel <= 2) _mechanism2 -> init() ;
            if(nowlevel == 1) _mechanism1 -> init() ;
            if(nowlevel == 2) _mechanism3 -> init() ;
            if(nowlevel == 1) _mechanismbegin1 -> Stay(map_block,  *_icegirl, *_fireboy, *_mechanism1) ;
            if(nowlevel <= 2) _mechanismbegin2 -> Stay(map_block,  *_icegirl, *_fireboy, *_mechanism2) ;
            if(nowlevel <= 2) _mechanismbegin02 -> Stay(map_block,  *_icegirl, *_fireboy, *_mechanism2) ;
            if(nowlevel == 2) _mechanismbegin3 -> Stay(map_block,  *_icegirl, *_fireboy, *_mechanism3) ;
            if(nowlevel == 2) _mechanismbegin03 -> Stay(map_block,  *_icegirl, *_fireboy, *_mechanism3) ;
            if(nowlevel <= 2 ) _mechanism2 -> Stay(map_block, *_icegirl, *_fireboy) ;
            if(nowlevel == 2 ) _mechanism3 -> Stay(map_block, *_icegirl, *_fireboy) ;
            if(nowlevel == 1) _mechanism1 -> Stay(map_block, *_icegirl, *_fireboy) ;
            if(nowlevel == 2) cover1 -> ins(map_block), cover2 -> ins(map_block) ;
            int ed = -1 ;
            if(nowlevel == 2) ed = 6 ;
            if(nowlevel == 1) ed = 4 ;
            rep( i, 0, ed )
            _poison[i] -> Die(map_block, *_icegirl, *_fireboy, *_die) ;
            if(nowlevel == 3) ed = 17 ;
            if(nowlevel == 2) ed = 13 ;
            if(nowlevel == 1) ed = 4 ;
            rep( i, 0, ed )
            _lava[i] -> Die(map_block, *_icegirl, *_die) ;
            rep( i, 0, ed )
            _water[i] -> Die(map_block, *_fireboy, *_die) ;

            for(int i = 0; i < 4; ++ i) _ice_diamond[i] -> Stay(map_block, *_icegirl, *_fireboy) ;

            for(int i = 0; i < 4; ++ i) _fire_diamond[i] -> Stay(map_block, *_icegirl, *_fireboy) ;
            _fire_door -> Stay(map_block, *_fireboy) ;
            _ice_door -> Stay(map_block, *_icegirl) ;
            if((_ice_door -> _flag == 1) && (_fire_door -> _flag == 1)) _die ->_flag = 1 ;
            _icegirl -> check_wind(map_block), _fireboy -> check_wind(map_block) ;
            _icegirl -> Stay(map_block), _fireboy -> Stay(map_block) ;
        }
        else {
            _die -> DIE() ;
            if(_die -> _count == 129) {

                level *l = new level(nullptr, -nowlevel, 0, 0, this->rkA, this->rkB, this->rkC) ;
                l -> show() ;
                this -> close() ;
            }
        }
    }
}

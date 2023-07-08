#ifndef MAP_H
#define MAP_H
#include<QPixmap>

class Map
{
public:
    Map();
    QPixmap m_map, m_map2, m_map3 ;
    int m_map_posX, m_map_posY ;
    void setposition(int x, int y) ;

};

#endif // MAP_H

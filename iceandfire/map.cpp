#include "map.h"
#include "config.h"

Map::Map()
{
    m_map.load(MAP_PATH) ;
    m_map2.load(MAP2_PATH) ;
    m_map3.load(GAMEOVER) ;
    m_map_posY = 0 ;
    m_map_posX = 0 ;
}

void Map::setposition(int x, int y) {
    m_map_posX += x ;
    m_map_posY += y ;
}

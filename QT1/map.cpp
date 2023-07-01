#include "map.h"
#include "config.h"
#include "heroplane.h"


map::map()
{
    //初始化地图
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);
    m_floor1.load(MAP_FLOOR1);
    m_floor2.load(MAP_FLOOR2);
    m_floor3.load(MAP_FLOOR3);
    m_wall1.load(MAP_WALL1);
    m_wall10.load(MAP_WALL10);
    m_wall2.load(MAP_WALL2);
    m_wall20.load(MAP_WALL20);
    m_plant.load(MAP_PLANT);
    water1.load(MAP_WATER1);
    water2.load(MAP_WATER2);
    water3.load(MAP_WATER3);
    water4.load(MAP_WATER4);
    hole1.load(MAP_WALLIN1);
    hole2.load(MAP_WALLIN2);
    key.load(MAP_KEY);
    success.load(MAP_HOME);


    //初始化背景x轴坐标
    m_map1_posX = GAME_WIDTH;
    m_map2_posX = 0;

    //初始化地图方块坐标
    m_floor1_X = 0;
    m_floor1_Y = 0;

    //建立floor1方块边框(用于碰撞检测)
    m_Rect.setWidth(270);
    m_Rect.setHeight(m_floor1.height());
    m_Rect.moveTo(0,500);

    //悬崖
    m_Rect1.setWidth(336);
    m_Rect1.setHeight(444);
    m_Rect1.moveTo(420,400);

    //水
    m_Rect2.setWidth(96);
    m_Rect2.setHeight(96);
    m_Rect2.moveTo(348,674);

    //河流
    m_Rect3.setWidth(520);
    m_Rect3.setHeight(48);
    m_Rect3.moveTo(800,666);

    //怪物平台
    m_Rect4.setWidth(320);
    m_Rect4.setHeight(48);
    m_Rect4.moveTo(1000,396);

    //钥匙
    m_Rect5.setWidth(30);
    m_Rect5.setHeight(30);
    m_Rect5.moveTo(1170,360);

    //最终平台
    m_Rect6.setWidth(740);
    m_Rect6.setHeight(48);
    m_Rect6.moveTo(0,-200);

    m_Rect7.setWidth(66);
    m_Rect7.setHeight(66);
    m_Rect7.moveTo(0,-200);

    //地图滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;
}

void map::mapPosition()
{
    //处理第一张图片滚动位置
    m_map1_posX -= m_scroll_speed;
    if(m_map1_posX <= 0)
    {
        m_map1_posX = GAME_WIDTH;
    }

    //处理第二张图片滚动位置
    m_map2_posX -= m_scroll_speed;
    if(m_map2_posX <= -GAME_WIDTH)
    {
        m_map2_posX = 0;
    }
}

void map::mapMove(int x,int y)
{
    m_map1_posX -= x;
    m_map2_posX -= x;
}

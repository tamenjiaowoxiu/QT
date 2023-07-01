#ifndef MAP_H
#define MAP_H
#include <QPixmap>

class map
{
public:
    //构造函数
    map();

    //地图滚动坐标计算
    void mapPosition();

    //地图移动
    void mapMove(int x,int y);

public:

    //地图图片对象
    QPixmap m_map1;
    QPixmap m_map2;
    QPixmap m_floor1;
    QPixmap m_floor2;
    QPixmap m_floor3;
    QPixmap m_wall1;
    QPixmap m_wall2;
    QPixmap m_plant;
    QPixmap m_wall10;
    QPixmap m_wall20;
    QPixmap water1;
    QPixmap water2;
    QPixmap water3;
    QPixmap water4;
    QPixmap hole1;
    QPixmap hole2;
    QPixmap key;
    QPixmap success;


    //地图边框
    QRect m_Rect; //需要多个边框

    QRect m_Rect1; //悬崖

    QRect m_Rect2; //水流

    QRect m_Rect3; //河流

    QRect m_Rect4; //右边平台

    QRect m_Rect5; //钥匙

    QRect m_Rect6; //最终平台

    QRect m_Rect7; //通关房子



    //地图方块坐标
    int m_floor1_X;
    int m_floor1_Y;

    //地图x轴坐标
    int m_map1_posX;
    int m_map2_posX;


    //地图滚动速度
    int m_scroll_speed;
};

#endif // MAP_H

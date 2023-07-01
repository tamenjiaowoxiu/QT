#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>


class Bullet
{
public:
    Bullet();

    //更新手里剑坐标
    void updatePosition();

public:
    //手里剑资源对象
    QPixmap m_Bullet;
    //手里剑坐标
    int m_X;
    int m_Y;
    //手里剑速度
    int m_Speed;
    //手里剑是否闲置
    bool m_Free;
    //手里剑的矩形边框（碰撞检测，主要是屏幕外即距离检测）
    QRect m_Rect;

};

#endif // BULLET_H

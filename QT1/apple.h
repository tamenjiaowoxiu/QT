#ifndef APPLE_H
#define APPLE_H
#include <QPixmap>

class apple
{
public:
    apple();
    //更新手里剑坐标
    void updatePosition();

public:
    //苹果资源对象
    QPixmap m_Apple;
    //苹果坐标
    int m_X;
    int m_Y;
    //苹果速度
    int m_Speed;
    //苹果是否闲置
    bool m_Free;
    //苹果的矩形边框（碰撞检测，主要是屏幕外即距离检测）
    QRect m_Rect;
};

#endif // APPLE_H

#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>


class Enemy
{
public:
    Enemy();

    //更新坐标
    void updatePosition();

public:
    //敌人资源对象
    QPixmap m_enemy;

    //初始化位置
    int m_X;
    int m_Y;

    //敌人边框(用于边框检测)
    QRect m_Rect;

    //状态
    bool m_Free;

    //移动状态
    bool movechange;

    //速度
    float m_Speed;
};

#endif // ENEMY_H

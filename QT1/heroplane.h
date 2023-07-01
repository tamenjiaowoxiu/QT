#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include <QRect>
#include  "bullet.h"


class HeroPlane
{
public:
    HeroPlane();
    //发射手里剑
    void shoot();

    //鼠标移动位置（坐标）
    void setPosition(int x,int y);

    //键盘移动位置
    void updatePosition(int x,int y);

    //跳跃
    void jumpPosition();

    //人物跳跃事件
    void Jump();

    //人物移动切换图片
    void Change(QPixmap x);

    void down();





public:
    QPixmap m_Kakaxi;
    QPixmap m_Kakaxi_right;
    QPixmap m_Kakaxi_left;
    QPixmap m_Kakaxi_right1;
    QPixmap m_Kakaxi_left1;
    QPixmap m_Kakaxi_jump_left;
    QPixmap m_Kakaxi_jump_right ;
    QPixmap pix;
    QPixmap m_Kakaxi_dead;

    QVector<QPixmap> m_pixArr;
    //人物位置
    int m_X;
    int m_Y;

    //判断加速度
    int speedx = 0;

    //跳跃判断
    bool jumping = false;

    //是否可以跳跃
    bool canJump = false;

    //下落判断
    bool Falling = false;

    //地图障碍物判断
    bool obj = false;

    //地图障碍物碰撞1
    bool obj1 = false;

    //地图的水
    bool obj2 = false;

    //地图的河流
    bool obj3 = false;

    //右平台
    bool obj4 = false;

    //敌人
    bool obj5 = false;

    //通过条件
    bool objfinal = false;

    //最终平台
    bool obj6 = false;

    //通关
    bool obj7 = false;

    //平台的开启和隐藏
    bool obj8 = false;

    //播放状态
    bool m_Free;

    //切图间隔
    int m_Recoder;

    //图片下标
    int m_index;

    //人物速度
    int m_Speed;

    //下落速度
    int m_Speed1;

    //人物边框（矩形）
    QRect m_Rect;

    //箭袋
    Bullet m_bullets[BULLET_NUM];

    //发射时间间隔记录
    int m_recorder ;

    int count;



};

#endif // HEROPLANE_H

#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include <QList> //链表
#include <enemy.h>
#include <boomb.h>
#include "otherscene.h"
#include "successscene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class myWidget; }
QT_END_NAMESPACE

class myWidget : public QWidget //继承于QWidget，所以里面的东西都可以用。
{
    Q_OBJECT // 是一个宏，允许类中使用信号和槽的机制！！！

public:
    myWidget(QWidget *parent = nullptr); //构造函数
    ~myWidget();//析构函数

    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    //更新所有游戏中元素的坐标
    void updatePosition();

    //绘制到屏幕中 函数名称不可改
    void paintEvent(QPaintEvent *);

    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *);

    OtherScene * otherScene = NULL;

    successscene * successScene = NULL;


    //地图对象
    map m_map;

    //人物对象
    HeroPlane m_hero;

    //定时器
    QTimer m_Timer; //背景移动
    QTimer* mHeroMoveTimer; //人物移动

    //测试手里剑对象
//    Bullet temp_Bullet;

    //按键事件
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

    //按键组合
    QList<int> mKeyList;

    //人物移动
    void HeroMove();

    //人物跳跃
    void jumpUpdateposition();

    //下落
    void down();

    //是否处于下落状态
    bool isdown;

    bool canMove;

    //敌人出场
    void enemyComeout();

    //敌人数组
    Enemy m_enemy;

    //敌人出场间隔记录
    int m_recorder;

    //碰撞物理系统
    void collisionDetection();

    //爆炸数组
    Boomb m_bombs[BOMB_NUM];





private:
    Ui::myWidget *ui;
};
#endif // MYWIDGET_H

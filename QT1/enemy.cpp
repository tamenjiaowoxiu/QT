#include "enemy.h"
#include "config.h"
#include <QDebug>
Enemy::Enemy()
{
    //敌人资源绘制
    m_enemy.load(ENEMY_PATH);

    //敌人位置
    m_X = 1254;
    m_Y = 340;

    //敌人状态(空闲）
    m_Free = true;

    //敌人速度
    m_Speed = ENEMY_SPEED;

    movechange = true;

    //敌人矩形框（碰撞）
    m_Rect.setWidth(66);
    m_Rect.setHeight(66);
    m_Rect.moveTo(m_X,m_Y);
}

void Enemy::updatePosition()
{
    if(movechange)
    {
      m_enemy.load(ENEMY_PATH);
      m_X -= m_Speed;
      m_Rect.moveTo(m_X,m_Y);
      if(m_X<=1000)
      {
          movechange = false;
      }
    }
    if(!movechange)
    {
        m_enemy.load(ENEMY_PATH1);
        m_X += m_Speed;
        m_Rect.moveTo(m_X,m_Y);
        if(m_X>1320)
        {
            movechange = true;
        }
    }

//    if(m_Free)
//    {
//        return;
//    }

//    m_X -= m_Speed;
//    m_Rect.moveTo(m_X,m_Y);
//    qDebug() << m_X;

//    //如果超出屏幕 重置空闲状态
//    if(m_X <= 0 + m_Rect.height())
//    {
//        m_Free = true;
//    }
}

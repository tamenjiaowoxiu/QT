#include "bullet.h"

Bullet::Bullet()
{
    //加载资源
    m_Bullet.load(BULLET_PATH);

    //手里剑坐标
    m_X = 0; //GAME_WIDTH * 0.5 - m_Bullet.width() * 0.5
    m_Y = 0; //GAME_HEIGHT

    //手里剑状态 默认空闲
    m_Free = true;

    //手里剑速度
    m_Speed = BULLET_SPEED;

    //手里剑边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);

}

void Bullet::updatePosition()
{
    //空闲状态下的手里剑，不需要计算坐标
    if(m_Free)
    {
        return;
    }

    //手里剑向右移动
    m_X += m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //手里剑位置 超出固定距离，重现变为空闲状态
    if(m_Y <= - m_Rect.height())
    {
        m_Free = true;
    }

}

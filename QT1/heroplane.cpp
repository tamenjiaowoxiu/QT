#include "heroplane.h"
#include "config.h"
#include <QDebug>
#include <mywidget.h>

HeroPlane::HeroPlane()
{
    //初始化加载人物图片资源
    m_Kakaxi.load(HERO_PATH);
    m_Kakaxi_left.load(":/res/kakaxi_left.png");
    m_Kakaxi_right.load(":/res/kakaxi_right.png");
    m_Kakaxi_left1.load(":/res/kakaxi_left1.png");
    m_Kakaxi_right1.load(":/res/kakaxi_right.png");
    m_Kakaxi_jump_left.load(":/res/JUMP_left.png");
    m_Kakaxi_jump_right.load(":/res/JUMP_right.png");
    m_Kakaxi_dead.load(":/res/dead.png");



    //初始化人物坐标
    m_X = 0;
    m_Y = 666;

    //初始化人物边框
    m_Rect.setHeight(66);
    m_Rect.setWidth(1);
    m_Rect.moveTo(m_X,m_Y);

    //初始化人物速度
    m_Speed = HERO_SPEED;

    //下落速度
    m_Speed1 = HERO_SPEED1;


    int count=0;

////重力设置 （如果不在陆地上则会不断掉落，跳跃的时候就将移动范围增大甚至直接setposition）
//    if(m_Y != 720 )
//    {
//        m_Y += HERO_SPEED;
//        m_Rect.moveTo(m_X,m_Y);
//    }

}
//手里剑在发射出一段距离后消失（落下），这段距离是固定的，在得到本身的坐标后，加上这段固定距离，判断消失条件。
void HeroPlane::shoot()
{
////    累加时间间隔记录变量
//    for(int m_recorder = 0;m_recorder<BULLET_INTERVAL; m_recorder++)
//    {
//        if(m_recorder < BULLET_INTERVAL)
//        {
//            return;
//        }

//    }
    m_recorder++;

    //如果记录的数字，未达到发射手里剑时间间隔，直接return，不发射手里剑
    if(m_recorder < BULLET_INTERVAL)
    {
        return;
    }

    //达到发射时间间隔
    m_recorder = 0;

    //发射手里剑
    for(int i = 0; i< BULLET_NUM;i++)
    {
         //如果是空闲的手里剑，则发射
        if(m_bullets[i].m_Free)
        {
            //将空闲状态改变
            m_bullets[i].m_Free = false;
            //设置子弹坐标
            m_bullets[i].m_X = m_X;
            m_bullets[i].m_Y = m_Y;
            break;
        }
    }
    qDebug() << m_bullets;

}

void HeroPlane::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}

void HeroPlane::updatePosition(int x, int y)
{
    m_X += x;
    m_Y += y;
    m_Rect.moveTo(m_X,m_Y);
    qDebug() << m_X;
}


void HeroPlane::Jump()
{
//    int i = 0;

//    if(count++%3){
//        return;
//    }


//    i++;
   jumping = true;
//   if(jumping)
//   {
//       m_Y -= m_Speed;
//       m_Speed -= 1;
//       if(m_Y>=666)
//       {
//           jumping = false;
//           m_Speed = 25;
//       }
//   }
}

void HeroPlane::Change(QPixmap x)
{
    m_Kakaxi = x ;
}

void HeroPlane::down()
{
    jumping = true;
    m_Speed = 0;
}

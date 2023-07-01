#include "boomb.h"
#include "config.h"

Boomb::Boomb()
{
    //将所有爆炸pixmap放入到数组中

    for(int i = 1; i<BOMB_MAX;i++)
    {
        //str类似于":/res/bomb-1.png"

        QString str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    //坐标
    m_X = 0;
    m_Y = 0;

    //空闲状态
    m_Free = true;

    //当前播放图片下标
    m_index = 0;

    //播放爆炸间隔记录
    m_Recoder = 0;
}

void Boomb::updateInfo()
{
    //空闲状态下的 爆炸小 直接 return
    if(m_Free)
    {
        return;
    }

    m_Recoder++;
    //如果记录爆炸的记录未到爆炸间隔，不需要切图，直接return
    if(m_Recoder<BOMB_INTERVAL)
    {
        return;
    }

    //重置记录
    m_Recoder = 0;

    //切换图片
    m_index ++;

    //数组中从0开始计算，最后一个图片的下标为 6
    if(m_index > BOMB_MAX-1)
    {
        m_index = 1;
        m_Free = true;
    }
}

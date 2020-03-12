#include "bomb.h"
#include "config.h"
#include "mainscene.h"
#include <QDebug>
Bomb::Bomb()
{
    //初始化爆炸图片数组
    for(int i=1;i<8;i++)
    {
        QString str=QString(BOMB_PATH).arg(i);

        m_pixArr.push_back(QPixmap(str));
    }

    //初始化坐标
    m_X=0;
    m_Y=0;

    //初始化空闲状态
    m_Free=true;

    //当前播放图片下标
    m_index=0;

    //爆炸间隔记录
    m_recorder=0;


}

void Bomb::updateInfo()
{
    //空闲状态
    if(m_Free)
    {
        return;
    }

    m_recorder++;
    //没用完不切换

    //重置记录
    m_recorder=0;
    if (m_recorder<BOMB_INTERVAL)
       {
           return;
       }
    //切换爆炸播放图片
    m_index++;
    //注：数组中点的下标从0开始，最大为6
    //如果计算的下标大于6，重置为0
    if(m_index>BOMB_MAX-1)
    {
        m_index=0;
        m_Free=true;
    }



}





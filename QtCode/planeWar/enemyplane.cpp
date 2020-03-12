#include "enemyplane.h"
#include "config.h"
#include <QTime>
EnemyPlane::EnemyPlane()
{

    QString pixmap_url =ENEMY_PATH+QString::number(randomIntEnemy(),10)+".png";
       m_enemy.load(pixmap_url);

    //m_enemy.load(ENEMY_PATH);

    //敌机位置
    m_X=0;
    m_Y=0;

    //敌机状态
    m_Free=true;

    //敌机速度
    m_Speed=ENEMY_SPEED;

    //敌机矩形
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);




}

void EnemyPlane::updatePosition()
{
    //空闲状态
    if(m_Free)
    {
        return;
    }

    m_Y+=m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //超出屏幕则重置
    if(m_Y>=GAME_HEIGHT+m_Rect.height())
    {
        m_Free=true;
    }

}

int EnemyPlane::randomIntEnemy()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int n = qrand() % 7;    //随机数
    return  n;
}







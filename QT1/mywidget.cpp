#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPushButton> //按钮的头文件
#include "config.h"
#include <QIcon>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <ctime>
#include "boomb.h"
#include <QSound>
#include <QLabel>
#include <QApplication>
#include <QGraphicsRectItem>
// 命名规范
// 类名 首字母大写，单词和单词之间首字母大写
// 函数名 变量名称 首字母小写，单词和单词之间首字母大写

// 快捷键
// 注释 ctrl + /
// 运行 ctrl + r(run)
// 编译 ctrl + b(build)
// 字体缩放 ctrl + 滚轮
// 查找 ctrl + f(find)
// 整行移动 ctrl + shift ↑ 或者 ↓
// 帮助文档 F1（俩次就全屏 退出就exe）
// 自动对齐 ctrl + i
// 同名之间的.h 和.cpp 切换 F4

//帮助文档 第一种方式 F1

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);

    //调用初始化场景
    initScene();

    //实例化场景
    otherScene = new OtherScene;

    //重置窗口大小
    resize(600,400);

    //设置固定窗口大小
//    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("kakaxirun");

    this->setWindowIcon(QPixmap(":/res/kakaxi-removebg-preview.png"));

    //通关窗口
    successScene = new successscene;

    //启动游戏
    playGame();


}

myWidget::~myWidget()
{
    delete ui;
    qDebug() << "myWidget";
}

void myWidget::initScene()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
//    setWindowIcon(QIcon());

    //定时器初始化设置
    m_Timer.setInterval(GAME_RATE);

    //敌人出场时间
    m_recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL));

    //初始化下落状态
    isdown = true;

    canMove = true;
}

void myWidget::playGame()
{
    //启动背景音乐
    QSound::play(SOUND_BACKGROUND);

    //启动定时器
    m_Timer.start();

    //监听定时器发送的信号
    connect(&m_Timer , &QTimer::timeout,[=](){
        //更新游戏中元素的坐标
        updatePosition();

        //敌人出场
        enemyComeout();

        //绘制到屏幕中
        update();

    });

    //开启人物移动检测定时器
    mHeroMoveTimer = new QTimer(this);
    mHeroMoveTimer->start(10);
    connect(mHeroMoveTimer,&QTimer::timeout,[=](){
        jumpUpdateposition();
        HeroMove();
        //碰撞检测
        collisionDetection();
        //播放爆炸效果
        for(int k = 0 ; k<BOMB_NUM; k++)
        {
            if(m_bombs[k].m_Free)
            {
                //播放爆炸音乐
//                QSound::play(SOUND_BOMB);
                //空闲的爆炸即播放
                m_bombs[k].m_Free = false;
                if(k == BOMB_NUM)
                {
                    k =0;
                }
                //更新爆炸坐标
                break;

            }
        }


    });
}

void myWidget::updatePosition()
{
    //更新敌人的坐标
    m_enemy.updatePosition();

    //发射手里剑
    m_hero.shoot();

    //计算所有非空闲手里剑的当前坐标
    for(int i = 0;i < BULLET_NUM;i++)
    {
        //如果非空闲，计算发射位置
        if(m_hero.m_bullets[i].m_Free == false)
        {
            m_hero.m_bullets[i].updatePosition();
        }
    }

}

void myWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(m_map.m_map1_posX,300,m_map.m_map1);
    painter.drawPixmap(m_map.m_map2_posX,-200,m_map.m_map2);
    painter.drawPixmap(384,740,m_map.water1);
    painter.drawPixmap(384,788,m_map.water3);
    painter.drawPixmap(432,740,m_map.water2);
    painter.drawPixmap(432,788,m_map.water4);

    //左边河流
    for(int i = 800; i<GAME_WIDTH;i+=48)
    {
       painter.drawPixmap(i,740,m_map.water2);
    }

    for(int i = 800; i<GAME_WIDTH;i+=48)
    {
       painter.drawPixmap(i,788,m_map.water4);
    }

    //第一层
    for(int i = 0; i<384;i+=48)
    {
        painter.drawPixmap(i,730,m_map.m_floor1);
    }
    //第二层
    for(int i = 0;i<384;i+=48)
    {
        painter.drawPixmap(i,778,m_map.m_floor3);
    }
    //墙
//    painter.drawPixmap(480,396,m_map.m_Rect1.width(),m_map.m_Rect1.height(),m_map.water1);
//    左平台
    painter.drawPixmap(470,396,m_map.m_wall1);
    //右平台
    painter.drawPixmap(758,396,m_map.m_wall2);
    //中间格子
    for(int i = 518;i<753;i+=48)
    {
        painter.drawPixmap(i,396,m_map.m_floor1);
    }
    //地基左
    for(int i = 444; i<960 ;i+=48)
    {
        painter.drawPixmap(470,i,m_map.m_wall10);
    }
    //右
    for(int i = 444; i<960 ;i+=48)
    {
        painter.drawPixmap(758,i,m_map.m_wall20);
    }
    for(int i = 444; i<960 ;i+=48)
    {
        painter.drawPixmap(518,i,m_map.hole1);
    }
    for(int i = 444; i<960 ;i+=48)
    {
        painter.drawPixmap(566,i,m_map.hole1);
    }
    for(int i = 444; i<960 ;i+=48)
    {
        painter.drawPixmap(614,i,m_map.hole1);
    }
    for(int i = 444; i<960 ;i+=48)
    {
        painter.drawPixmap(662,i,m_map.hole1);
    }
    for(int i = 444; i<960 ;i+=48)
    {
        painter.drawPixmap(710,i,m_map.hole1);
    }



    //空中踏板左

    for(m_map.m_floor1_X = 0; m_map.m_floor1_X<288; m_map.m_floor1_X+=48)
    {
        painter.drawPixmap(m_map.m_floor1_X,500,m_map.m_floor1);
    }
    //右
    for(m_map.m_floor1_X = 1000; m_map.m_floor1_X<GAME_WIDTH; m_map.m_floor1_X+=48)
    {
        painter.drawPixmap(m_map.m_floor1_X,396,m_map.m_floor1);
    }

    //钥匙平台
    if(m_hero.objfinal)
    {
        for(m_map.m_floor1_X = 0; m_map.m_floor1_X<740; m_map.m_floor1_X+=48)
        {
            painter.drawPixmap(m_map.m_floor1_X,200,m_map.m_floor1);
            //房子
            painter.drawPixmap(0,134,66,66,m_map.success);
            m_map.m_Rect6.moveTo(0,200);
            m_map.m_Rect7.moveTo(0,134);
        }
    }

    painter.drawPixmap(1170,360,30,30,m_map.key); //钥匙


//    //空中踏板右
//    for(int i = 1320; i>696; i-=48)
//    {
//        painter.drawPixmap(i,300,50,50,m_map.m_floor1);
//    }


//    painter.drawPixmap(0,730,m_map.m_floor1);
//    painter.drawPixmap(48,730,m_map.m_floor1);

    //绘制人物
//    painter.scale(0.1,0.1);

    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,66,66,m_hero.m_Kakaxi);
    painter.drawPixmap(m_enemy.m_X,m_enemy.m_Y,66,66,m_enemy.m_enemy);


    //绘制手里剑
//    painter.scale(0.5,0.5);
//    for(int i = 0;i < BULLET_NUM;i++)
//    {
//        if(m_hero.m_bullets[i].m_Free == false)
//        {//如果非空闲，绘制手里剑

//                painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,50,50,m_hero.m_bullets[i].m_Bullet);

//        }
//    }

    //绘制敌人
//    for(int i = 0; i < ENEMY_NUM;i++)
//    {
//        if(m_enemys[i].m_Free == false)
//        {
//            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,150,150,m_enemys[i].m_enemy);
//        }
//    }
    
    //绘制爆炸水流
//    for(int i = 0;i < BOMB_NUM;i++)
//    {
//        if(m_bombs[i].m_Free == false)
//        {
//            painter.drawPixmap(384,788,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
//        }
//    }
    //测试手里剑
//    painter.drawPixmap(temp_Bullet.m_X,temp_Bullet.m_Y,temp_Bullet.m_Bullet);
}

void myWidget::mouseMoveEvent(QMouseEvent * event)
{
  int x = event->x() - m_hero.m_Rect.width()*0.5;
  int y = event->y() - m_hero.m_Rect.height()*0.5;

  //边界检测
  if(x <= 0)
  {
      x = 0;
  }
  if(x >= GAME_WIDTH - m_hero.m_Rect.width())
  {
      x = GAME_WIDTH - m_hero.m_Rect.width();
  }
  if(y <= 0)
  {
    y = 0;
  }
  if(y >= GAME_HEIGHT - m_hero.m_Rect.height())
  {
    y = GAME_HEIGHT - m_hero.m_Rect.height();
  }
  m_hero.setPosition(x,y);
}


void myWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_W:
        case Qt::Key_S:
        case Qt::Key_A:
        case Qt::Key_D:
        case Qt::Key_J:
        mKeyList.append(event->key());
        break;
    }
    //边界检测

    //    m_hero.setPosition(x,y);
}


void myWidget::keyReleaseEvent(QKeyEvent *event)
{
    //移除对应按键组合
   if(mKeyList.contains(event->key()))
    {
        mKeyList.removeOne(event->key());

   }
}

void myWidget::HeroMove()
{
    if(canMove)
    {
        for(int keyCode : mKeyList)
        {
            switch (keyCode)
            {
            case Qt::Key_W: m_hero.Jump();break;
            case Qt::Key_S: qDebug() << m_hero.m_Speed;;break;
            case Qt::Key_A:  m_hero.Change(m_hero.m_Kakaxi_left); m_hero.updatePosition(-HERO_SPEED1,0);break;  //人物也移动
            case Qt::Key_D:  m_hero.Change(m_hero.m_Kakaxi_right); m_hero.updatePosition(HERO_SPEED1,0);break;  //人物也移动
    //        case Qt::Key_J: m_hero.shoot(); break;
            }
        }
    }

}

void myWidget::jumpUpdateposition()
{

        //跳跃

//            m_hero.Jump();
         if (m_hero.jumping )
         {



                m_hero.m_Y -= m_hero.m_Speed;
                m_hero.m_Speed -= 1;
                m_hero.m_Rect.moveTo(QPoint(m_hero.m_X, m_hero.m_Y));
                if( m_hero.m_Y >= 666)
                {

                    m_hero.jumping = false;
                    m_hero.m_Speed = 25;
                }
//                if(m_hero.m_Y>=500){
//                    m_hero.jumping = false;
//                    qDebug()<<"                        500";
//                    m_hero.m_Speed = 25;
//                }

         }

//         m_hero.jumping=false;
}



void myWidget::enemyComeout()
{
    m_recorder++;
    //未到出场间隔，直接return
    if(m_recorder < ENEMY_INTERVAL)
    {
        return;
    }
    m_recorder = 0;

//    for(int i = 0;i< ENEMY_NUM; i++)
//    {
//        //如果是空闲
//        if(m_enemys[i].m_Free)
//        {
//            m_enemys[i].m_Free = false;

//            //设置敌人坐标
//            m_enemys[i].m_X =  2560;
//            m_enemys[i].m_Y = rand()%(GAME_HEIGHT - m_enemys[i].m_Rect.height());
//            break;
//        }
//    }

}

void myWidget::collisionDetection()

{


    if(m_hero.m_X <= 0)
    {
        m_hero.m_X = 0;
    }
    if(m_hero.m_X >= GAME_WIDTH - 66)
    {
        m_hero.m_X = GAME_WIDTH - 66;
    }
    if(m_hero.m_Y <= 0)
    {
      m_hero.m_Y = 1;
      m_hero.m_Speed = 0;
    }
    if(m_hero.m_Y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
      m_hero.m_Y = GAME_HEIGHT - m_hero.m_Rect.height();
    }
    //地图碰撞 如果相交 则obj为true，否则为false
    //地图碰撞 如果相交 则无法移动
    //地图碰撞 分为上碰或者下碰，当你下面碰到的时候，会将你碰撞的位置设置为rect.m_y-rect.height

// 地图碰撞 判断相交


//    qDebug() << m_hero.jumping;
    if(m_hero.m_Rect.intersects(m_map.m_Rect) )
    {
        m_hero.obj = true;
    }
    else {
        m_hero.obj = false;

    }
    if(m_hero.obj)
    {
        //将速度变成下落速度
        m_hero.m_Speed = 0;
        if(m_hero.m_Y >= m_map.m_Rect.y())//当人物在下方的时候撞到物体
        {
           m_hero.m_Y = m_map.m_Rect.y()+m_map.m_Rect.height();//修正到物体下方
//           qDebug() << "123";
        }
        else if(m_hero.m_Y <= m_map.m_Rect.y())//当人物在上方的时候撞到物体
        {
           m_hero.m_Y = m_map.m_Rect.y()-m_map.m_Rect.height()-20;//修正到物体上方
//           m_hero.obj = false;
           m_hero.jumping = false;
           m_hero.m_Speed = 25;

        }
        else if(m_hero.m_Y >= m_map.m_Rect.y())
        {
            m_hero.m_Y = m_map.m_Rect.y()+m_map.m_Rect.height();
        }

//        qDebug() << "接触地面!";
    }
    else {
//        qDebug() << "注意脚下!即将掉落";

    }

//    qDebug() << m_hero.jumping;


    if(m_hero.m_Rect.intersects(m_map.m_Rect1) )
    {
        m_hero.obj1 = true;
        qDebug() << "悬崖之上";
    }
    else {
        m_hero.obj1 = false;
//        qDebug() << "pppp";
    }
    if(m_hero.obj1)
    {
        //将速度变成下落速度
        m_hero.m_Speed = 0;
         if(m_hero.m_Y <= m_map.m_Rect1.y())//当人物在上方的时候撞到物体
        {
           m_hero.m_Y = m_map.m_Rect1.y()-66;//修正到物体上方
           m_hero.jumping = false;
           qDebug() << m_map.m_Rect1.y();
           m_hero.m_Speed = 25;

        }
        else if(m_hero.m_X >= m_map.m_Rect1.x())
        {
            m_hero.m_X = m_map.m_Rect1.x()-1;
            qDebug() << m_map.m_Rect1.x();

        }

    }
    else {

    }

    if(m_hero.m_Rect.intersects(m_map.m_Rect2) )
    {
        m_hero.obj2 = true;
        qDebug() << "溺死";
        m_hero.Change(m_hero.m_Kakaxi_dead);
        canMove = false;
        m_hero.m_Rect.moveTo(0,0); //防止系统崩溃
        //进入到死亡场景
        QTimer::singleShot(500,this,[=](){
            otherScene->show();

            this->close();

            qDebug() << "killed";
        });

    }
    else {
        m_hero.obj2 = false;
    }



    if(m_hero.m_Rect.intersects(m_map.m_Rect3) )
    {
        m_hero.obj3 = true;
        m_hero.Change(m_hero.m_Kakaxi_dead);
        canMove = false;
        m_hero.m_Rect.moveTo(0,0); //防止系统崩溃
        //进入到死亡场景
        QTimer::singleShot(500,this,[=](){
            otherScene->show();

            this->close();

            qDebug() << "killed";
        });

    }
    else {
        m_hero.obj3 = false;
    }

    //碰到钥匙
    if(m_hero.m_Rect.intersects(m_map.m_Rect5) )
    {
        m_hero.objfinal = true;
        m_map.key.load("");
        qDebug() << "成功拿到钥匙";
        QSound::play(SOUND_BOMB);
    }
    else {
        m_hero.obj3 = false;
    }

    //碰到房子
    if(m_hero.m_Rect.intersects(m_map.m_Rect7) )
    {
        canMove = false;
        m_hero.m_Rect.moveTo(0,0);
        if(m_hero.objfinal)
        {
            //进入到成功场景
            QTimer::singleShot(500,this,[=](){
                successScene->show();

                this->close();

                qDebug() << "恭喜你通关";
            });
        }
    }
    else {
        m_hero.obj7 = false;
    }

    //碰到怪物
    if(m_hero.m_Rect.intersects(m_enemy.m_Rect) )
    {
        m_hero.obj5 = true;
        m_hero.Change(m_hero.m_Kakaxi_dead);
        canMove = false;
        m_hero.m_Rect.moveTo(0,0); //防止系统崩溃
        //进入到死亡场景
        QTimer::singleShot(500,this,[=](){
            otherScene->show();
            otherScene->setWindowTitle("你被怪物杀死了");
            this->close();

            qDebug() << "killed";
        });

    }
    else {
        m_hero.obj5 = false;
    }

    if(m_hero.m_Rect.intersects(m_map.m_Rect4) )
    {
        m_hero.obj4 = true;
        qDebug() << "裁雨流虹";
    }
    else {
        m_hero.obj4 = false;

    }
    if(m_hero.obj4)
    {
        //将速度变成下落速度
        m_hero.m_Speed = 0;
        if(m_hero.m_Y >= m_map.m_Rect4.y())//当人物在下方的时候撞到物体
        {
           m_hero.m_Y = m_map.m_Rect4.y()+m_map.m_Rect4.height();//修正到物体下方
//           qDebug() << "123";
        }
        else if(m_hero.m_Y <= m_map.m_Rect4.y())//当人物在上方的时候撞到物体
        {
           m_hero.m_Y = m_map.m_Rect4.y()-m_map.m_Rect4.height()-20;//修正到物体上方
//           m_hero.obj = false;
           m_hero.jumping = false;
           m_hero.m_Speed = 25;

        }

//        qDebug() << "接触地面!";
    }
    else {
//        qDebug() << "注意脚下!即将掉落";

    }

    if(m_hero.m_Rect.intersects(m_map.m_Rect6) )
    {
        m_hero.obj6 = true;
        qDebug() << "裁雨流虹";
    }
    else {
        m_hero.obj6 = false;

    }
    if(m_hero.obj6)
    {
        //将速度变成下落速度
        m_hero.m_Speed = 0;
        if(m_hero.m_Y >= m_map.m_Rect6.y())//当人物在下方的时候撞到物体
        {
           m_hero.m_Y = m_map.m_Rect6.y()+m_map.m_Rect6.height();//修正到物体下方
//           qDebug() << "123";
        }
        else if(m_hero.m_Y <= m_map.m_Rect6.y())//当人物在上方的时候撞到物体
        {
           m_hero.m_Y = m_map.m_Rect6.y()-m_map.m_Rect6.height()-20;//修正到物体上方
//           m_hero.obj = false;
           m_hero.jumping = false;
           m_hero.m_Speed = 25;

        }

//        qDebug() << "接触地面!";
    }
    else {
//        qDebug() << "注意脚下!即将掉落";

    }

}





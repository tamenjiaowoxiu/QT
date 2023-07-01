#include "otherscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include "mywidget.h"
#include "QDebug"
OtherScene::OtherScene(QWidget *parent) : QMainWindow(parent)
{
    //死亡场景
    this->setFixedSize(474,588);

    //图标
    this->setWindowIcon(QPixmap(":/res/kakaxi-removebg-preview.png"));

    //标题
    this->setWindowTitle("你溺死了");
    MyPushButton * backBtn = new MyPushButton;
    backBtn->setText("Exit");
    backBtn->setParent(this);
    backBtn->resize(100,100);
    backBtn->move(this->width()-100,this->height()-100);


    connect(backBtn,&MyPushButton::clicked,[=](){
        qDebug() << "yesssss";
        this->close();
    });
}

void OtherScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/deaded.png");
    painter.drawPixmap(0,200,474,59,pix);

}

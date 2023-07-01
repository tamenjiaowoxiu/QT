#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "gouzao";

}

MyPushButton::~MyPushButton()
{
    qDebug() << "xigou";

}

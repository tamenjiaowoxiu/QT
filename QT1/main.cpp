#include "mywidget.h"

#include <QApplication> //包含一个应用程序类的头文件

#include <QResource>
#include "config.h"

//main程序入口 argc命令行变量的数量 argv命令行变量的数组
int main(int argc, char *argv[])
{

    //a应用程序对象，在Qt中，应用程序对象 有且仅有一个
   QApplication a(argc, argv);

   //注册二进制资源文件
   QResource::registerResource("./hhwwcc.rcc");

   //窗口对象 myWidget父类 -> QWidget
    myWidget w;

    //窗口对象 默认不会显示，必须要调用show方法显示窗口
    w.show();


    //让应用程序对象进入消息循环
    //当代码阻塞到这行
    return a.exec();
}

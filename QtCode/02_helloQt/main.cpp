#include <QApplication>
#include <QWidget>//窗口控件基类
#include <QPushButton>//按钮

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    QWidget w;//创建一个窗口
    //设置标题名称
    w.setWindowTitle(QString(u8"主要看气质"));

    QPushButton b;//创建一个按钮b
    b.setText("x_x");//给按钮设定内容
    b.setParent(&w);//指定父对象
    b.move(100,100);//移动按钮坐标

    QPushButton b1(&w);//通过构造函数传参
    b1.setText("abc");
    /*
     *如果不指定父对象，对象和对象（窗口和窗口）没有关系，独立
     * a指定b为它的父对象，a放在b的上面
     * 指定父对象，有两种方式：
     *              1）setParent
     *              2）通过构造函数传参
     * 指定父对象，只需要父对象显示，上面的子对象自动显示
    */
    w.show();

    app.exec();
    return 0;
}

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    //键盘按下事件
    void keyPressEvent(QKeyEvent *e);
    //计时器事件
    void timerEvent(QTimerEvent *e);
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *event);
    //关闭事件
    void closeEvent(QCloseEvent *event);
    //重写event事件
    bool event(QEvent *event);
    //事件过滤器
    bool eventFilter(QObject *obj, QEvent *e);
private:
    Ui::Widget *ui;
    int timerId;
    int timerId2;
};

#endif // WIDGET_H

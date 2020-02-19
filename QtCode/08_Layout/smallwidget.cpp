#include "smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
//通过代码向ui中的widget添加控件
Smallwidget::Smallwidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox *spin=new QSpinBox(this);
    QSlider *slider= new QSlider(Qt::Horizontal,this);
    //把空间添加到布局中
    QHBoxLayout *hLayout= new QHBoxLayout(this);
    hLayout->addWidget(spin);
    hLayout->addWidget(slider);
    //把布局添加到窗口的地方
    //setLayout(hLayout);
    //滑块与微调之间互联
    connect(spin,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider, &QSlider::setValue);
    connect(slider,&QSlider::valueChanged,spin,&QSpinBox::setValue);
}

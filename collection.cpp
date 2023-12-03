#include "collection.h"
#include<QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include<QScrollBar>

collection::collection(QWidget* parent):QWidget(parent)
{
    count = 0;
    add_button = new QPushButton("Add new ");
    m_layout = new QVBoxLayout(this);
    m_layout->addWidget(add_button);

    connect(add_button,&QPushButton::clicked,this,&collection::ClickedSLot);
}

collection::~collection()
{

}
void collection::addNew(QObject* new_object){
    widgets.append(new_object);
    for(int i = 0;i<widgets.size()-1;++i){
        QObject::connect(widgets[i],SIGNAL(valueChanged(int)),widgets[widgets.size()-1],SLOT(setValue(int)));
        QObject::connect(widgets[widgets.size()-1],SIGNAL(valueChanged(int)),widgets[i],SLOT(setValue(int)));
        QObject::connect(widgets[i],SIGNAL(valueChanged(int)),widgets[widgets.size()-1],SLOT(setNum(int)));
        QObject::connect(widgets[widgets.size()-1],SIGNAL(valueChanged(int)),widgets[i],SLOT(setNum(int)));
    }

}

void collection::ClickedSLot()
{
    if(count%4==1) {
        QLabel * label = new QLabel();
        this->addNew(label);
        m_layout->addWidget(label);
        count++;
    }
    else if(count%4==2) {
        QScrollBar* scrollbar = new QScrollBar(Qt::Vertical);
        this->addNew(scrollbar);
        m_layout->addWidget(scrollbar);
        count++;
    }
    else if(count%4==3) {
        QSlider *slider = new QSlider(Qt::Horizontal);
        this->addNew(slider);
        m_layout->addWidget(slider);
        count++;
    }
    else if(count%4==0) {
        QSpinBox *spinbox = new QSpinBox;
        this->addNew(spinbox);
        m_layout->addWidget(spinbox);
        count++;
    }
}

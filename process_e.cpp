#include "process_e.h"
unsigned short process_e::next_id=0;

process_e::process_e(QWidget *parent) : QWidget(parent)
{
    ID=++next_id;
    btn=new QPushButton;
    btn->setParent(this);
    btn->setEnabled(false);
    starting_point=new QLabel;
    starting_point->setParent(this);
    finishing_point=new QLabel;
    finishing_point->setParent(this);
}

void process_e::InputProcess(unsigned short duration , unsigned short arrival_t, unsigned short priority)
{
    this->duration=duration;
    this->arrival_t=arrival_t;
    this->priority=priority;
}

void process_e::DrawProcess(short x, short y, unsigned short starting_point_time)
{
    btn->setStyleSheet("color: black;"
                       "background-color:yellow");
    QString s;
    s="P"+QString::number(ID);
    btn->setText(s);
    btn->setGeometry(x,y,this->width,60);
    starting_point->setText(QString::number(starting_point_time));
    starting_point->setStyleSheet("background-color: rgba(0,0,0,0%)");
    starting_point->setGeometry(x-3,y+60+5,20,20);
    finishing_point->setText(QString::number(starting_point_time+duration));
    finishing_point->setStyleSheet("background-color: rgba(0,0,0,0%)");
    finishing_point->setGeometry(x-3+width,y+60+5,20,20);
    btn->show();
    starting_point->show();
    finishing_point->show();
}

process_e::~process_e()
{
    delete btn;
}

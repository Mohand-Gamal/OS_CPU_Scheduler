#ifndef PROCESS_E_H
#define PROCESS_E_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <stdlib.h>
#include <QString>
#include <QLabel>
class process_e : public QWidget
{
    Q_OBJECT
public:
    explicit process_e(QWidget *parent = nullptr);
    void InputProcess(unsigned short duration , unsigned short arrival_t, unsigned short priority);
    void DrawProcess(short x, short y, unsigned short starting_point_time);
    ~process_e();
private:
    static unsigned short next_id;
    unsigned short ID;
    unsigned short duration;
    unsigned short arrival_t;
    unsigned short priority;
    unsigned short waiting_t;
    QPushButton *btn;
    QLabel *starting_point;
    QLabel *finishing_point;
    unsigned short width;
    friend class simulate;
};

#endif // PROCESS_E_H

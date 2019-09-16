#ifndef SIMULATE_H
#define SIMULATE_H

#include <QObject>
#include <QWidget>
#include "process_e.h"
#include <QLabel>
#include <QTextEdit>
#include<QPushButton>
#include <stdlib.h>
#include <QString>
#include<QSpinBox>
#include<QComboBox>
#include <QDebug>
#include <string>
#include <QVector>
class simulate : public QWidget
{
    Q_OBJECT
public:
    explicit simulate(QWidget *parent = nullptr);
    void FCFS();
    void SJF_non();
    void SJF_pre();
    void Priority_non();
    void Priority_pre();
    void RR();
    void DrawOutput();
    void RRmergeSort(process_e* arr[], int l, int r) ;
    void RRmerge(process_e* arr[], int l, int m, int r) ;
    void bubble_sort_sjf(process_e* arr[]);
    void bubble_sort_rr(process_e* arr[]);
    void bubble_sort_priority(process_e* arr[]);
private:
    unsigned short no_in_processes;
    process_e *input_processes_arr[10];
    process_e *processes_arr[10];
    unsigned short no_out_processes;
    process_e *output_processes_arr[50];
    unsigned short quantum;
    bool preemptive;
    bool priority;
    bool rr;
    static int process_counter;
    QPushButton *processes_no_btn;
    QPushButton *scheduler_type_btn;
    QPushButton *process_submit_btn;
    QSpinBox *no_processes;
    QSpinBox *priority_input;
    QSpinBox *duration_input;
    QSpinBox *arrival_t_input;
    QSpinBox *quantum_input;
    QLabel *priority_label;
    QLabel *duration_label;
    QLabel *arrival_t_label;
    QLabel *quantum_label;
    QLabel *user_info_label;
    QLabel *process_label;
    QComboBox *scheduler_choice;

public slots:
    void no_process_chosen();
    void scheduler_chosen();
    void TakeInput();

signals:
    void process_remain();
};

#endif // SIMULATE_H

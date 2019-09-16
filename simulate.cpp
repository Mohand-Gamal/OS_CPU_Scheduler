 #include "simulate.h"

int simulate::process_counter=0;

simulate::simulate(QWidget *parent) : QWidget(parent)
{
    this->setFixedHeight(600);
    this->setMinimumWidth(1100);
    this->setMaximumWidth(10000);
    processes_no_btn = new QPushButton("Submit",this);
    scheduler_type_btn = new QPushButton("Submit",this);
    process_submit_btn = new QPushButton(this);
    no_processes = new QSpinBox;
    priority_input= new QSpinBox;
    duration_input= new QSpinBox;
    arrival_t_input= new QSpinBox;
    quantum_input= new QSpinBox;
    user_info_label=new QLabel;
    process_label=new QLabel;
    priority_label=new QLabel;
    duration_label=new QLabel;
    arrival_t_label=new QLabel;
    quantum_label=new QLabel;
    scheduler_choice=new QComboBox;
    user_info_label->setText("Please Enter the Number of Processes");
    user_info_label->setGeometry(450,250,250,30);
    no_processes->setGeometry(450,300,170,30);
    no_processes->setMinimum(1);
    no_processes->setMaximum(10);
    no_processes->setSingleStep(1);
    priority_input->setMinimum(1);
    priority_input->setMaximum(10);
    priority_input->setSingleStep(1);
    duration_input->setMinimum(1);
    duration_input->setMaximum(10);
    duration_input->setSingleStep(1);
    arrival_t_input->setMinimum(0);
    arrival_t_input->setMaximum(100);
    arrival_t_input->setSingleStep(1);
    quantum_input->setMinimum(1);
    quantum_input->setMaximum(10);
    quantum_input->setSingleStep(1);
    processes_no_btn->setGeometry(650,300,100,30);
    scheduler_type_btn->setGeometry(650,300,100,30);
    process_submit_btn->setGeometry(650,300,100,30);
    no_processes->setParent(this);
    user_info_label->setParent(this);
    scheduler_choice->setParent(this);
    process_label->setParent(this);
    priority_input->setParent(this);
    duration_input->setParent(this);
    arrival_t_input->setParent(this);
    quantum_input->setParent(this);
    scheduler_type_btn->hide();
    process_submit_btn->hide();
    scheduler_choice->hide();
    priority_input->hide();
    duration_input->hide();
    arrival_t_input->hide();
    quantum_input->hide();
    priority_label->setParent(this);
    duration_label->setParent(this);
    arrival_t_label->setParent(this);
    quantum_label->setParent(this);
    connect(processes_no_btn,SIGNAL(pressed()),this,SLOT(no_process_chosen()));
}

void simulate::no_process_chosen(){
    no_in_processes=no_processes->value();
    no_processes->hide();
    processes_no_btn->hide();
    scheduler_type_btn->show();
    scheduler_choice->show();
    scheduler_choice->addItem("FCFS");
    scheduler_choice->addItem("SJF Preemptive");
    scheduler_choice->addItem("SJF Non-Preemptive");
    scheduler_choice->addItem("Priority Preemptive");
    scheduler_choice->addItem("Priority Non-Preemptive");
    scheduler_choice->addItem("Round-Robin");
    scheduler_choice->setGeometry(450,300,170,30);
    user_info_label->setText("Choose The Type of the scheduler");
    connect(scheduler_type_btn,SIGNAL(pressed()),this,SLOT(scheduler_chosen()));
}

void simulate::scheduler_chosen(){
    scheduler_choice->hide();
    scheduler_type_btn->hide();
    process_submit_btn->show();
    if((scheduler_choice->currentText()=="FCFS")||(scheduler_choice->currentText()=="SJF Non-Preemptive"))
    {
        preemptive=0;
        priority=0;
        rr=0;
    }
    else if ((scheduler_choice->currentText()=="SJF Preemptive")) {
        preemptive=1;
        priority=0;
        rr=0;
    }
    else if ((scheduler_choice->currentText()=="Priority Preemptive")) {
        preemptive=1;
        priority=1;
        rr=0;
    }
    else if ((scheduler_choice->currentText()=="Priority Non-Preemptive")) {
        preemptive=0;
        priority=1;
        rr=0;
    }
    else if ((scheduler_choice->currentText()=="Round-Robin")) {
        preemptive=1;
        priority=0;
        rr=1;
    }
    process_submit_btn->setText("Submit P"+QString::number(process_counter+1));
    user_info_label->setText("Enter the info for each process");
    if(priority==1)
    {
        process_label->setGeometry(200,300,100,30);
        process_label->setStyleSheet("font:10pt");
        process_submit_btn->setGeometry(750,300,100,30);
        priority_label->setText("Priority:");
        priority_label->setGeometry(320,300,50,30);
        priority_input->show();
        priority_input->setGeometry(370,300,50,30);
        duration_label->setText("Duration:");
        duration_label->setGeometry(450,300,50,30);
        duration_input->show();
        duration_input->setGeometry(500,300,50,30);
        arrival_t_label->setText("Arrival:");
        arrival_t_label->setGeometry(580,300,50,30);
        arrival_t_input->show();
        arrival_t_input->setGeometry(630,300,50,30);
        process_label->setText("P"+QString::number(process_counter+1));
    }
    else if(rr==1)
    {
        process_label->setGeometry(410,300,100,30);
        process_label->setStyleSheet("font:10pt");
        process_submit_btn->setGeometry(750,300,100,30);
        quantum_label->setText("Quantum for all Processes:");
        quantum_label->setGeometry(150,300,150,30);
        quantum_input->show();
        quantum_input->setGeometry(300,300,50,30);
        duration_label->setText("Duration:");
        duration_label->setGeometry(450,300,50,30);
        duration_input->show();
        duration_input->setGeometry(500,300,50,30);
        arrival_t_label->setText("Arrival:");
        arrival_t_label->setGeometry(580,300,50,30);
        arrival_t_input->show();
        arrival_t_input->setGeometry(630,300,50,30);
        process_label->setText("P"+QString::number(process_counter+1));
    }
    else
    {
        process_label->setGeometry(340,300,100,30);
        process_label->setStyleSheet("font:10pt");
        process_submit_btn->setGeometry(750,300,100,30);
        duration_label->setText("Duration:");
        duration_label->setGeometry(450,300,50,30);
        duration_input->show();
        duration_input->setGeometry(500,300,50,30);
        arrival_t_label->setText("Arrival:");
        arrival_t_label->setGeometry(580,300,50,30);
        arrival_t_input->show();
        arrival_t_input->setGeometry(630,300,50,30);
        process_label->setText("P"+QString::number(process_counter+1));
    }
    connect(process_submit_btn,SIGNAL(pressed()),this,SLOT(TakeInput()));
}

void simulate::TakeInput()
{
    input_processes_arr[process_counter]=new process_e;
    input_processes_arr[process_counter]->duration=duration_input->value();
    input_processes_arr[process_counter]->priority=priority_input->value();
    input_processes_arr[process_counter]->arrival_t=arrival_t_input->value();
    quantum=quantum_input->value();
    if(process_counter<no_in_processes-1)
    {
        duration_input->setValue(duration_input->minimum());
        priority_input->setValue(priority_input->minimum());
        arrival_t_input->setValue(arrival_t_input->minimum());
        process_counter++;
        if(process_counter>0){
        quantum_label->hide();
        quantum_input->hide();}
        process_label->setText("P"+QString::number(process_counter+1));
        process_submit_btn->setText("Submit P"+QString::number(process_counter+1));
    }
    else
    {
        process_submit_btn->hide();
        process_label->hide();
        priority_label->hide();
        priority_input->hide();
        duration_label->hide();
        duration_input->hide();
        arrival_t_label->hide();
        arrival_t_input->hide();
        quantum_label->hide();
        quantum_input->hide();
        if((scheduler_choice->currentText()=="FCFS"))
        {
            FCFS();
        }
        else if ((scheduler_choice->currentText()=="SJF Preemptive"))
        {
            SJF_pre();
        }
        else if((scheduler_choice->currentText()=="SJF Non-Preemptive"))
        {
            SJF_non();
        }
        else if ((scheduler_choice->currentText()=="Priority Preemptive"))
        {
            Priority_pre();
        }
        else if((scheduler_choice->currentText()=="Priority Non-Preemptive"))
        {
            Priority_non();
        }
        else if ((scheduler_choice->currentText()=="Round-Robin")) {
            RR();
        }

        //for testing
        for(int i=0;i<no_out_processes;i++)
        {
            qDebug()<<output_processes_arr[i]->ID<<" "<<input_processes_arr[output_processes_arr[i]->ID-1]->arrival_t<<" "<<output_processes_arr[i]->arrival_t<<" "<<output_processes_arr[i]->duration<<" "<<output_processes_arr[i]->priority;
        }

        DrawOutput();
    }
}

void simulate::FCFS(){
    no_out_processes=no_in_processes;
    process_e *temp_processes_arr[10];
    for (int i=0;i<no_in_processes;i++)
    {
        temp_processes_arr[i]=new process_e;
        temp_processes_arr[i]->ID=input_processes_arr[i]->ID;
        temp_processes_arr[i]->duration=input_processes_arr[i]->duration;
        temp_processes_arr[i]->arrival_t=input_processes_arr[i]->arrival_t;
    }
    for(int i=0; i<no_out_processes-1;i++)
    {
        for(int j=0; j<no_out_processes-i-1;j++)
        {
            if(temp_processes_arr[j]->arrival_t>temp_processes_arr[j+1]->arrival_t)
            {
                process_e *temp=temp_processes_arr[j];
                temp_processes_arr[j]=temp_processes_arr[j+1];
                temp_processes_arr[j+1]=temp;
            }
        }
    }
    output_processes_arr[0]=new process_e;
    output_processes_arr[0]->ID=temp_processes_arr[0]->ID;
    output_processes_arr[0]->duration=temp_processes_arr[0]->duration;
    output_processes_arr[0]->arrival_t=temp_processes_arr[0]->arrival_t;
    for(int i=1;i<no_out_processes;i++)
    {
        output_processes_arr[i]=new process_e;
        output_processes_arr[i]->ID=temp_processes_arr[i]->ID;
        output_processes_arr[i]->duration=temp_processes_arr[i]->duration;
        if(output_processes_arr[i-1]->arrival_t+output_processes_arr[i-1]->duration < temp_processes_arr[i]->arrival_t )
        {
            output_processes_arr[i]->arrival_t=temp_processes_arr[i]->arrival_t;
        }
        else
        {
            output_processes_arr[i]->arrival_t = output_processes_arr[i-1]->arrival_t+output_processes_arr[i-1]->duration;

        }
    }
}

void simulate::SJF_non(){
     no_out_processes=0;
     process_e *temp_processes_arr[10];
     unsigned short sampling_t=0;
     bool process_status[10];
     QVector<process_e*>selected_processes;
    for (int i=0;i<no_in_processes;i++)
    {
        temp_processes_arr[i]=new process_e;
        temp_processes_arr[i]->ID=input_processes_arr[i]->ID;
        temp_processes_arr[i]->duration=input_processes_arr[i]->duration;
        temp_processes_arr[i]->arrival_t=input_processes_arr[i]->arrival_t;
        process_status[i]=false;
    }
    unsigned short min_arrival_t=input_processes_arr[0]->arrival_t;
    for(int i=1;i<no_in_processes;i++)
    {
        if(input_processes_arr[i]->arrival_t<min_arrival_t)
        {
            min_arrival_t=input_processes_arr[i]->arrival_t;
        }
    }
    sampling_t=min_arrival_t;
    for(int sampling_no=0; sampling_no<no_in_processes; sampling_no++)
    {
        for(int i=0;i<no_in_processes;i++)
        {
            if(temp_processes_arr[i]->arrival_t<=sampling_t && process_status[i]==false)
            {
                selected_processes.push_back(temp_processes_arr[i]);
            }
        }
        if(selected_processes.size()==1)
        {
            output_processes_arr[no_out_processes]=selected_processes[0];
            output_processes_arr[no_out_processes]->arrival_t=sampling_t;
            process_status[selected_processes[0]->ID-1]=true;
            selected_processes.clear();
        }
        else
        {
            process_e *min_duration_process=selected_processes[0];
            for(int i=1;i<selected_processes.size();i++)
            {
                if( selected_processes[i]->duration < min_duration_process->duration )
                {
                    min_duration_process=selected_processes[i];
                }
            }
            output_processes_arr[no_out_processes]=min_duration_process;
            output_processes_arr[no_out_processes]->arrival_t=sampling_t;
            process_status[min_duration_process->ID-1]=true;
            selected_processes.clear();
        }

        min_arrival_t=500;
        for(int i=0;i<no_in_processes;i++)
        {
            if(input_processes_arr[i]->arrival_t<min_arrival_t && process_status[i]==false)
            {
                min_arrival_t=input_processes_arr[i]->arrival_t;
            }
        }
        if(output_processes_arr[no_out_processes]->arrival_t+output_processes_arr[no_out_processes]->duration >min_arrival_t)
        {
            sampling_t=output_processes_arr[no_out_processes]->arrival_t+output_processes_arr[no_out_processes]->duration;
        }
        else
        {
            sampling_t=min_arrival_t;
        }

        no_out_processes++;
    }
}

void simulate::SJF_pre()
{
    no_out_processes=0;
    process_e *temp_processes_arr[10];
    process_e *target_process;
    unsigned short sampling_t=0;
    unsigned short old_duration;
    bool process_status[10];
    QVector<process_e*>selected_processes;
    unsigned short old_sampling_t=0;
   for (int i=0;i<no_in_processes;i++)
   {
       temp_processes_arr[i]=new process_e;
       temp_processes_arr[i]->ID=input_processes_arr[i]->ID;
       temp_processes_arr[i]->duration=input_processes_arr[i]->duration;
       temp_processes_arr[i]->arrival_t=input_processes_arr[i]->arrival_t;
       process_status[i]=false;
   }

   unsigned short min_arrival_t=input_processes_arr[0]->arrival_t;
   for(int i=1;i<no_in_processes;i++)
   {
       if(input_processes_arr[i]->arrival_t<min_arrival_t)
       {
           min_arrival_t=input_processes_arr[i]->arrival_t;
       }
   }
   sampling_t=min_arrival_t;

   while(true)
   {
       old_sampling_t=sampling_t;
       for(int i=0;i<no_in_processes;i++)
       {
           if(temp_processes_arr[i]->arrival_t<=sampling_t && process_status[i]==false)
           {
               selected_processes.push_back(temp_processes_arr[i]);
           }
       }
       if(selected_processes.size()==1)
       {
           target_process=selected_processes[0];
           selected_processes.clear();
       }
       else
       {
           process_e *min_duration_process=selected_processes[0];
           for(int i=1;i<selected_processes.size();i++)
           {
               if( selected_processes[i]->duration < min_duration_process->duration )
               {
                   min_duration_process=selected_processes[i];
               }
           }
           target_process=min_duration_process;
           selected_processes.clear();
       }
       old_duration=target_process->duration;
       for(int i=0;i<no_in_processes;i++)
       {
           if( temp_processes_arr[i]->arrival_t>sampling_t && temp_processes_arr[i]->arrival_t<sampling_t+target_process->duration && process_status[i]==false && temp_processes_arr[i]!=target_process)
           {
               if(temp_processes_arr[i]->duration<target_process->duration + sampling_t - temp_processes_arr[i]->arrival_t)
               {
                    selected_processes.push_back(temp_processes_arr[i]);
               }
           }
       }
       if(selected_processes.size()>=1)
       {
           process_e *interrupt_process=selected_processes[0];
           for(int i=1;i<selected_processes.size();i++)
           {
               if( selected_processes[i]->arrival_t < interrupt_process->arrival_t )
               {
                   interrupt_process=selected_processes[i];
               }
           }
           selected_processes.clear();
           target_process->duration=sampling_t+old_duration-interrupt_process->arrival_t;
           sampling_t= interrupt_process->arrival_t;
           if(target_process->duration==0)
           {
               process_status[target_process->ID-1]=true;
           }
       }
       else
       {
           target_process->duration=0;
           process_status[target_process->ID-1]=true;
           min_arrival_t=500;
           for(int i=0;i<no_in_processes;i++)
           {
               if(input_processes_arr[i]->arrival_t<min_arrival_t && process_status[i]==false)
               {
                   min_arrival_t=input_processes_arr[i]->arrival_t;
               }
           }
           if(sampling_t+old_duration >min_arrival_t)
           {
               sampling_t+=old_duration;
           }
           else
           {
               sampling_t=min_arrival_t;
           }
       }
        output_processes_arr[no_out_processes]=new process_e;
        output_processes_arr[no_out_processes]->ID=target_process->ID;
        output_processes_arr[no_out_processes]->duration=old_duration-target_process->duration;
        output_processes_arr[no_out_processes]->arrival_t=old_sampling_t;
        no_out_processes++;
        bool flag=true;
        for(int i=0;i<no_in_processes;i++)
        {
            if(process_status[i]==false)
            {
              flag=false;
            }
        }
        if(flag)
        {
            break;
        }
   }
}

void simulate::Priority_non()
{
    no_out_processes=0;
    process_e *temp_processes_arr[10];
    unsigned short sampling_t=0;
    bool process_status[10];
    QVector<process_e*>selected_processes;
   for (int i=0;i<no_in_processes;i++)
   {
       temp_processes_arr[i]=new process_e;
       temp_processes_arr[i]->ID=input_processes_arr[i]->ID;
       temp_processes_arr[i]->duration=input_processes_arr[i]->duration;
       temp_processes_arr[i]->arrival_t=input_processes_arr[i]->arrival_t;
       temp_processes_arr[i]->priority=input_processes_arr[i]->priority;
       process_status[i]=false;
   }
   unsigned short min_arrival_t=input_processes_arr[0]->arrival_t;
   for(int i=1;i<no_in_processes;i++)
   {
       if(input_processes_arr[i]->arrival_t<min_arrival_t)
       {
           min_arrival_t=input_processes_arr[i]->arrival_t;
       }
   }
   sampling_t=min_arrival_t;
   for(int sampling_no=0; sampling_no<no_in_processes; sampling_no++)
   {
       for(int i=0;i<no_in_processes;i++)
       {
           if(temp_processes_arr[i]->arrival_t<=sampling_t && process_status[i]==false)
           {
               selected_processes.push_back(temp_processes_arr[i]);
           }
       }
       if(selected_processes.size()==1)
       {
           output_processes_arr[no_out_processes]=selected_processes[0];
           output_processes_arr[no_out_processes]->arrival_t=sampling_t;
           process_status[selected_processes[0]->ID-1]=true;
           selected_processes.clear();
       }
       else
       {
           process_e *max_priority_process=selected_processes[0];
           for(int i=1;i<selected_processes.size();i++)
           {
               if(selected_processes[i]->priority < max_priority_process->priority )
               {
                  max_priority_process=selected_processes[i];

               }
           }
           output_processes_arr[no_out_processes]=max_priority_process;
           output_processes_arr[no_out_processes]->arrival_t=sampling_t;
           process_status[max_priority_process->ID-1]=true;
           selected_processes.clear();
       }
       min_arrival_t=500;
       for(int i=0;i<no_in_processes;i++)
       {
           if(input_processes_arr[i]->arrival_t<min_arrival_t && process_status[i]==false)
           {
               min_arrival_t=input_processes_arr[i]->arrival_t;
           }
       }
       if(output_processes_arr[no_out_processes]->arrival_t+output_processes_arr[no_out_processes]->duration >min_arrival_t)
       {
           sampling_t=output_processes_arr[no_out_processes]->arrival_t+output_processes_arr[no_out_processes]->duration;
       }
       else
       {
           sampling_t=min_arrival_t;
       }

       no_out_processes++;
   }
}

void simulate::Priority_pre(){

no_out_processes=0;
process_e *temp_processes_arr[10];
process_e *target_process;
unsigned short sampling_t=0;
unsigned short old_duration;
bool process_status[10];
QVector<process_e*>selected_processes;
unsigned short old_sampling_t=0;
for (int i=0;i<no_in_processes;i++)
{
   temp_processes_arr[i]=new process_e;
   temp_processes_arr[i]->ID=input_processes_arr[i]->ID;
   temp_processes_arr[i]->duration=input_processes_arr[i]->duration;
   temp_processes_arr[i]->arrival_t=input_processes_arr[i]->arrival_t;
   temp_processes_arr[i]->priority=input_processes_arr[i]->priority;
   process_status[i]=false;
}

unsigned short min_arrival_t=input_processes_arr[0]->arrival_t;
for(int i=1;i<no_in_processes;i++)
{
    if(input_processes_arr[i]->arrival_t<min_arrival_t)
    {
        min_arrival_t=input_processes_arr[i]->arrival_t;
    }
}
sampling_t=min_arrival_t;

while(true)
{
   old_sampling_t=sampling_t;
   for(int i=0;i<no_in_processes;i++)
   {
       if(temp_processes_arr[i]->arrival_t<=sampling_t && process_status[i]==false)
       {
           selected_processes.push_back(temp_processes_arr[i]);
       }
   }
   if(selected_processes.size()==1)
   {
       target_process=selected_processes[0];
       selected_processes.clear();
   }
   else
   {
       process_e *max_priority_process=selected_processes[0];
       for(int i=1;i<selected_processes.size();i++)
       {
           if( selected_processes[i]->priority < max_priority_process->priority )
           {
               max_priority_process=selected_processes[i];
           }
       }
       target_process=max_priority_process;
       selected_processes.clear();
   }
   old_duration=target_process->duration;
   for(int i=0;i<no_in_processes;i++)
   {
       if( temp_processes_arr[i]->arrival_t>sampling_t && temp_processes_arr[i]->arrival_t<sampling_t+target_process->duration && process_status[i]==false && temp_processes_arr[i]!=target_process)
       {
           if(temp_processes_arr[i]->priority < target_process->priority)
           {
                selected_processes.push_back(temp_processes_arr[i]);
           }
       }
   }
   if(selected_processes.size()>=1)
   {
       process_e *interrupt_process=selected_processes[0];
       for(int i=1;i<selected_processes.size();i++)
       {
           if( selected_processes[i]->arrival_t < interrupt_process->arrival_t )
           {
               interrupt_process=selected_processes[i];
           }
       }
       selected_processes.clear();
       target_process->duration=sampling_t+old_duration-interrupt_process->arrival_t;
       sampling_t= interrupt_process->arrival_t;
       if(target_process->duration==0)
       {
           process_status[target_process->ID-1]=true;
       }
   }
   else
   {
       target_process->duration=0;
       process_status[target_process->ID-1]=true;
       min_arrival_t=500;
       for(int i=0;i<no_in_processes;i++)
       {
           if(input_processes_arr[i]->arrival_t<min_arrival_t && process_status[i]==false)
           {
               min_arrival_t=input_processes_arr[i]->arrival_t;
           }
       }
       if(sampling_t+old_duration >min_arrival_t)
       {
           sampling_t+=old_duration;
       }
       else
       {
           sampling_t=min_arrival_t;
       }
   }

    output_processes_arr[no_out_processes]=new process_e;
    output_processes_arr[no_out_processes]->ID=target_process->ID;
    output_processes_arr[no_out_processes]->duration=old_duration-target_process->duration;
    output_processes_arr[no_out_processes]->arrival_t=old_sampling_t;
    output_processes_arr[no_out_processes]->priority=target_process->priority;
    no_out_processes++;
    bool flag=true;
    for(int i=0;i<no_in_processes;i++)
    {
        if(process_status[i]==false)
        {
          flag=false;
        }
    }
    if(flag)
    {
        break;
    }
}
}

void simulate::RR()
{
    no_out_processes=0;
    process_e *temp_processes_arr[10];
    process_e *target_process;
    unsigned short sampling_t=0;
    unsigned short old_duration;
    bool process_status[10];
    QVector<process_e*>selected_processes;
    unsigned short old_sampling_t=0;
    for (int i=0;i<no_in_processes;i++)
    {
       temp_processes_arr[i]=new process_e;
       temp_processes_arr[i]->ID=input_processes_arr[i]->ID;
       temp_processes_arr[i]->duration=input_processes_arr[i]->duration;
       temp_processes_arr[i]->arrival_t=input_processes_arr[i]->arrival_t;
       process_status[i]=false;
    }
    unsigned short min_arrival_t=input_processes_arr[0]->arrival_t;
    for(int i=1;i<no_in_processes;i++)
    {
        if(input_processes_arr[i]->arrival_t<min_arrival_t)
        {
            min_arrival_t=input_processes_arr[i]->arrival_t;
        }
    }
    sampling_t=min_arrival_t;
    bool not_first=false;
    while(true)
    {
        old_sampling_t=sampling_t;
       for(int i=0;i<no_in_processes;i++)
       {
           if(temp_processes_arr[i]->arrival_t==sampling_t && process_status[i]==false)
           {
                   bool flag1=true;
                   for(int j=0; j<selected_processes.size();j++)
                   {
                       if(selected_processes[j]==temp_processes_arr[i])
                       {
                         flag1=false;
                       }
                   }
                   if(flag1)
                   {
                      selected_processes.push_back(temp_processes_arr[i]);
                   }
          }
          if(temp_processes_arr[i]->arrival_t<sampling_t && process_status[i]==false)
           {
                   bool flag2=true;
                   for(int j=0; j<selected_processes.size();j++)
                   {
                       if(selected_processes[j]==temp_processes_arr[i])
                       {
                         flag2=false;
                       }
                   }
                   if(flag2)
                   {
                      selected_processes.push_back(temp_processes_arr[i]);
                   }
          }
       }
       if(not_first)
       {
          selected_processes.pop_front();
          if(target_process->duration>0)
          {
              selected_processes.push_back(target_process);
          }
       }
       not_first=true;
       target_process=selected_processes[0];
       old_duration=target_process->duration;
       if(target_process->duration>=quantum)
       {
          target_process->duration=old_duration-quantum;
          sampling_t+=quantum;
       }
       else
       {
           target_process->duration=0;
           sampling_t+= old_duration;
       }
       if(target_process->duration==0)
       {
           process_status[target_process->ID-1]=true;
           min_arrival_t=500;
           for(int i=0;i<no_in_processes;i++)
           {
               if(input_processes_arr[i]->arrival_t<min_arrival_t && process_status[i]==false)
               {
                   min_arrival_t=input_processes_arr[i]->arrival_t;
               }
           }
           if(sampling_t <min_arrival_t)
           {
               sampling_t=min_arrival_t;
           }
       }
        output_processes_arr[no_out_processes]=new process_e;
        output_processes_arr[no_out_processes]->ID=target_process->ID;
        if(old_duration>=quantum)
        {
            output_processes_arr[no_out_processes]->duration=quantum;
        }
        else
        {
           output_processes_arr[no_out_processes]->duration=old_duration;
        }
        output_processes_arr[no_out_processes]->arrival_t=old_sampling_t;
        no_out_processes++;
        bool flag=true;
        for(int i=0;i<no_in_processes;i++)
        {
            if(process_status[i]==false)
            {
              flag=false;
            }
        }
        if(flag)
        {
            break;
        }
    }

}

void simulate::DrawOutput()
{
    for(int i=0;i<no_in_processes;i++)
    {
        unsigned short departure_t;
        unsigned short duration_sum=0;
        for(int j=0;j<no_out_processes;j++)
        {
            if(output_processes_arr[no_out_processes-j-1]->ID==i+1)
            {
                departure_t=output_processes_arr[no_out_processes-j-1]->arrival_t+output_processes_arr[no_out_processes-j-1]->duration;
                break;
            }
        }
        for(int j=0;j<no_out_processes;j++)
        {
            if(output_processes_arr[j]->ID==i+1)
            {
                duration_sum+=output_processes_arr[j]->duration;
            }
        }
        input_processes_arr[i]->waiting_t=departure_t-input_processes_arr[i]->arrival_t-duration_sum;
    }
    for(int i=0;i<no_out_processes;i++)
    {
        output_processes_arr[i]->width=output_processes_arr[i]->duration*30; //mapping duration to the width
        output_processes_arr[i]->DrawProcess(output_processes_arr[i]->arrival_t*30+100,300,output_processes_arr[i]->arrival_t);
        output_processes_arr[i]->setParent(this);
        output_processes_arr[i]->show();
    }
    unsigned short sum_waiting_t=0;
    for(int i=0;i<no_in_processes;i++)
    {
        sum_waiting_t+=input_processes_arr[i]->waiting_t;
    }
    user_info_label->setText("Average waiting time = " + QString::number(float(sum_waiting_t)/no_in_processes));
    user_info_label->setGeometry(450,200,250,50);
}

//
//  main.cpp
//  EmulatorV1
//
//  Created by Kartik Rattan on 11/15/19.
//  Copyright © 2019 Kartik Rattan. All rights reserved.
//

#include <iostream>
#include <map>
#include "Resource.h"
#include "workload.h"
#include <unistd.h>     //for using the function sleep

#include <fstream>

void compute_schedule(workload &w, Resource &r, vector<pair<task,node>>& schedule);
void print_schedule(vector<pair<task,node>>& schedule);

void compute_schedule_random(workload &w, Resource &r, vector<pair<task,node>>& schedule);
void print_schedule_random(vector<pair<task,node>>& schedule);

double total_time_execute_random(vector<pair<task,node>> &schedule_random);
double total_time_execute(vector<pair<task,node>> &schedule);


int main(int argc, const char * argv[]) {
    
    /*int number_pi;
    int number_fog;
    int number_hpc;
    
    int number_task;
    
    cout << "Enter the number of pi resources: ";
    cin >> number_pi;
    
    cout << "Enter the number of fog resources: ";
    cin >> number_fog;
    
    cout << "Enter the number of hpc resources: ";
    cin >> number_hpc;
    
    cout << "Number of task in the workload: ";
    cin >> number_task;
    
    
    workload w(number_task);
    Resource r(number_pi,number_fog,number_hpc);
    vector<pair<task,node>> schedule;
    vector<pair<task,node>> schedule_random;
    
    compute_schedule(w,r,schedule);
    print_schedule(schedule);
    
    compute_schedule_random(w,r,schedule_random);
    print_schedule_random(schedule_random);
    
    cout << "Total execution time by random assignment:" << total_time_execute_random(schedule_random);
    cout << "Total execution time by L2FF assignment:" << total_time_execute(schedule);*/
    
    //for experimentation
    
    vector<int> number_tasks{9,27,81,243,729};
    cout << number_tasks.size() << endl;
    vector<double> exec_time_L2ff;
    vector<double> exec_time_random;
    
    int iter = 10;
    
    for(int i = 0; i<number_tasks.size(); i++)
    {
        for(int j=0;j<iter;j++)
        {
            int number_task_exp = number_tasks[i];
            int number_pi_exp = number_task_exp / 3;
            int number_fog_exp = number_task_exp / 3;
            int number_hpc_exp = number_task_exp / 3;
            
            workload w_exp(number_task_exp);
            Resource r_exp(number_pi_exp,number_fog_exp,number_hpc_exp);
            
            vector<pair<task,node>> schedule_exp;
            vector<pair<task,node>> schedule_random_exp;
            
            compute_schedule(w_exp,r_exp,schedule_exp);
            compute_schedule_random(w_exp,r_exp,schedule_random_exp);
            
            exec_time_L2ff.push_back(total_time_execute_random(schedule_exp));
            exec_time_random.push_back(total_time_execute(schedule_random_exp));
            
        }
            
    }
    ofstream write;
    write.open("stat_dis_indis.txt");
    for(int i=0;i<exec_time_L2ff.size();i++)
    {
        write << exec_time_L2ff[i]<<endl;
    }
    for(int i=0;i<exec_time_L2ff.size();i++)
    {
        write << exec_time_random[i] << endl;
    }
    /*for(int i=0;i<exec_time_L2ff.size();i++)
    {
        write << "For l2ff with " << number_tasks[i] << " tasks "<< exec_time_L2ff[i] << endl;
        write << "For random with " << number_tasks[i] << " tasks "<< exec_time_random[i] << endl;
    }*/
    return 0;
}
void compute_schedule_random(workload &w, Resource &r, vector<pair<task,node>> &schedule_random)
{
    queue<task> tq = w.return_task_queue_random();
    queue<node> nq = r.return_node_list_random();
    
    for(int i = 0; i<w.return_number_task(); i++)
    {
        task temp_task = tq.front();
        tq.pop();
        
        node temp_node = nq.front();
        nq.pop();
        
        pair<task,node> p;
        p.first = temp_task;
        p.second = temp_node;
        
        schedule_random.push_back(p);
    }
}
void compute_schedule(workload &w, Resource &r, vector<pair<task,node>>& schedule)
{
    priority_queue<task> tq = w.return_task_queue();
    priority_queue<node> nq = r.return_resource_queue();
    
    for(int i = 0; i<w.return_number_task(); i++)
    {
        task temp_task = tq.top();
        tq.pop();
        
        node temp_node = nq.top();
        nq.pop();
        
        pair<task,node> p;
        p.first = temp_task;
        p.second = temp_node;
        
        schedule.push_back(p);
    }
}

void print_schedule(vector<pair<task,node>>& schedule)
{
    cout<< "printing schedule using l2ff algorithm:" <<endl;
    for(int i=0;i<schedule.size();i++)
    {
        cout << "Task id: " << schedule[i].first.return_id() << " with execution time:" << schedule[i].first.return_required_execTime() << " mapped to " << schedule[i].second.return_typeNode() << " with id " << schedule[i].second.return_id() << endl;
    }
}

void print_schedule_random(vector<pair<task,node>>& schedule_random)
{
    cout<< "printing schedule by random assignment:" <<endl;
    for(int i=0;i<schedule_random.size();i++)
    {
        cout << "Task id: " << schedule_random[i].first.return_id() << " with execution time:" << schedule_random[i].first.return_required_execTime() << " mapped to " << schedule_random[i].second.return_typeNode() << " with id " << schedule_random[i].second.return_id() << endl;
    }
}

double total_time_execute_random(vector<pair<task,node>> &schedule_random)
{
    double ttx_random = 0;
    for(int i=0;i<schedule_random.size();i++)
    {
        double task_exec_time = schedule_random[i].first.return_required_execTime();
        double node_comp_power = schedule_random[i].second.return_proc_power();
        
        ttx_random = ttx_random + (task_exec_time / node_comp_power);
    }
    return ttx_random;
}


double total_time_execute(vector<pair<task,node>> &schedule)
{
    double ttx_L2FF = 0;
    for(int i=0;i<schedule.size();i++)
    {
        double task_exec_time = schedule[i].first.return_required_execTime();
        double node_comp_power = schedule[i].second.return_proc_power();
        ttx_L2FF = ttx_L2FF + (task_exec_time / node_comp_power);
    }
    return ttx_L2FF;
}

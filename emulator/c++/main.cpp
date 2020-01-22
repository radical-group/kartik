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

void compute_schedule(workload &w, Resource &r, vector<pair<task,node>>& schedule);
void print_schedule(vector<pair<task,node>>& schedule);

int main(int argc, const char * argv[]) {
    
    int number_pi;
    int number_fog;
    int number_hpc;
    
    int number_task;
    
    cout << "Enter the number of pi resources: ";
    cin >> number_pi;
    
    cout << "Enter the number of fog resources: ";
    cin >> number_fog;
    
    cout << "Enter the number of hpc resources: ";
    cin >> number_hpc;
    
    cout << "Number of task in the wowrkload: ";
    cin >> number_task;
    
    workload w(number_task);
    Resource r(number_pi,number_fog,number_hpc);
    vector<pair<task,node>> schedule;
    
    compute_schedule(w,r,schedule);
    print_schedule(schedule);
    
    
    return 0;
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
    for(int i=0;i<schedule.size();i++)
    {
        cout << "Task id: " << schedule[i].first.return_id() << " with execution time:" << schedule[i].first.return_required_execTime() << " mapped to " << schedule[i].second.return_typeNode() << " with id " << schedule[i].second.return_id() << endl;
    }
}

//
//  workload.h
//  EmulatorV1
//
//  Created by Kartik Rattan on 11/15/19.
//  Copyright © 2019 Kartik Rattan. All rights reserved.
//

#ifndef workload_h
#define workload_h

#include "task.h"
#include <queue>
#include "time.h"

using namespace std;

class workload: public task
{
public:
    
    workload(int n)
    {
        
        numTasks = n;
        for(int i=0; i<n;i++)
        {
            int id = i+1;
            int mem = 1 + rand()%11; // in Gbs
            int exec = 1 + rand()%11; //in hours
            
            task t(id,mem,exec);
            task_list.push_back(t);
            taskQueue.push(t);
        }
    }
    int return_number_task()
    {
        return numTasks;
    }
    
    priority_queue<task> return_task_queue()
    {
        return taskQueue;
    }
    
    void print_workload()
    {
        cout << "Printing out workload........" << endl;
        for(int i=0; i<task_list.size(); i++)
        {
            cout << "ID:" << task_list[i].return_id() << " Exec time:" << task_list[i].return_execution_time() << " Memory:" << task_list[i].return_required_memory() << endl;
        }
    }
    
private:
    int idWL;
    int numTasks;
    priority_queue<task> taskQueue;
    vector<task> task_list;
};

#endif /* workload_h */

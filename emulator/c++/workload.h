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
#include <random>
#include <chrono>



using namespace std;

class workload: public task
{
public:
    
    workload(int n)
    {
        
        numTasks = n;
        
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        static std::default_random_engine generator (seed);
        std::uniform_real_distribution<double> distribution(1.0,10.0);
        for(int i=0; i<n;i++)
        {
            int id = i+1;
            
            
            double mem = distribution(generator);
            double exec = distribution(generator);

            
            task t(id,mem,exec);
            task_list.push(t);
            taskQueue.push(t);
        }
    }
    int return_number_task()
    {
        return numTasks;
    }
    queue<task> return_task_queue_random()
    {
        return task_list;
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
            queue<task> t_temp = return_task_queue_random();
            task t = t_temp.front();
            t_temp.pop();
            cout << "ID:" << t.return_id() << " Exec time:" << t.return_execution_time() << " Memory:" << t.return_required_memory() << endl;
        }
    }
    
private:
    int idWL;
    int numTasks;
    priority_queue<task> taskQueue;
    queue<task> task_list;
};

#endif /* workload_h */

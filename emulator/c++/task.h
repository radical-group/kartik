//
//  task.h
//  EmulatorV1
//
//  Created by Kartik Rattan on 11/15/19.
//  Copyright © 2019 Kartik Rattan. All rights reserved.
//

#ifndef task_h
#define task_h

#include <map>

class task
{
public:
    
    task()
    {
        idTask = 0;
        reqExecTime = 0.0;
        reqMemory = 0.0;
        
        startTime = 0.0;
        endTime = 0.0;
        usedMemory = 0.0;
    }
    task(int id_task, double mem, double exec)
    {
        set_id(id_task);
        set_reqExecTime(exec);
        set_reqMemory(mem);
        
        startTime = 0.0;
        endTime = 0.0;
        usedMemory = 0.0;
    }
    void set_id(int id_task)
    {
        idTask = id_task;
    }
    int return_id()
    {
        return idTask;
    }
    double return_required_execTime()
    {
        return reqExecTime;
    }
    double return_required_memory()
    {
        return reqMemory;
    }
    void set_reqExecTime(double val)
    {
        reqExecTime = val;
    }
    void set_reqMemory(double val)
    {
        reqMemory = val;
    }
    double return_execution_time()
    {
        return endTime - startTime;
    }
    double return_used_memory()
    {
        return usedMemory;
    }
    
    //Overload the >  & < operators ofr priority_queue

    bool operator <(const task& a) const               //define operator < for queue
    {
        return ((this->reqExecTime) > a.reqExecTime);
    }
    bool operator >(const task& a) const               //define operator > for queue
    {
        return ((this->reqExecTime) > a.reqExecTime);
    }
    struct CompareTasks {                                      //define compartor for STLs
        bool operator()(task const& t1, task const& t2)
        {
            return t1.reqExecTime < t2.reqExecTime;
        }
    };
    
private:
    int idTask;
    double startTime;
    double endTime;
    double reqExecTime;             //required execution time
    double reqMemory;
    double usedMemory;
};
#endif /* task_h */

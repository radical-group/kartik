# Emulator design: Rattan, Kartik
# class definition of a workload

from task import task
import random


class workload:

    numTasks = 0
    task_list = []                     #List of tasks sorted in decreasing order of number of instructions
    task_list_random = []              #List of tasks randomly sorted

    def __init__(self, num_tasks):


        self.set_numTasks(num_tasks)

        for i in range(0,num_tasks):

            temp_id = i + 1                    #assign an ID to the task
            mem = random.uniform(1,10)         #assign a sample point for memory required from a uniform distribution between 1 - 10
            exec = random.uniform(1,10)        #assign a sample point for execution time (number of instructions) from a uniform distribution between 1 - 10

            t = task(temp_id,mem,exec)

            self.task_list.append(t)           #add the task to the sorted task list
            self.task_list_random.append(t)    #add the task to the randomly sorted task list

        self.task_list.sort(key=lambda x: x.reqExecTime, reverse=True)  #sort the task list in decreasing order

    #print the workload
    def print_workload(self):
        print( 'Printing out workload........')
        for task in self.task_list_random:
            print('ID:' + str(task.idTask) + ' Exec time:' + str(task.reqExecTime) + ' Memory:' + str(task.reqMemory))
    
    #get the sorted task queue
    def return_task_queue(self):
        return self.task_list
    
    #get the sorted task queue
    def return_task_queue_random(self):
        return self.task_list_random

    #set the number of tasks
    def set_numTasks(self,num_tasks):
        self.numTasks = num_tasks
        
    #return the number of tasks
    def return_number_task(self):
        return self.numTasks





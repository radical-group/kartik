from task import task
import random


class workload:

    numTasks = 0
    task_list = []
    task_list_random = []

    def __init__(self, num_tasks):


        self.set_numTasks(num_tasks)

        for i in range(0,num_tasks):

            temp_id = i
            mem = random.randint(1,10)
            exec = random.randint(1,10)

            t = task(temp_id,mem,exec)

            self.task_list.append(t)
            self.task_list_random.append(t)

        self.task_list.sort(key=lambda x: x.reqExecTime, reverse=True)

    def print_workload(self):
        print( 'Printing out workload........')
        for task in self.task_list_random:
            print('ID:' + str(task.idTask) + ' Exec time:' + str(task.reqExecTime) + ' Memory:' + str(task.reqMemory))

    def return_task_queue(self):
        return self.task_list


    def set_numTasks(self,num_tasks):
        self.numTasks = num_tasks






#Emulator design: Rattan, Kartik
#definition of a task


class task:

    idTask = 0                  #ID of the task
    startTime = 0.0             #The starting time of the task execution
    endTime = 0.0               #Ending time of the task execution
    reqExecTime = 0.0           #Number of instructions
    reqMemory = 0.0             #required memory time set by the user
    usedMemory = 0.0            #Actual memory used by the task

    def __init__(self, id_task, mem, exec_time):

        self.set_id(id_task)
        self.set_req_mem(mem)
        self.set_req_execTime(exec_time)

    #get the id of the task
    def return_id(self):
        return self.idTask
        
    #get the req execution time of the task
    def return_req_execTime(self):
        return self.reqExecTime
        
    #get the req memory of the task
    def return_req_mem(self):
        return self.reqMemory
    
    #set the id of the task
    def set_id(self,id):
        self.idTask = id
        
    #set the rq memory of the task
    def set_req_mem(self,mem):
        self.reqMemory = mem
    
    #set the req exec time of task
    def set_req_execTime(self,exec):
        self.reqExecTime=exec

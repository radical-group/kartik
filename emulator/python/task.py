


class task:

    idTask = 0
    startTime = 0.0
    endTime = 0.0
    reqExecTime = 0.0             #required execution time
    reqMemory = 0.0
    usedMemory = 0.0

    def __init__(self, id_task, mem, exec_time):

        self.set_id(id_task)
        self.return_req_mem(mem)
        self.reqExecTime(exec_time)

    def return_id(self):
        return self.idTask

    def return_req_execTime(self):
        return self.reqExecTime

    def return_req_mem(self):
        return self.reqMemory

    def set_id(self,id):
        self.idTask = id

from resource import Resource
from workload import workload

#L2FF assignment
def compute_schedule(w, r, numTasks, schedule):

    task_list = w.return_task_queue()
    node_list = r.return_resource_queue()

    for i in range(0,numTasks):
        current_task = task_list[i]
        current_node = node_list[i]

        pair = []
        pair.append(current_task)
        pair.append(current_node)
        schedule.append(pair)

#random Assignment
def compute_schedule_random(w, r, numTasks, schedule_random):

    task_list = w.return_task_queue_random()
    node_list = r.return_resource_queue_random()

    for i in range(0,numTasks):
        current_task = task_list[i]
        current_node = node_list[i]

        pair = []
        pair.append(current_task)
        pair.append(current_node)
        schedule_random.append(pair)

def total_time_execute_random(schedule_random):

    ttx_random = 0.0
    for i in schedule_random:

        task_exec_time = i[0].return_req_execTime()
        node_comp_power = i[1].return_proc_power()

        ttx_random = ttx_random + (task_exec_time / node_comp_power)

    return ttx_random

def total_time_execute_L2FF(schedule):

    ttx_L2FF = 0.0
    for i in schedule:

        task_exec_time = i[0].return_req_execTime()
        node_comp_power = i[1].return_proc_power()

        ttx_L2FF = ttx_L2FF + (task_exec_time / node_comp_power)

    return ttx_L2FF

def print_schedule(schedule):
    for i in schedule:
        print("Task id: " + str(i[0].return_id()) + " with execution time:" + str(i[0].return_req_execTime()) + " mapped to " +str(i[1].return_typeNode()) + " with id " + str(i[1].return_id()))





number_pi = input("Enter the number of pi resources: ")
number_fog = input("Enter the number of fog resources: ")
number_hpc = input("Enter the number of hpc resources: ")

number_task = input("Number of task in the workload: ")

w = workload(int(number_task))
r = Resource(int(number_pi),int(number_fog),int(number_hpc))

schedule = []
schedule_random = []

compute_schedule(w,r,int(number_task),schedule)
compute_schedule_random(w,r,int(number_task),schedule_random)

print("*****Printing task-Node pair through L2FF assignment*****")
print_schedule(schedule)
print('The execution time for workload through L2FF assignment:' + str(total_time_execute_L2FF(schedule)))
print("*****Printing task-Node pair through random assignment*****")
print_schedule(schedule_random)
print('The execution time for workload through random assignment:' + str(total_time_execute_random(schedule_random)))


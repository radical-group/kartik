#Emulator design: Rattan, Kartik
#definition of a resource


from node import node
import random

class Resource:

    num_pi = 0              #Number of pi devices
    num_fog = 0             #Number of fog devices
    num_hpc = 0             #Number of cloud devices
    numNodes = num_pi + num_fog + num_hpc   #total number of devices in the resource

    node_list = []         #list of cores randomly ordered wrt execution time
    node_list_random = []  #list of cores ordered in decreasing order of execution time

    def __init__(self, n1, n2, n3):
        self.num_pi = n1
        self.num_fog = n2
        self.num_hpc = n3

        self.numNodes = self.num_pi + self.num_fog + self.num_hpc

        #node( int id, string type, int cores, double power, double ram, double storage, int status)
        #for pi
        for i in range(0,n1):

           id_node = i+1
           type = "pi"
           cores = 1
           power = random.uniform(1,3)              #i am taking tasks in the range 1-10 of memory and power
           ram = 4
           storage = 1
           status = 0


           n = node(id_node,type,cores,power,ram,storage,status)
           self.node_list.append(n)
           self.node_list_random.append(n)


       #for fog
        for i in range(0,n2):
           id_node = n2+i+1
           type = "fog"
           cores = 2
           power = random.uniform(4,6)
           ram = 16
           storage = 4
           status = 0

           n = node(id_node,type,cores,power,ram,storage,status)
           self.node_list.append(n)
           self.node_list_random.append(n)

       # for hpc
        for i in range(0,n3):
           id_node = n3 + n2 + i + 1
           type = "cloud"
           cores = 48
           power = random.uniform(7,10)
           ram = 96
           storage = 10
           status = 0

           n = node(id_node,type,cores,power,ram,storage,status)
           self.node_list.append(n)
           self.node_list_random.append(n)

        self.node_list.sort(key=lambda x: x.compPower, reverse=True)



    def return_resource_queue(self):
        return self.node_list

    def return_resource_queue_random(self):
        return self.node_list_random

    def print_resource(self):
        print("Printing out resources........")
        for node in self.node_list_random:
            print("ID:" + str(node.return_id()) + " Processing time:" + str(node.return_proc_power()) + " RAM:"+ str(node.return_RAM()))



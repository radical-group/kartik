#Emulator design: Rattan, Kartik
#class definition for a node


class node:

    idNode = 0              # The ID of the node
    typeNode = "NULL"       # type of node
    numberCores = 0         # number of cores
    compPower = 0.0         # computational power of node
    RAM = 0.0               # RAM associated with the core
    storageMemory = 0.0     # Storage memory
    status = 0              # 0 means idle, 1 means currently executing a task

    def __init__(self,id_Node,type_machine,numCores,execPower,RAM_machine,storageCapacity,status_machine):

        self.idNode = id_Node
        self.typeNode = type_machine
        self.numberCores = numCores
        self.compPower = execPower
        self.RAM = RAM_machine
        self.storageMemory = storageCapacity
        self.status = 0
        
    # get the ID of the node
    def return_id(self):
        return self.idNode
        
    # get the processing power of the node set by the user ( number of instructions per second )
    def return_proc_power(self):
        return self.compPower
        
    # get the RAM of the core
    def return_RAM(self):
        return self.RAM

    # get the type of node: Edge, fog & Cloud
    def return_typeNode(self):
        return self.typeNode


    

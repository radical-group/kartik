




class node:

    idNode = 0
    typeNode = "NULL"
    numberCores = 0
    compPower = 0.0
    RAM = 0.0
    storageMemory = 0.0
    status = 0   #0 means idle, 1 means in use

    def __init__(self,id_Node,type_machine,numCores,execPower,RAM_machine,storageCapacity,status_machine):

        self.idNode = id_Node
        self.typeNode = type_machine
        self.numberCores = numCores
        self.compPower = execPower
        self.RAM = RAM_machine
        self.storageMemory = storageCapacity
        self.status = 0         #0 means idle, 1 means in use


    def return_id(self):
        return self.idNode

    def return_proc_power(self):
        return self.compPower

    def return_RAM(self):
        return self.RAM

    def return_typeNode(self):
        return self.typeNode


    

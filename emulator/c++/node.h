
//
//  node.h
//  EmulatorV1
//
//  Created by Kartik Rattan on 11/15/19.
//  Copyright © 2019 Kartik Rattan. All rights reserved.
//

#ifndef node_h
#define node_h

using namespace std;


class node
{
public:
    node()
    {
        idNode = 0;
        typeNode = "NULL";
        numberCores = 0;
        compPower = 0.0;
        RAM = 0.0;
        storageMemory = 0.0;
        status = 0; // 0 means idle, 1 means in use
    }
    node( int id_node, string type, int cores, double power, double ram, double storage, int status)
    {
        idNode = id_node;
        typeNode = type;
        numberCores = cores;
        compPower = power;
        RAM = ram;
        storageMemory = storage;
        status = 0; // 0 means idle, 1 means in use
    }
    
    int return_id()
    {
        return idNode;
    }
    
    double return_proc_power()
    {
        return compPower;
    }
    double return_RAM()
    {
        return RAM;
    }
    string return_typeNode()
    {
        return typeNode;
    }
    bool operator <(const node& a) const               //define operator < for queue
    {
       return ((this->compPower) > a.compPower);
    }
    bool operator >(const node& a) const               //define operator > for queue
    {
       return ((this->compPower) > a.compPower);
    }
    struct CompareNodes {                                      //define compartor for STLs
       bool operator()(node const& n1, node const& n2)
       {
           return n1.compPower < n2.compPower;
       }
    };
    
private:
    int idNode;
    string typeNode;        // type of node - cloud,fog,edge
    int numberCores;
    double compPower;
    double RAM;
    double storageMemory;
    int status;             // 0 - in use, 1 - available
};


#endif /* node_h */

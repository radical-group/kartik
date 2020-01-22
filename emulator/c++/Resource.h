//
//  Resource.h
//  EmulatorV1
//
//  Created by Kartik Rattan on 11/15/19.
//  Copyright © 2019 Kartik Rattan. All rights reserved.
//

#ifndef Resource_h
#define Resource_h
#include<queue>
#include "node.h"

using namespace std;

class Resource: public node
{
public:
    Resource()
    {
        num_pi = 0;
        num_fog = 0;
        num_hpc = 0;
        
        numNodes = num_pi + num_fog + num_hpc;
    }
    
    Resource(int n1, int n2, int n3)
       {
           
           num_pi = n1;
           num_fog = n2;
           num_hpc = n3;
           
           numNodes = num_pi + num_fog + num_hpc;
           
           //node( int id, string type, int cores, double power, double ram, double storage, int status)
           // for pi
           for(int i=0; i<n1;i++)
           {
               int id_node = i+1;
               string type = "pi";
               int cores = 1;
               double power = 1.0;              // i am taking tasks in the range 1-10 of memory and power
               double ram = 4;
               double storage = 1;
               int status = 0;
               
               
               node n(id_node,type,cores,power,ram,storage,status);
               nodeQueue.push(n);
               node_list.push_back(n);
           }
           // for fog
           for(int i=0; i<n2;i++)
           {
               int id_node = n2+i+1;
               string type = "fog";
               int cores = 2;
               double power = 5.0;
               double ram = 16;
               double storage = 4;
               int status = 0;
               
               node n(id_node,type,cores,power,ram,storage,status);
               nodeQueue.push(n);
               node_list.push_back(n);
           }
           // for hpc
           for(int i=0; i<n3;i++)
           {
               int id_node = n3 + n2 + i + 1;
               string type = "cloud";
               int cores = 48;
               double power = 10.0;
               double ram = 96;
               double storage = 10;
               int status = 0;
               
               node n(id_node,type,cores,power,ram,storage,status);
               nodeQueue.push(n);
               node_list.push_back(n);
           }
           
       }
    priority_queue<node> return_resource_queue()
    {
        return nodeQueue;
    }
    void print_resource()
    {
        cout << "Printing out resources........" << endl;
        for(int i=0; i<node_list.size(); i++)
        {
            cout << "ID:" << node_list[i].return_id() << " Processing time:" << node_list[i].return_proc_power() << " RAM:" << node_list[i].return_RAM() << endl;
        }
    }
private:
    
    int numNodes;
    int num_pi;
    int num_fog;
    int num_hpc;
    
    priority_queue<node> nodeQueue;
    vector<node> node_list;
    
};

#endif /* Resource_h */

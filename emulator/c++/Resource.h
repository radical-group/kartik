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

#include <random>
#include <chrono>

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
           unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
           static std::default_random_engine generator_pi(seed);
           std::uniform_real_distribution<double> distribution_pi(0.0,1.0);
           
        
           for(int i=0; i<n1;i++)
           {
               int id_node = i+1;
               string type = "pi";
               int cores = 1;
               double power = distribution_pi(generator_pi);              // i am taking tasks in the range 1-10 of memory and power
               double ram = 4;
               double storage = 1;
               int status = 0;
               
               
               node n(id_node,type,cores,power,ram,storage,status);
               nodeQueue.push(n);
               node_list.push(n);
           }
           // for fog
           seed = std::chrono::system_clock::now().time_since_epoch().count();
           static std::default_random_engine generator_fog(seed);
           std::uniform_real_distribution<double> distribution_fog(2.0,5.0);
           for(int i=0; i<n2;i++)
           {
               int id_node = n2+i+1;
               string type = "fog";
               int cores = 2;
               double power = distribution_fog(generator_fog);
               double ram = 16;
               double storage = 4;
               int status = 0;
               
               node n(id_node,type,cores,power,ram,storage,status);
               nodeQueue.push(n);
               node_list.push(n);
           }
           // for hpc
           seed = std::chrono::system_clock::now().time_since_epoch().count();
           static std::default_random_engine generator_hpc(seed);
           std::uniform_real_distribution<double> distribution_hpc(7.0,10.0);
           for(int i=0; i<n3;i++)
           {
               int id_node = n3 + n2 + i + 1;
               string type = "cloud";
               int cores = 48;
               double power = distribution_hpc(generator_hpc);;
               double ram = 96;
               double storage = 10;
               int status = 0;
               
               node n(id_node,type,cores,power,ram,storage,status);
               nodeQueue.push(n);
               node_list.push(n);
           }
           
       }
    priority_queue<node> return_resource_queue()
    {
        return nodeQueue;
    }
    queue<node> return_node_list_random()
    {
        return node_list;
    }
    void print_resource()
    {
        cout << "Printing out resources........" << endl;
        for(int i=0; i<node_list.size(); i++)
        {
            queue<node> n_temp = return_node_list_random();
            node n = n_temp.front();
            n_temp.pop();
            cout << "ID:" << n.return_id() << " Processing time:" << n.return_proc_power() << " RAM:" << n.return_RAM() << endl;
        }
    }
private:
    
    int numNodes;
    int num_pi;
    int num_fog;
    int num_hpc;
    
    priority_queue<node> nodeQueue;
    queue<node> node_list;
    
};

#endif /* Resource_h */

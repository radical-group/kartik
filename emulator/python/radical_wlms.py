from resource import Resource
from workload import workload


number_pi = input("Enter the number of pi resources: ")
number_fog = input("Enter the number of fog resources: ")
number_hpc = input("Enter the number of hpc resources: ")

number_task = input("Number of task in the workload: ")

w = workload(number_task)
r = Resource(number_pi,number_fog,number_hpc)


def compute_schedule(w, r, vector<pair<task,node>>& schedule):

    task_list = w.return_task_queue();
    node_list = r.return_resource_queue();

    for i = 0;w.return_number_task(); i++)
    {
        task temp_task = tq.top();
        tq.pop();

        node temp_node = nq.top();
        nq.pop();

        pair<task,node> p;
        p.first = temp_task;
        p.second = temp_node;

        schedule.push_back(p);
    }
}

def print_schedule(vector<pair<task,node>>& schedule):
    for(int i=0;i<schedule.size();i++)
    {
        cout << "Task id: " << schedule[i].first.return_id() << " with execution time:" << schedule[i].first.return_required_execTime() << " mapped to " << schedule[i].second.return_typeNode() << " with id " << schedule[i].second.return_id() << endl;
    }
}

// SUSHANT SINHA
// 1901CS62
// Non preemptive priority Scheduling Algorithm
#include <bits/stdc++.h>

using namespace std;

// Class for process
class Process{
public:
    int pid;
    double arr_time;
    double burst_time;
    int priority;

public:
    Process(int _pid, double _arr_time, double _burst_time, int _priority){
        pid = _pid;
        arr_time = _arr_time;
        burst_time = _burst_time;
        priority = _priority;
    }

    ~Process(){

    }
};

// Comparator class for sorting input according to process arrival time, priority and pid
class comparator {
public:
    bool operator()(const Process &a, const Process &b){
        if(a.arr_time == b.arr_time){
            if(a.priority == b.priority)
                return (a.pid < b.pid);
            else
                return (a.priority < b.priority);
        }
        return (a.arr_time < b.arr_time);
    }
};

// Comparator class to have highest priority(lowest priority number) on front of queue
class q_comparator {
public:
    bool operator()(const Process &a, const Process &b){
        if(a.priority == b.priority)
            return (a.pid > b.pid);
        return (a.priority > b.priority);
    }
};

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    vector<Process> v;  // Vector to store all the processes
    priority_queue<Process,vector<Process>, q_comparator> q;    // Queue of processes
    cout<<"Enter arrival time, burst time and priority: ";
    
    for(int i=0;i<n;++i){   // Taking input
        int priority;
        double arr_time, burst_time;
        cin>>arr_time>>burst_time>>priority;
        Process p(i+1,arr_time,burst_time,priority);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), comparator()); // Sort input
    q.push(v[0]);   // Push single element into queue
    int idx = 1;    // Keep track of index

    double cur_time = 0.0;  // Variables
    double wt=0.0,tat=0.0;
    vector<int> comp;   // Vector to store the order fo completion
    while(!q.empty()){  // Processing queue
        Process cur = q.top();  // Current process
        q.pop();

        if(cur_time < cur.arr_time)
            cur_time = cur.arr_time;
        // Updating values
        wt += cur_time - cur.arr_time;
        cur_time += cur.burst_time;
        tat += cur_time - cur.arr_time;
        comp.push_back(cur.pid);    // Process finished
        
        while(idx<n && v[idx].arr_time <= cur_time){
            // Push additional processes into queues that arrived in the meantime
            q.push(v[idx]);
            idx++;
        }
        if(q.empty() && idx<n){ // In case none was found in the meantime
            q.push(v[idx]);
            idx++;
        }
    }

    wt /= (double)n;    // Calculate averages
    tat /= (double)n;

    cout<<fixed<<setprecision(2)<<wt<<" "<<tat<<endl;   // Output
    for(int i=0;i<n;++i){
        cout<<"P"<<comp[i]<<" ";
    }
    cout<<endl;
    return 0;
}
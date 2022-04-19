// SUSHANT SINHA
// 1901CS62
// RR Scheduling Algorithm
#include <bits/stdc++.h>

using namespace std;

// Class for a process
class Process{
public:
    int pid;
    double arr_time;
    double burst_time;
    double last_exec;

public:
    Process(int _pid, double _arr_time, double _burst_time ){
        pid = _pid;
        arr_time = _arr_time;
        burst_time = _burst_time;
        last_exec = _arr_time;
    }

    ~Process(){

    }
};

// Comparator class for sorting processes in order of arrival time and pid
class comparator {
public:
    bool operator()(const Process &a, const Process &b){
        if(a.arr_time == b.arr_time)
            return (a.pid < b.pid);
        return (a.arr_time < b.arr_time);
    }
};

int main(){
    int n;
    double quanta;
    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<"Enter quanta: ";
    cin>>quanta;

    vector<Process> v;  // Vector to store all the processes
    queue<Process> q;   // queue of processes
    cout<<"Enter arrival time and burst time: ";
    
    for(int i=0;i<n;++i){   // Taking input
        double arr_time, burst_time;
        cin>>arr_time>>burst_time;
        Process p(i+1,arr_time,burst_time);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), comparator()); // Sort input
    q.push(v[0]);   // Push single element
    int idx = 1;    // Index of array

    double cur_time = 0.0;  // Variables
    double wt=0.0,tat=0.0;
    vector<int> comp;   // Vector to store the order of completion

    while(!q.empty()){  // Processing queue
        Process cur = q.front();    // Current process
        q.pop();
        if(cur_time < cur.arr_time)
            cur_time = cur.arr_time;
        // Updating values
        // We store the last time the process was executed and run the given process for a finite time
        wt += cur_time - cur.last_exec;
        double time_spent = min(quanta, cur.burst_time);
        cur_time += time_spent;
        cur.burst_time -= time_spent;   // Update required time left
        cur.last_exec = cur_time;
        while(idx<n && v[idx].arr_time <= cur_time){
            // Push additional processes into queues that arrived in the meantime
            q.push(v[idx]);
            idx++;
        }
        if(cur.burst_time < 0.0001){    // If process is finished, calculate tat
            tat += cur_time - cur.arr_time;
            comp.push_back(cur.pid);
        }
        else    // if process is not finished, push back to the queue
            q.push(cur);

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
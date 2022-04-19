// SUSHANT SINHA
// 1901CS62
// FCFS Scheduling Algorithm
#include <bits/stdc++.h>

using namespace std;

// Class for a process
class Process{
public:
    int pid;
    double arr_time;
    double burst_time;

public:
    Process(int _pid, double _arr_time, double _burst_time ){
        pid = _pid;
        arr_time = _arr_time;
        burst_time = _burst_time;
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
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<Process> v;  // Vector containing all processes
    cout<<"Enter arrival time and burst time: ";

    for(int i=0;i<n;++i){   // Taking input
        double arr_time, burst_time;
        cin>>arr_time>>burst_time;
        Process p(i+1,arr_time,burst_time);
        v.push_back(p);
    }

    sort(v.begin(),v.end(),comparator());   // Sort processes
    double cur_time = 0.0;  // Variables for current time, waiting time and turn around time
    double wt=0.0,tat=0.0;
    vector<int> comp;   // Vector to store the order of completion
    for(int i=0;i<n;++i){   // processing all processes
        Process cur = v[i]; // Current process
        
        if(cur_time < cur.arr_time)
            cur_time = cur.arr_time;
        // Updating values
        wt += cur_time - cur.arr_time;
        cur_time += cur.burst_time;
        tat += cur_time - cur.arr_time;
        comp.push_back(cur.pid);
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
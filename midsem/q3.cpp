/*
SUSHANT SINHA
1901CS62
Program to simulate Multi level queue scheduling with 2 queues
System process(1) has higher priority than user process(2)
*/
#include <bits/stdc++.h>

using namespace std;

// Class for a process
class Process{
public:
    int pid;    // Process pid
    double arr_time;    // arrival time of process
    double burst_time;  // Burst time left of process
    double last_exec;   // Last time process was executed
    int priority;   // Process priority

public:
    Process(){}

    Process(int _pid, double _arr_time, double _burst_time, int _priority ){
        pid = _pid;
        arr_time = _arr_time;
        burst_time = _burst_time;
        last_exec = _arr_time;
        priority = _priority;
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
    int n,nq;
    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<"Enter number of queues(2 for this question): ";
    cin>>nq;
    if(nq!=2){
        cout<<"Total queues for this question is specified to be 2.\n";
        return 0;
    }

    // Vector to store all the processes
    vector<Process> vp1;  // with priority 1
    vector<Process> vp2;  // with priority 2
    // Queues of processes
    queue<Process> qp1;   // with priority 1
    queue<Process> qp2;   // with priority 2
    cout<<"Enter arrival time, burst time and priorty: ";
    
    for(int i=0;i<n;++i){   // Taking input
        double arr_time, burst_time;
        int priority;
        cin>>arr_time>>burst_time>>priority;
        Process p(i+1,arr_time,burst_time,priority);    // Create process
        if(priority==1) // Push in appropriate vector
            vp1.push_back(p);
        else
            vp2.push_back(p);
    }
    
    sort(vp1.begin(), vp1.end(), comparator()); // Sort vectors
    sort(vp2.begin(), vp2.end(), comparator());
    int np1 = vp1.size();   // Total process with priority 1
    int np2 = vp2.size();   // Total process with priority 2
    int idxp1 = 0, idxp2 = 0;   // Index for both vectors

    // Finding the process which arrived first
    double tempt = 2000000000.0;    // minimum arrival time for a process from both priorities
    if(np1 && vp1[0].arr_time <= tempt) // Update tempt if new minimum
        tempt = vp1[0].arr_time;
    if(np2 && vp2[0].arr_time <= tempt)
        tempt = vp2[0].arr_time;        // Update tempt if new minimum
    if(np1 && vp1[0].arr_time == tempt){
        qp1.push(vp1[0]);   // Push into queue1 if this process arrived first
        idxp1++;
    }
    if(np2 && vp2[0].arr_time == tempt){
        qp2.push(vp2[0]);   // Push into queue2 if this process arrived first
        idxp2++;
    }

    double cur_time = 0.0;  // Current running time of simulation
    double wt=0.0,tat=0.0;  // waiting time and turn-around time
    vector<int> comp;   // Vector to store the order of completion
    
    while(!qp1.empty() || !qp2.empty()){  // Processing both queues
        Process cur;
        if(!qp1.empty()){   // If process available in queue 1, process first
            cur = qp1.front();
            qp1.pop();
        }
        else{   // Else take from queue 2
            cur = qp2.front();
            qp2.pop();
        }

        if(cur_time < cur.arr_time) // Update cur_time if needed
            cur_time = cur.arr_time;

        // Updating values
        // We store the last time the process was executed and run the given process for a finite time
        wt += cur_time - cur.last_exec; // Update waiting time
        double time_spent;
        if(cur.priority==1) // Find time spent on process
            time_spent = min(4.0, cur.burst_time);
        else
            time_spent = min(3.0, cur.burst_time);

        if(idxp1 < np1 && cur.priority==2)  // If preemption can occur
            time_spent = min(time_spent,vp1[idxp1].arr_time-cur_time);

        cur_time += time_spent; // Update current time
        cur.burst_time -= time_spent;   // Update required burst time left
        cur.last_exec = cur_time;   // Update last execution time

        while(idxp1<np1 && vp1[idxp1].arr_time <= cur_time){
            // Push additional processes into queue 1 that arrived in the meantime
            qp1.push(vp1[idxp1]);
            idxp1++;
        }
        while(idxp2<np2 && vp2[idxp2].arr_time <= cur_time){
            // Push additional processes into queue 2 that arrived in the meantime
            qp2.push(vp2[idxp2]);
            idxp2++;
        }

        if(cur.burst_time < 0.00001){    // If process is finished, calculate tat
            tat += cur_time - cur.arr_time;
            comp.push_back(cur.pid);
        }
        else {  // if process is not finished, push back to the appropriate queue
            if(cur.priority==1)
                qp1.push(cur);
            else
                qp2.push(cur);
        } 

        if(qp1.empty() && qp2.empty()){ 
            // If both queues are empty(no process arrived in meantime and no process left in queues)
            // Find the process which will arrive next using same logic
            // As was used to find the process which would arrive first
            double arrt = 2000000000.0;
            if(idxp1 < np1 && vp1[idxp1].arr_time <= arrt)
                arrt = vp1[idxp1].arr_time;
            if(idxp2 < np2 && vp2[idxp2].arr_time <= arrt)
                arrt = vp2[idxp2].arr_time;
            if(idxp1 < np1 && vp1[idxp1].arr_time == arrt){
                qp1.push(vp1[idxp1]);
                idxp1++;
            }
            if(idxp2 < np2 && vp2[idxp2].arr_time == arrt){
                qp2.push(vp2[idxp2]);
                idxp2++;
            }
        }
    }

    wt /= (double)n;    // Calculate averages
    tat /= (double)n;

    cout<<fixed<<setprecision(2)<<"Avg_WT = "<<wt<<" Avg_TAT = "<<tat<<endl;   // Output
    for(int i=0;i<n;++i){
        cout<<"P"<<comp[i]<<" ";
    }
    cout<<endl;
    return 0;
}
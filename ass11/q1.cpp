/*
SUSHANT SINHA
1901CS62
C++ program to run the given input queue with all 4 algorithms 
and make a separate file for graphing points 
*/
// Including necessary libraries
#include <bits/stdc++.h> 
#define INI_CUR 100 // initial disk head position

using namespace std;

int n;  // total disk queue access
vector<int> work_q; // vector for work queue
vector<int> dup_work;

int fcfs(){ // fcfs algorithm
    int counter = 1;
    ofstream newfile("fcfs.txt");
    int thm=0;  // total head movement
    int cur = INI_CUR;  // current had position
    newfile<<cur<<' '<<counter<<'\n';
    counter++;

    for(int i=0;i<n;++i){   // process works in the order they came in
        thm += abs(work_q[i]-cur);
        cur = work_q[i];
        newfile<<cur<<' '<<counter<<'\n';
        counter++;
    }
    newfile.close();
    return thm;
}

int sstf(){ //sstf algorithm
    int counter = 1;
    ofstream newfile("sstf.txt");
    int thm = 0;    // total head movement
    int cur = INI_CUR;  // current head position
    newfile<<cur<<' '<<counter<<'\n';
    counter++;

    dup_work = work_q;
    sort(dup_work.begin(),dup_work.end());  // sort work queue

    auto x = upper_bound(dup_work.begin(),dup_work.end(),cur);  // next work on the right
    int l=-1,r=n;   // nearest work on left and right
    if(x==dup_work.end())
        l=n-1;
    else{
        r = x-dup_work.begin();
        l= r-1;
    }

    while(l>=0 || r<n){ // pick one from either left or right depending on which closest
        if(l<0){
            thm += abs(cur-dup_work[r]);
            cur = dup_work[r++];
        }
        else if(r>=n){
            thm += abs(cur-dup_work[l]);
            cur = dup_work[l--];
        }else{
            int min_work = min(abs(cur-dup_work[l]),abs(cur-dup_work[r]));
            thm += min_work;
            if(min_work==abs(cur-dup_work[l]))
                cur = dup_work[l--];
            else
                cur = dup_work[r++];
        }
        newfile<<cur<<' '<<counter<<'\n';
        counter++;
    }

    return thm;
}

int scan(){ //scan algorithm
    int counter = 1;
    ofstream newfile("scan.txt");
    int thm = 0;    // total head movement
    int cur = INI_CUR;  // initial head position
    int count = 0;  // total disk work processed
    dup_work = work_q;
    newfile<<cur<<' '<<counter<<'\n';
    counter++;

    sort(dup_work.begin(),dup_work.end());  // sort work queue
    auto x = lower_bound(dup_work.begin(),dup_work.end(),cur);  // finding first work to do
    int ini;
    if(x!=dup_work.end())
        ini = x - dup_work.begin();
    else
        ini = n;

    int i = ini;
    bool flag = false;
    while(count<n){
        if(i>=n){   // reverse direction if nothing else is found on right
            thm += abs(cur - 199);
            cur = 199;
            newfile<<cur<<' '<<counter<<'\n';
            counter++;
            i = ini-1;
            flag = true;
        }
        thm += abs(cur-dup_work[i]);
        cur = dup_work[i];
        newfile<<cur<<' '<<counter<<'\n';
        counter++;
        count++;
        if(flag)
            i--;
        else
            i++;
    }

    return thm;
}

int cscan(){
    int counter = 1;
    ofstream newfile("cscan.txt");
    int thm = 0;    // total head movement
    int cur = INI_CUR;  // current head position
    int count = 0;  // total work processed
    dup_work = work_q;
    newfile<<cur<<' '<<counter<<'\n';
    counter++;

    sort(dup_work.begin(),dup_work.end());  // sort work queue
    auto x = lower_bound(dup_work.begin(),dup_work.end(),cur);  // the first work to do from inital position
    int i;
    if(x!=dup_work.end())
        i = x - dup_work.begin();
    else
        i = n;

    while(count<n){
        if(i>=n){   // if end reached, loop back to 0
            thm += abs(cur-199)+199;
            newfile<<199<<' '<<counter<<'\n';
            counter++;
            i = 0;
            cur = 0;
            newfile<<cur<<' '<<counter<<'\n';
            counter++;
        }
        thm += abs(cur-dup_work[i]);
        cur = dup_work[i];
        newfile<<cur<<' '<<counter<<'\n';
        counter++;
        count++;
        i++;
    }

    return thm;
}

int main(){
    // input
    cout<<"Enter number of jobs in work queue: ";
    cin>>n;
    cout<<"Enter the work queue: ";
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        work_q.push_back(x);
    }    
    cout<<"Total head movement and seek time:-\n";
    int x;
    // calling all algorithms
    x = fcfs();
    cout<<"FCFS: "<<x<<"    "<<x*5<<"ms\n";
    x = sstf();
    cout<<"SSTF: "<<x<<"    "<<x*5<<"ms\n";
    x = scan();
    cout<<"SCAN: "<<x<<"    "<<x*5<<"ms\n";
    x = cscan();
    cout<<"C-SCAN: "<<x<<"    "<<x*5<<"ms\n";
    return 0;
}
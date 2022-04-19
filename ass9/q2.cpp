/*
SUSHANT SINHA
1901CS62
Newly designed Page replacement algorithm
*/
#include <bits/stdc++.h>

using namespace std;

int n;  // number of frames
vector<int> pn; // vector containing page numbers
vector<vector<int> > new_output;    // time output of new page replacemetn algorithm

int fifo(){ //fifo page replacement algorithm
    int idx = 0;    // frame index
    unordered_set<int> epn; // collection of all page numbers in frames
    vector<int> frame(n,-1);    // -1 indicating no page number present
    int page_fault = 0; // total number of page faults

    for(int i=0;i<pn.size();++i){   // for each page number
        if(epn.find(pn[i])==epn.end()){ // if page number is not in frame
            page_fault++;   // page fault occured
            if(frame[idx]!=-1)  // adding page numbers, maintaining collection, increasing index
                epn.erase(frame[idx]);
            frame[idx] = pn[i];
            epn.insert(frame[idx]);
            idx = (idx+1)%n;
        }
    }
    return page_fault;
}

int lru(){  //lru page replacement algorithm
    vector<pair<int,int> > frame(n,{-1,INT_MAX});   // {page number, last time frame was used}
    int page_fault = 0; // total page faults
    
    for(int i=0;i<pn.size();++i){
        int idx = 0;    //frame index
        int emptyidx = -1;  // index of empty slot if any
        int leastused = 0;  // index of frame used farthest in past
        for(;idx<n;++idx){  // finding idx, emptyidx, leastused
            if(frame[idx].second < frame[leastused].second)
                leastused = idx;
            if(frame[idx].first==pn[i])
                break;
            if(emptyidx==-1 && frame[idx].first==-1)
                emptyidx = idx;
        }
        if(idx<n)   // if page number found
            frame[idx].second = i+1;    // update last used
        else{
            page_fault++;   // page fault occured
            if(emptyidx!=-1)    // if empty space available
                frame[emptyidx] = {pn[i],i+1};
            else    // page replacement
                frame[leastused] = {pn[i],i+1};
        }
    }
    return page_fault;
}

int optimal(){  // optimal algorithm
    int idx = 0;    //frame index for empty frames
    unordered_set<int> epn; // collection of page numbers in frame
    vector<int> frame(n,-1);    // -1 indicating no page number present
    int page_fault = 0; // total page faults

    for(int i=0;i<pn.size();++i){   // fpr each page number
        if(epn.find(pn[i])==epn.end()){ // if page does not exists in frame
            page_fault++;   // page fault occured
            if(idx<n){  // if empty frame, fill it
                epn.insert(pn[i]);
                frame[idx] = pn[i];
                idx++;
            }else{  // finding page to replace
                int tempidx = 0;
                int duration = 0;

                for(int k=0;k<n;++k){   // finding the page which is used farthest in the future
                    int wait = INT_MAX;
                    for(int l=i+1;l<pn.size();++l){
                        if(frame[k]==pn[l]){
                            wait = l-i;
                            break;
                        }
                    }
                    
                    if(duration<wait){
                        duration = wait;
                        tempidx = k;
                    }
                }

                epn.erase(frame[tempidx]);  // replacing the page found with current one
                epn.insert(pn[i]);
                frame[tempidx] = pn[i];
            }
        }
    }
    return page_fault;
}

int new_algo(){ // new algorithm
    vector<pair<int,int> > frame(n,{-1,0});     // {page number, frquency of usage}
    int page_fault = 0; // total page faults
    vector<int> temp(n,-1);

    new_output.push_back(temp);
    for(int i=0;i<pn.size();++i){   // for each page number
        int idx = 0;    // frame index
        int emptyidx = -1;  // index of empty slot if any
        int leastfreq = 0;  // index of page least used
        for(;idx<n;++idx){  // calculate above index values
            if(frame[idx].second < frame[leastfreq].second)
                leastfreq = idx;
            if(frame[idx].first==pn[i])
                break;
            if(emptyidx==-1 && frame[idx].first==-1)
                emptyidx = idx;
        }
        if(idx<n)   // if page number found
            (frame[idx].second)++;  // increase frequency
        else{
            page_fault++;   // page fault occured
            if(emptyidx!=-1)    // if empty space available, fill it
                frame[emptyidx] = {pn[i],1};
            else    // replace least used page 
                frame[leastfreq] = {pn[i],1};
        }
        
        for(int j=0;j<n;++j)
            temp[j] = frame[j].first;
        
        new_output.push_back(temp);
    }
    return page_fault;
}

void print_frame(vector<vector<int> > &best_algo, int min_fault){   // function to print the time output of algo
    int x = best_algo.size();
    for(int i=1;i<=n;++i)
        cout<<"F"<<i<<" ";
    cout<<'\n';

    for(int i=0;i<x;++i){
        for(int j=0;j<n;++j){
            if(best_algo[i][j]==-1)
                cout<<"X ";
            else
                cout<<best_algo[i][j]<<" ";
        }
        cout<<"at time "<<i<<'\n';
    }
    cout<<"#Page faults: "<<min_fault<<'\n';
    return;
}

int main(){
    cin>>n; // taking input
    cin.ignore();
    string pni;
    getline(cin, pni);
    istringstream temp(pni);
    int curpn;
    while(temp>>curpn)
        pn.push_back(curpn);
    
    // running all algorithms
    int fifo_fault = fifo();
    int lru_fault = lru();
    int optimal_fault = optimal();
    int new_fault = new_algo();

    // output page faults and time output of new algo
    cout<<"#Page Faults for FIFO: "<<fifo_fault<<'\n';
    cout<<"#Page Faults for LRU: "<<lru_fault<<'\n';
    cout<<"#Page Faults for OPTIMAL: "<<optimal_fault<<'\n';
    cout<<"#Page Faults for NEW_ALGO: "<<new_fault<<'\n';
    print_frame(new_output,new_fault);
    return 0;
}
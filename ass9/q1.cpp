/*
SUSHANT SINHA
1901CS62
Selecting the best page replacement algorithm based on number of page faults occuring
*/
#include <bits/stdc++.h>

using namespace std;
int n;  // Number of frames
vector<int> pn; // vector containing page numbers
vector<vector<int> > fifo_output;   // Time output of fifo
vector<vector<int> > lru_output;    // Time output of lru   
vector<vector<int> > optimal_output;    // time output of optimal algo

int fifo(){ //fifo page replacement algorithm
    int idx = 0;    // frame index
    unordered_set<int> epn; // collection of all page numbers in frames
    vector<int> frame(n,-1);    // -1 indicating no page number present
    int page_fault = 0; // total number of page faults

    fifo_output.push_back(frame);
    for(int i=0;i<pn.size();++i){   // for each page number
        if(epn.find(pn[i])==epn.end()){ // if page number is not in frame
            page_fault++;   // page fault occured
            if(frame[idx]!=-1)  // adding page numbers, maintaining collection, increasing index
                epn.erase(frame[idx]);
            frame[idx] = pn[i];
            epn.insert(frame[idx]);
            idx = (idx+1)%n;
        }

        fifo_output.push_back(frame);
    }
    return page_fault;
}

int lru(){  //lru page replacement algorithm
    vector<pair<int,int> > frame(n,{-1,INT_MAX});   // {page number, last time frame was used}
    int page_fault = 0; // total page faults
    vector<int> temp(n,-1);

    lru_output.push_back(temp);
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
        
        for(int j=0;j<n;++j)
            temp[j] = frame[j].first;
        
        lru_output.push_back(temp);
    }
    return page_fault;
}

int optimal(){  // optimal algorithm
    int idx = 0;    //frame index for empty frames
    unordered_set<int> epn; // collection of page numbers in frame
    vector<int> frame(n,-1);    // -1 indicating no page number present
    int page_fault = 0; // total page faults

    optimal_output.push_back(frame);
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

        optimal_output.push_back(frame);
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

    // finding minimum page fault and output that algorithm time output
    int min_fault = min({fifo_fault,lru_fault,optimal_fault});

    if(min_fault==fifo_fault){
        cout<<"Best Page Replacement Algorithm: FIFO\n";
        print_frame(fifo_output,min_fault);
    }else if(min_fault==lru_fault){
        cout<<"Best Page Replacement Algorithm: LRU\n";
        print_frame(lru_output,min_fault);
    }else{
        cout<<"Best Page Replacement Algorithm: OPTIMAL\n";
        print_frame(optimal_output,min_fault);
    }
    return 0;
}
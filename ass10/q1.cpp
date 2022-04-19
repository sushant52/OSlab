/*
SUSAHNT SINHA
1901CS62
MMU Simulation
NOTE: Add an extra newline after input to mark end of input
*/
// Including necessary libraries
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Global variables
ll p,v,f,maxpage,maxframe,page_size,free_frame;
ll page = 0;    // current active page number

unordered_map<ll,ll> kernel,page_table; // kernel frames and page table map
unordered_set<ll> allocated_frame;  // currently allocated frames
vector<string> output;  // output for the program

// function to allocate the given frames
void allocate(ll p_size){
    ll n_frame = ceil(double(p_size)/double(page_size));    // number of frames to be allocated 
    if(free_frame<n_frame){ // check if required frames are available
        output.push_back("Insufficient amount of frames available.");
        return;
    }

    if((page+n_frame)>maxpage){ // check if required frames are available
        output.push_back("Insufficient amount of pages available.");
        return;
    }

    string temp = to_string(p_size) + " bytes has been allocated in frame no ";
    for(ll i=0;i<maxframe && n_frame;++i){  // while all frames are not allocated
        if(kernel.find(i)!=kernel.end()){   // if kernel frame, move on
            i = kernel[i];
        }else if(allocated_frame.find(i)==allocated_frame.end()){   // if frame unused
            allocated_frame.insert(i);  // allocate frame
            page_table[page] = i;   //update page table
            page++; // increment page number
            free_frame--;   // update number of free frames
            n_frame--;  // update number of frames to be allocated
            temp += to_string(i);
            if(n_frame)
                temp += ",";
        }
    }
    output.push_back(temp);
    return;
}

// function to translate logical address to physical address
void translate(ll l_addr){
    ll p = (l_addr>>f); // extract 'p' from logical address
    ll d = l_addr ^ (p<<f); // extract 'd' from logical address
    string temp;
    if(page_table.find(p)==page_table.end()){   // if page number is not in page table
        temp = "invalid page no";   // invalid page number
        output.push_back(temp);
        return;
    }

    ll tr_addr = page_table[p]; // get 'p' of physical address from page table
    tr_addr = (tr_addr<<f); 
    tr_addr = (tr_addr | d);    // get 'd' of physcial address
    temp = "the physical address is- " + to_string(tr_addr);
    output.push_back(temp);
    return;
}

// function to delete a page
void del(ll pno){
    if(page_table.find(pno)==page_table.end()){ // if page number not available in page table 
        string temp = "no such page available. Nothing deleted";
        output.push_back(temp);
        return;
    }
    
    string temp = "frame no " + to_string(page_table[pno]) + " has been deleted";
    free_frame++;   // update number of free frames
    allocated_frame.erase(page_table[pno]); // free up allocated frame
    page_table.erase(pno);  // remove entry from page table
    output.push_back(temp);
    return;
}

int main(){
    cin>>p>>v>>f;   // take input
    maxpage = (1<<(v-f));   // maximum number of possible pages
    maxframe = (1<<(p-f));  // maximum number of possible frames
    free_frame = maxframe;  // number of free frames
    page_size = (1<<(f));   

    cin.ignore();   // input
    string tempin;
    getline(cin, tempin);
    istringstream temp(tempin);
    ll p1;
    while(temp>>p1){
        ll p2;
        temp>>p2;
        kernel[p1] = p2;    // p1 to p2 as kernel part
        free_frame -= (p2-p1+1);    // update number of free frames
    }
    
    while(1){
        char c;
        cin.get(c);
        if(c=='\n')
            break;
        ll x;
        cin>>x;
        if(c=='a')  // allocate command
            allocate(x);
        else if(c=='t') // translate command
            translate(x);
        else if(c=='d') // delete command
            del(x);
        cin.get(c);
    }

    for(string x: output)   // print output
        cout<<x<<endl;

    return 0;
}
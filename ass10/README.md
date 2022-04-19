SUSHANT SINHA
1901CS62

Q1:
Compile: g++ q1.cpp -o q1
Run: ./q1
Input:
7 10 2
0 2 5 7
a 64
d 3
d 5
t 43
a 32
t 26

NOTE: Add extra newline character after output
Output:
64 bytes has been allocated in frame no 3,4,8,9,10,11,12,13,14,15,16,17,18,19,20,21
frame no 9 has been deleted
frame no 11 has been deleted
the physical address is- 67
32 bytes has been allocated in frame no 9,11,22,23,24,25,26,27
the physical address is- 50

Input:
7 10 4
0 2 5 7
a 64
t 43
t 241
d 1
a 32


Output:
Insufficient amount of frames available.
invalid page no
invalid page no
no such page available. Nothing deleted
32 bytes has been allocated in frame no 3,4
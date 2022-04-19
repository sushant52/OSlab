SUSHANT SINHA
1901CS62
ASSIGNMENT 9

Q1:
Compile: g++ q1.cpp -o q1
Command: ./q1
Input:
3
4 7 6 1 7 6 1 2 7 2

Output: 
Best Page Replacement Algorithm: OPTIMAL
F1 F2 F3 
X X X at time 0
4 X X at time 1
4 7 X at time 2
4 7 6 at time 3
1 7 6 at time 4
1 7 6 at time 5
1 7 6 at time 6
1 7 6 at time 7
2 7 6 at time 8
2 7 6 at time 9
2 7 6 at time 10
#Page faults: 5

Input:
4
1 2 3 4 2 7 5 1 1 6 4 7 2 1 2 5 

Output: 
Best Page Replacement Algorithm: OPTIMAL
F1 F2 F3 F4 
X X X X at time 0
1 X X X at time 1
1 2 X X at time 2
1 2 3 X at time 3
1 2 3 4 at time 4
1 2 3 4 at time 5
1 2 7 4 at time 6
1 5 7 4 at time 7
1 5 7 4 at time 8
1 5 7 4 at time 9
1 6 7 4 at time 10
1 6 7 4 at time 11
1 6 7 4 at time 12
1 2 7 4 at time 13
1 2 7 4 at time 14
1 2 7 4 at time 15
5 2 7 4 at time 16
#Page faults: 9

Q2:
Compile: g++ q2.cpp -o q2
Command: ./q2
Input:
3
5 0 1 2 0 3 2 0 3 4 1 0 5 0 4 3 2 1 2 0 1

Output: 
#Page Faults for FIFO: 15
#Page Faults for LRU: 14
#Page Faults for OPTIMAL: 11
#Page Faults for NEW_ALGO: 12
F1 F2 F3 
X X X at time 0
5 X X at time 1
5 0 X at time 2
5 0 1 at time 3
2 0 1 at time 4
2 0 1 at time 5
3 0 1 at time 6
2 0 1 at time 7
2 0 1 at time 8
3 0 1 at time 9
4 0 1 at time 10
4 0 1 at time 11
4 0 1 at time 12
5 0 1 at time 13
5 0 1 at time 14
4 0 1 at time 15
3 0 1 at time 16
2 0 1 at time 17
2 0 1 at time 18
2 0 1 at time 19
2 0 1 at time 20
2 0 1 at time 21
#Page faults: 12

Input:
4
1 2 3 4 2 7 5 1 1 6 4 7 2 1 2 5

Output:
#Page Faults for FIFO: 13
#Page Faults for LRU: 13
#Page Faults for OPTIMAL: 9
#Page Faults for NEW_ALGO: 10
F1 F2 F3 F4 
X X X X at time 0
1 X X X at time 1
1 2 X X at time 2
1 2 3 X at time 3
1 2 3 4 at time 4
1 2 3 4 at time 5
7 2 3 4 at time 6
5 2 3 4 at time 7
1 2 3 4 at time 8
1 2 3 4 at time 9
1 2 6 4 at time 10
1 2 6 4 at time 11
1 2 7 4 at time 12
1 2 7 4 at time 13
1 2 7 4 at time 14
1 2 7 4 at time 15
1 2 5 4 at time 16
#Page faults: 10
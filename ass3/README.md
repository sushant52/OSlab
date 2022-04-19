SUSHANT SINHA
1901CS62
All the scripts take command line arguments as input.
All shell files are ran on Ubuntu 18.04 LTS
To add executable permissions to the shell scripts, type the following commands in terminal while being in correct directory:

sudo chmod u+rx task1.sh
sudo chmod u+rx task2.sh

Tests and outputs:

Question 1:-
Compile C program:
gcc q1.c -o q1

./q1
Output: ERROR: Required number of arguments are 2.

./q1 5 7
Output:
Result of Multiplication by Child PID 19288 : 35
Result of Addition by Child PID 19290 : 12
Result of Division by Parent PID 19289 : 2.916667

./q1 -3 8
Output:
Result of Multiplication by Child PID 19298 : -24
Result of Addition by Child PID 19300 : 5
Result of Division by Parent PID 19299 : -4.800000

Question 2:-

Compile C program:
gcc q2.c -o q2

./q2
Output: Hello   Hello   Hello   Hello   Hello   Hello   Hello   Hello   

Two fork() calls are added in code. This leads to creation of total 4 processes.
Inside the func() function, all 4 processes print "Hello    ".
After returning back to main() function, all 4 processes print "Hello   " again.
This leads to printing Hello 8 times thus printing:
Hello   Hello   Hello   Hello   Hello   Hello   Hello   Hello   

Question 3:-

Compile C program:
gcc q3.c -o q3

./q3 task1.sh 2 8 9 9 task2.sh 5
Output: 
N = 5, Output = 1200
Search found along with its index: 1, of searched item: 9

./q3 task1.sh 5 8 9 1 2 3 0 task2.sh 3
Output: 
N = 3, Output = 30
Error: No match found.

./q3 task1.sh 3 4 5 6 4 task2.sh 2
Output:
N = 2, Output = 4
Search found along with its index: 0, of searched item: 4
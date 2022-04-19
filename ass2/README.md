All the scripts take command line arguments as input.
All shell files are ran on Ubuntu 18.04 LTS
To add executable permissions to the shell scripts, type the following commands in terminal while being in correct directory:

sudo chmod u+rx q1.sh
sudo chmod u+rx q2.sh
sudo chmod u+rx q3.sh
sudo chmod u+rx q4.sh

Tests and outputs:

Question 1:-
NOTE: 0 based indexing

./q1.sh 3 45 67 12 45
Output: Search found along with its index: 0, of searched item: 45

./q1.sh 5 99 100 23 56 102 56
Output: Search found along with its index: 3, of searched item: 56

./q1.sh 5 99 100 23 56 102 28
Output: Error: No match found.

Question 2:-

./q2.sh
Output: Number of required arguments is 1

./q2.sh 3
Output: N = 3, Output = 30

./q2.sh 7
Output: N = 7, Output = 85680

Question 3:-

Shell:

./q3.sh
Output: Required number of inputs is 2

./q3.sh 34 789
Output:
Decimal: XOR of 34 and 789: 823 
Binary: XOR of 0000100010 and 1100010101: 1100110111

./q3.sh 3 5
Output:
Decimal: XOR of 3 and 5: 6 
Binary: XOR of 011 and 101: 110

C equivalent code:
NOTE: First, we compile the program once

gcc q3.c -o q3

./q3
Output: Required number of arguments is two

./q3 34 789
Output: 
Decimal: XOR of 34 and 789: 823
Binary: XOR of 0000100010 and 1100010101: 1100110111

./q3 3 5
Output:
Decimal: XOR of 3 and 5: 6
Binary: XOR of 011 and 101: 110

Time Comparison:
Shell:
time ./q3.sh 34 789
Output:
Decimal: XOR of 34 and 789: 823 
Binary: XOR of 0000100010 and 1100010101: 1100110111

real	0m0.005s
user	0m0.000s
sys	0m0.005s

C:
time ./q3 34 789
Output:
Decimal: XOR of 34 and 789: 823
Binary: XOR of 0000100010 and 1100010101: 1100110111

real	0m0.002s
user	0m0.002s
sys	0m0.001s

Shell:
time ./q3.sh 3 5
Output:
Decimal: XOR of 3 and 5: 6 
Binary: XOR of 011 and 101: 110

real	0m0.006s
user	0m0.003s
sys	0m0.003s

C:
time ./q3 3 5
Output:
Decimal: XOR of 3 and 5: 6
Binary: XOR of 011 and 101: 110

real	0m0.002s
user	0m0.002s
sys	0m0.000s

Shell:
time ./q3.sh 213465 246246
Output:
Decimal: XOR of 213465 and 246246: 32831 
Binary: XOR of 110100000111011001 and 111100000111100110: 001000000000111111

real	0m0.006s
user	0m0.003s
sys	0m0.004s

C:
time ./q3 213465 246246
Output:
Decimal: XOR of 213465 and 246246: 32831
Binary: XOR of 110100000111011001 and 111100000111100110: 001000000000111111

real	0m0.002s
user	0m0.000s
sys	0m0.002s

Question 4:-

./q4.sh
Output: Required number of inputs is one

./q4.sh "sfajafs"
Output: INVALID PASSWORD

./q4.sh "asfa124///"
Output: VALID PASSWORD

./q4.sh "/13fsasf"
Output: VALID PASSWORD

./q4.sh "/<>()[l[.sfvs[.45"
Output: VALID PASSWORD

All the scripts take command line arguments as input.
All shell files are ran on Ubuntu 18.04 LTS
To add executable permissions to the shell scripts, type the following commands in terminal while being in correct directory:

sudo chmod u+rx q1.sh
sudo chmod u+rx q2.sh
sudo chmod u+rx q3.sh
sudo chmod u+rx q4.sh

Tests and outputs:

Question 1:-

./q1.sh 567
Output: Reversed Number is : 765

./q1.sh
Output: ERROR: No argument provided.

./q1.sh 567 57
Output: ERROR: Too many arguments provided.

Question 2:-

./q2.sh 5 15
5 6 7 8 9 10 11 12 13 14 15

./q2.sh
ERROR: Two command line arguments needed.

./q2.sh 567 567
Output: 567

./q2.sh 8 3
ERROR: First number must not be greater than second number.

Question 3:-
Consider we have two files lorem.txt and ipsum.txt in the same directory with 12 and 3 lines respectively.

./q3.sh lorem.txt 5
Output: Total lines in file: 12

./q3.sh ipsum.txt 5
Output: 
Total lines in file: 3
File Deleted.

The file was successfully deleted here.

Question 4:-
Consider we have four files, fast.c , aspart.py , las.cpp and kr7.c, in the same directory.

./q4.sh ~/Desktop/OSlab/ass1 as NEWAS
Output: Total 3 files renamed.

fast.c was changed to NEWAS_1.c
aspart.py was changed to NEWAS_2.py
las.cpp was changed to NEWAS_3.cpp

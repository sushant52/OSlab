SUSHANT SINHA
1901CS62
MIDSEM

Q1:
Compile: gcc q1.c -o q1
Run: ./q1
Output: 42 files were made named 1.txt, 2.txt, ... , 42.txt
Each file contained the contents of mth line of q1.c, such as:-
29.txt:        if(fork()==0){  // Inside child process

Q2:
Compile: gcc child.c -o child
gcc parent.c -o parent
Run: ./parent girl Nancy boy Mark boy Joseph
Output:
I have 3 children.
Child # 1: I am a girl, and my name is Nancy.
Child # 2: I am a boy, and my name is Mark.
Child # 3: I am a boy, and my name is Joseph.
All child processes terminated. Parent exits.

Run: ./parent girl Nancy girl Cindy
Output:
I have 2 children.
Child # 1: I am a girl, and my name is Nancy.
Child # 2: I am a girl, and my name is Cindy.
All child processes terminated. Parent exits.

Q3:
Compile: g++ q3.cpp -o q3
Run: ./q3
Input: 
5 2
0 10 2
3 7 1
4 6 2
12 5 1
18 8 1

Output:
Avg_WT = 10.00 Avg_TAT = 17.20
P2 P4 P5 P1 P3

Q4:
NOTE: We have used sleep() and spinlocks in the program to give diverse outputs
Initially, 150 treasure is placed in treasury
Compile: gcc q4.c -o q4 -lpthread
Run: ./q4
OUTPUT SIMULATION 1:
Enter amount to be borrowed: 45
Amount = 45 borrowed from treasury.
Total Amount in treasury = 105

Enter amount to be borrowed: 35
Amount = 35 borrowed from treasury.
Total Amount in treasury = 70

Enter amount to be borrowed: 65
Amount = 65 borrowed from treasury.
Total Amount in treasury = 5

Enter amount to be borrowed: 8
Hacker took 5 amount from treasury.

EXPLANATION: In the last attempt, we had insufficient funds, so we waited for depositor to deposit money.
Before it could happen, hacker took all the remaining treasure and program ended.

OUTPUT SIMULATION 2:
Enter amount to be borrowed: 20
Amount = 20 borrowed from treasury.
Total Amount in treasury = 130

Enter amount to be borrowed: 30
Amount = 30 borrowed from treasury.
Total Amount in treasury = 100

Enter amount to be borrowed: 100
Amount = 100 borrowed from treasury.
Total Amount in treasury = 0

Enter amount to be borrowed: 30
Amount = 30 deposited to treasury.
Total Amount in treasury = 30

Hacker took 30 amount from treasury.

EXPLANATION: In this example, we again waited for depositor to deposit money.
The required amount was deposited. However, before we could borrow, hacker came in and took all the money.

OUTPUT SIMULATION 3:
Enter amount to be borrowed: 3
Amount = 3 borrowed from treasury.
Total Amount in treasury = 147

Enter amount to be borrowed: 1
Amount = 1 borrowed from treasury.
Total Amount in treasury = 146

Hacker took 146 amount from treasury.

OUTPUT SIMULATION 4:
Enter amount to be borrowed: 200
Amount = 50 deposited to treasury.
Total Amount in treasury = 200

Amount = 200 borrowed from treasury.
Total Amount in treasury = 0

Enter amount to be borrowed: 120
Amount = 120 deposited to treasury.
Total Amount in treasury = 120

Amount = 120 borrowed from treasury.
Total Amount in treasury = 0

Enter amount to be borrowed: 230
Hacker took 0 amount from treasury.

EXPLANATION: Treasury was out of money. Even before depositor could deposit, hacker hacked.
Hacker took 0 money as treasury was fully empty.
SUSHANT SINHA
1901CS62
ASSIGNMENT 8

Q1:
Compile: gcc -o q1 q1.c
Command: ./q1
Input:
5
3
0 1 0
2 0 0 
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3
3
2

Output: 
Safe sequence 1: P1->P3->P0->P2->P4
Safe sequence 2: P1->P3->P0->P4->P2
Safe sequence 3: P1->P3->P2->P0->P4
Safe sequence 4: P1->P3->P2->P4->P0
Safe sequence 5: P1->P3->P4->P0->P2
Safe sequence 6: P1->P3->P4->P2->P0
Safe sequence 7: P1->P4->P3->P0->P2
Safe sequence 8: P1->P4->P3->P2->P0
Safe sequence 9: P3->P1->P0->P2->P4
Safe sequence 10: P3->P1->P0->P4->P2
Safe sequence 11: P3->P1->P2->P0->P4
Safe sequence 12: P3->P1->P2->P4->P0
Safe sequence 13: P3->P1->P4->P0->P2
Safe sequence 14: P3->P1->P4->P2->P0
Safe sequence 15: P3->P4->P1->P0->P2
Safe sequence 16: P3->P4->P1->P2->P0

Input:
2
2
1 1
1 1
3 3
3 3
1
1

Output: No safe sequence found
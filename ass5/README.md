SUSHANT SINHA
1901CS62
ASSIGNMENT 5

Q1:
Compile: gcc q1.c -o q1 -lpthread
Command: ./q1
Output: 
THREAD 0: Hello World!
THREAD 1: Hello World!
THREAD 2: Hello World!
THREAD 3: Hello World!
THREAD 4: Hello World!
THREAD 5: Hello World!
THREAD 7: Hello World!
i = 0, status = THREAD 0 SUCCESS
i = 1, status = THREAD 1 SUCCESS
i = 2, status = THREAD 2 SUCCESS
i = 3, status = THREAD 3 SUCCESS
THREAD 8: Hello World!
i = 4, status = THREAD 4 SUCCESS
THREAD 6: Hello World!
i = 5, status = THREAD 5 SUCCESS
i = 6, status = THREAD 6 SUCCESS
i = 7, status = THREAD 7 SUCCESS
i = 8, status = THREAD 8 SUCCESS
i = 9, status = THREAD 9 CANCELED

Comment: We can see how the execution of threads interleaves. Also,
the last thread was canceled and proper output was given out.

Q2:
Compile: gcc q2.c -o q2 -lpthread
Command: ./q2
q2file.txt:
Terminal output: Invalid inputs.

Command: ./q2 15 q2file.txt
q2file.txt:
Line number : 1 is NOT PRIME, written by thread : 139801836955392
Line number : 2 is PRIME, written by thread : 139801828562688
Line number : 3 is PRIME, written by thread : 139801828562688
Line number : 4 is NOT PRIME, written by thread : 139801836955392
Line number : 5 is PRIME, written by thread : 139801828562688
Line number : 6 is NOT PRIME, written by thread : 139801836955392
Line number : 7 is PRIME, written by thread : 139801828562688
Line number : 8 is NOT PRIME, written by thread : 139801836955392
Line number : 9 is NOT PRIME, written by thread : 139801836955392
Line number : 10 is NOT PRIME, written by thread : 139801836955392
Line number : 11 is PRIME, written by thread : 139801828562688
Line number : 12 is NOT PRIME, written by thread : 139801836955392
Line number : 13 is PRIME, written by thread : 139801828562688
Line number : 14 is NOT PRIME, written by thread : 139801836955392
Line number : 15 is NOT PRIME, written by thread : 139801836955392

Terminal Output:
Total characters in line 1 is : 65, counted by thread 139801820169984
Total characters in line 2 is : 61, counted by thread 139801820169984
Total characters in line 3 is : 61, counted by thread 139801820169984
Total characters in line 4 is : 65, counted by thread 139801820169984
Total characters in line 5 is : 61, counted by thread 139801820169984
Total characters in line 6 is : 65, counted by thread 139801820169984
Total characters in line 7 is : 61, counted by thread 139801820169984
Total characters in line 8 is : 65, counted by thread 139801820169984
Total characters in line 9 is : 65, counted by thread 139801820169984
Total characters in line 10 is : 66, counted by thread 139801820169984
Total characters in line 11 is : 62, counted by thread 139801820169984
Total characters in line 12 is : 66, counted by thread 139801820169984
Total characters in line 13 is : 62, counted by thread 139801820169984
Total characters in line 14 is : 66, counted by thread 139801820169984
Total characters in line 15 is : 66, counted by thread 139801820169984

Q3:
Compile: gcc q3.c -o q3 -lpthread
Command: ./q3
Input and output:
Enter the litres of petrol available: 1000
Enter total number of queues: 10
Enter the number of people in queue 1: 10         
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
Enter the number of people in queue 2: 10
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
Enter the number of people in queue 3: 10
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
Enter the number of people in queue 4: 10
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
Enter the number of people in queue 5: 10
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
Enter the number of people in queue 6: 10
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
Enter the number of people in queue 7: 10
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
Enter the number of people in queue 8: 10
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
Enter the number of people in queue 9: 10
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
Enter the number of people in queue 10: 10
Enter the petrol demand of each person: 1 1 1 1 1 1 1 1 1 1
1 litres given to person number: 0 in queue: 0. Remaining petrol: 999
1 litres given to person number: 1 in queue: 0. Remaining petrol: 998
1 litres given to person number: 2 in queue: 0. Remaining petrol: 997
1 litres given to person number: 3 in queue: 0. Remaining petrol: 996
1 litres given to person number: 4 in queue: 0. Remaining petrol: 995
1 litres given to person number: 5 in queue: 0. Remaining petrol: 994
1 litres given to person number: 6 in queue: 0. Remaining petrol: 993
1 litres given to person number: 7 in queue: 0. Remaining petrol: 992
1 litres given to person number: 8 in queue: 0. Remaining petrol: 991
1 litres given to person number: 9 in queue: 0. Remaining petrol: 990
1 litres given to person number: 0 in queue: 1. Remaining petrol: 989
1 litres given to person number: 1 in queue: 1. Remaining petrol: 988
1 litres given to person number: 2 in queue: 1. Remaining petrol: 987
1 litres given to person number: 3 in queue: 1. Remaining petrol: 986
1 litres given to person number: 4 in queue: 1. Remaining petrol: 985
1 litres given to person number: 5 in queue: 1. Remaining petrol: 984
1 litres given to person number: 6 in queue: 1. Remaining petrol: 983
1 litres given to person number: 7 in queue: 1. Remaining petrol: 982
1 litres given to person number: 8 in queue: 1. Remaining petrol: 981
1 litres given to person number: 9 in queue: 1. Remaining petrol: 980
1 litres given to person number: 0 in queue: 6. Remaining petrol: 979
1 litres given to person number: 1 in queue: 6. Remaining petrol: 978
1 litres given to person number: 0 in queue: 2. Remaining petrol: 977
1 litres given to person number: 0 in queue: 3. Remaining petrol: 976
1 litres given to person number: 1 in queue: 3. Remaining petrol: 975
1 litres given to person number: 2 in queue: 3. Remaining petrol: 974
1 litres given to person number: 2 in queue: 6. Remaining petrol: 973
1 litres given to person number: 3 in queue: 6. Remaining petrol: 972
1 litres given to person number: 4 in queue: 6. Remaining petrol: 971
1 litres given to person number: 5 in queue: 6. Remaining petrol: 970
1 litres given to person number: 6 in queue: 6. Remaining petrol: 969
1 litres given to person number: 3 in queue: 3. Remaining petrol: 968
1 litres given to person number: 1 in queue: 2. Remaining petrol: 967
1 litres given to person number: 2 in queue: 2. Remaining petrol: 966
1 litres given to person number: 3 in queue: 2. Remaining petrol: 965
1 litres given to person number: 4 in queue: 2. Remaining petrol: 964
1 litres given to person number: 5 in queue: 2. Remaining petrol: 963
1 litres given to person number: 0 in queue: 9. Remaining petrol: 962
1 litres given to person number: 0 in queue: 4. Remaining petrol: 961
1 litres given to person number: 1 in queue: 4. Remaining petrol: 960
1 litres given to person number: 2 in queue: 4. Remaining petrol: 959
1 litres given to person number: 3 in queue: 4. Remaining petrol: 958
1 litres given to person number: 4 in queue: 4. Remaining petrol: 957
1 litres given to person number: 5 in queue: 4. Remaining petrol: 956
1 litres given to person number: 6 in queue: 4. Remaining petrol: 955
1 litres given to person number: 7 in queue: 4. Remaining petrol: 954
1 litres given to person number: 8 in queue: 4. Remaining petrol: 953
1 litres given to person number: 9 in queue: 4. Remaining petrol: 952
1 litres given to person number: 7 in queue: 6. Remaining petrol: 951
1 litres given to person number: 8 in queue: 6. Remaining petrol: 950
1 litres given to person number: 9 in queue: 6. Remaining petrol: 949
1 litres given to person number: 6 in queue: 2. Remaining petrol: 948
1 litres given to person number: 7 in queue: 2. Remaining petrol: 947
1 litres given to person number: 8 in queue: 2. Remaining petrol: 946
1 litres given to person number: 9 in queue: 2. Remaining petrol: 945
1 litres given to person number: 0 in queue: 5. Remaining petrol: 944
1 litres given to person number: 1 in queue: 5. Remaining petrol: 943
1 litres given to person number: 2 in queue: 5. Remaining petrol: 942
1 litres given to person number: 3 in queue: 5. Remaining petrol: 941
1 litres given to person number: 0 in queue: 7. Remaining petrol: 940
1 litres given to person number: 1 in queue: 7. Remaining petrol: 939
1 litres given to person number: 2 in queue: 7. Remaining petrol: 938
1 litres given to person number: 1 in queue: 9. Remaining petrol: 937
1 litres given to person number: 2 in queue: 9. Remaining petrol: 936
1 litres given to person number: 3 in queue: 9. Remaining petrol: 935
1 litres given to person number: 4 in queue: 9. Remaining petrol: 934
1 litres given to person number: 5 in queue: 9. Remaining petrol: 933
1 litres given to person number: 6 in queue: 9. Remaining petrol: 932
1 litres given to person number: 7 in queue: 9. Remaining petrol: 931
1 litres given to person number: 8 in queue: 9. Remaining petrol: 930
1 litres given to person number: 9 in queue: 9. Remaining petrol: 929
1 litres given to person number: 0 in queue: 8. Remaining petrol: 928
1 litres given to person number: 1 in queue: 8. Remaining petrol: 927
1 litres given to person number: 2 in queue: 8. Remaining petrol: 926
1 litres given to person number: 3 in queue: 8. Remaining petrol: 925
1 litres given to person number: 4 in queue: 8. Remaining petrol: 924
1 litres given to person number: 5 in queue: 8. Remaining petrol: 923
1 litres given to person number: 6 in queue: 8. Remaining petrol: 922
1 litres given to person number: 7 in queue: 8. Remaining petrol: 921
1 litres given to person number: 8 in queue: 8. Remaining petrol: 920
1 litres given to person number: 9 in queue: 8. Remaining petrol: 919
1 litres given to person number: 4 in queue: 3. Remaining petrol: 918
1 litres given to person number: 5 in queue: 3. Remaining petrol: 917
1 litres given to person number: 6 in queue: 3. Remaining petrol: 916
1 litres given to person number: 7 in queue: 3. Remaining petrol: 915
1 litres given to person number: 8 in queue: 3. Remaining petrol: 914
1 litres given to person number: 9 in queue: 3. Remaining petrol: 913
1 litres given to person number: 4 in queue: 5. Remaining petrol: 912
1 litres given to person number: 5 in queue: 5. Remaining petrol: 911
1 litres given to person number: 6 in queue: 5. Remaining petrol: 910
1 litres given to person number: 7 in queue: 5. Remaining petrol: 909
1 litres given to person number: 8 in queue: 5. Remaining petrol: 908
1 litres given to person number: 9 in queue: 5. Remaining petrol: 907
1 litres given to person number: 3 in queue: 7. Remaining petrol: 906
1 litres given to person number: 4 in queue: 7. Remaining petrol: 905
1 litres given to person number: 5 in queue: 7. Remaining petrol: 904
1 litres given to person number: 6 in queue: 7. Remaining petrol: 903
1 litres given to person number: 7 in queue: 7. Remaining petrol: 902
1 litres given to person number: 8 in queue: 7. Remaining petrol: 901
1 litres given to person number: 9 in queue: 7. Remaining petrol: 900

Command: ./q3
Input and output:
Enter the litres of petrol available: 10
Enter total number of queues: 2
Enter the number of people in queue 1: 10
Enter the petrol demand of each person: 4 11 12 13 14 15 16 17 18 19
Enter the number of people in queue 2: 3
Enter the petrol demand of each person: 5 9 8
4 litres given to person number: 0 in queue: 0. Remaining petrol: 6
5 litres given to person number: 0 in queue: 1. Remaining petrol: 1
SUSHANT SINHA
1901CS62
ASSIGNMENT 7

Q1:
Compile: gcc -o q1 q1.c -lpthread -lrt
Command: ./q1
Output: 
Reader thread:2, completed.
Reader thread:3, completed.
Reader thread:1, completed.
Reader thread:4, completed.
Reader thread:5, completed.
Writer thread:1, completed.
Writer thread:2, completed.

Explanation: First 5 readers read simultaneously and the writers had to wait for readers to complete.
Then, the writers wrote one by one.

Q2:
Inside A:
wait(mutex);
wait(data);

Inside B:
wait(data);
wait(mutex);

The ordering of the wait calls can lead to deadlock.
Suppose, the sequence is this:
A:wait(mutex) -> B:wait(data) -> A:wait(data) -> B:wait(mutex)

First, A acquires mutex then, B acquires data.
Now, A is asking for data which is held by B
and B is asking for mutex which is held by A.
Since both threads will not let go of resource they have acquired
and asking for resource other thread has, both threads come at halt and deadlock occurs.

This is solved by making the wait statements as follows:
Inside A:
wait(mutex);
wait(data);

Inside B:
wait(mutex);
wait(data);

This ensures that only that one thread gets both or none of the resource.
Compile: gcc -o q2 q2.c -lpthread -lrt
Command: ./q2
Output: process Aprocess B

Q3:
Compile: gcc -o q3 q3.c -lpthread
Command: ./q3
Output(ran for 11 seconds):
Student 1 took a slice and studied.
Student 2 took a slice and studied.
Student 3 took a slice and studied.
Student 4 took a slice and studied.
Student 5 took a slice and studied.
Student 5 ordered pizza.
Student 7 sleeping due to lack of pizza.
Student 6 sleeping due to lack of pizza.
Student 8 sleeping due to lack of pizza.
Student 4 sleeping due to lack of pizza.
Student 1 sleeping due to lack of pizza.
Student 2 sleeping due to lack of pizza.
Student 3 sleeping due to lack of pizza.
5 slices of pizza delivered.
Student 2 took a slice and studied.
Student 1 took a slice and studied.
Student 8 took a slice and studied.
Student 4 took a slice and studied.
Student 7 took a slice and studied.
Student 7 ordered pizza.
Student 2 sleeping due to lack of pizza.
Student 1 sleeping due to lack of pizza.
Student 8 sleeping due to lack of pizza.
Student 5 sleeping due to lack of pizza.
Student 4 sleeping due to lack of pizza.
5 slices of pizza delivered.

Explanation: Above simulation ran for 11 seconds.
First 5 people acquire pizza, then one of them has to order the pizza.
When others see no pizza is available, they sleep and wait.
When pizza is available, again 5 people acquire pizza and the cycle continues.

Output(ran for 17 seconds):
Student 1 took a slice and studied.
Student 2 took a slice and studied.
Student 3 took a slice and studied.
Student 4 took a slice and studied.
Student 5 took a slice and studied.
Student 5 ordered pizza.
Student 7 sleeping due to lack of pizza.
Student 6 sleeping due to lack of pizza.
Student 8 sleeping due to lack of pizza.
Student 1 sleeping due to lack of pizza.
Student 2 sleeping due to lack of pizza.
Student 3 sleeping due to lack of pizza.
Student 4 sleeping due to lack of pizza.
5 slices of pizza delivered.
Student 2 took a slice and studied.
Student 7 took a slice and studied.
Student 6 took a slice and studied.
Student 8 took a slice and studied.
Student 1 took a slice and studied.
Student 1 ordered pizza.
Student 2 sleeping due to lack of pizza.
Student 7 sleeping due to lack of pizza.
Student 6 sleeping due to lack of pizza.
Student 8 sleeping due to lack of pizza.
5 slices of pizza delivered.
Student 7 took a slice and studied.
Student 8 took a slice and studied.
Student 6 took a slice and studied.
Student 2 took a slice and studied.
Student 4 took a slice and studied.
Student 4 ordered pizza.
Student 5 sleeping due to lack of pizza.
Student 3 sleeping due to lack of pizza.
Student 7 sleeping due to lack of pizza.
Student 8 sleeping due to lack of pizza.
Student 6 sleeping due to lack of pizza.
Student 2 sleeping due to lack of pizza.
Student 1 sleeping due to lack of pizza.
5 slices of pizza delivered.
Student 6 took a slice and studied.
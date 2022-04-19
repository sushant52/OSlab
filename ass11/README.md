SUSAHANT SINHA
1901CS62

Q1:-
Compile: g++ -o q1 q1.cpp
Run: ./q1
Input:
Enter number of jobs in work queue: 5
Enter the work queue: 23 89 132 42 187

Output:
Total head movement and seek time:-
FCFS: 421    2105ms
SSTF: 273    1365ms
SCAN: 275    1375ms
C-SCAN: 387    1935ms

Datapoints for graph(X,Y):
FCFS:-
100 1
23 2
89 3
132 4
42 5
187 6

Plotting using gnuplot:-
gnuplot> set style line 1 \
>    linecolor rgb '#0060ad' \
>    linetype 1 linewidth 2 \
>    pointtype 7 pointsize 1.5
gnuplot> set title "FCFS"
gnuplot> set xlabel "Head Position"
gnuplot> set ylabel "Work number"
gnuplot> plot "fcfs.txt" with linespoints linestyle 1

SIMILARILY, rest of the algorithms data can be plotted

SSTF:-
100 1
89 2
132 3
187 4
42 5
23 6

SCAN:-
100 1
132 2
187 3
199 4
89 5
42 6
23 7

C-SCAN:-
100 1
132 2
187 3
199 4
0 5
23 6
42 7
89 8

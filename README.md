# Deadlock-Avoidance-Program

1) Copy the entire code from the file called "deadlock.c".
2) Use an IDE that can run a code that is based of C (Example: Replit).
3) Run the program/code, To compile in linux ubuntu:

   gcc deadlock.c
   
   ./a.out

In this assignment we are dealt with the problem of multiple procceses trying to access the same resource. This situation is called a Deadlock. Due to the action of the processes, they are preventing each other from acquiring the reasources. 

Deadlock Avoidance: to prevent this problem from occuring in our program, we need to stop one of the processes once it has aqcuired what it needed. We use void function as it will not being returnning the values itself but the bt(burst time: time required by a process for its execution on the CPU), wt(wait time: period of time in which a work item, like a document, is waiting for further processing), and tat(turnaround time: time interval from the time of submission of a process to the time of the completion of the process). This program will have a list already coded into the program for burst time as we were having problems trying to make it use user inputs.



//Jacob Silveira and Jose Castillo
//CST-315
//2-27-2022
//Assignment 3: Deadlock avoidance program
//To compile: 
//gcc deadlock.c
//./a.out

//includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//first function waitTime purpose is to find the witing time for all processes
void waitTime(int process[], int n, int burstT[], int waitT[], int quant)
{
//copy is made of burstT to store the remaining rem_burstT times
int rem_burstT[n];
  for (int i = 0 ; i < n ; i++)
      rem_burstT[i] = burstT[i];

int t = 0; //current time set
//here each process is traversed
while (1)
{
  bool done = true;
  //each processes traversed one by one 
    for (int i = 0 ; i < n; i++)
    {
      if (rem_burstT[i] > 0) //if burstT of a ceratin process is > 0 then only one process further
      {
      done = false; //then there is a process that is waiting

      if (rem_burstT[i] > quant)
      {
        //the value of t is increase to show how much time a certain process is processed
        t += quant; 
        //burst_time of current porcess is decreased by quant
        rem_burstT[i] -= quant;
      }
      //this is if the burst time is either smaller or equal to the quant
      //last cycle
      else
      {
        t = t + rem_burstT[i]; //increased t show how much T a process has been processed
        waitT[i] = t - burstT[i]; //wait time is the current T - T used by specific process
        rem_burstT[i] = 0; //process is completely executed and remaining burst time set to 0
        }
    }
}
    //if every process is done then
    if (done == true)
    break;
   }
}

//second function will calculate what the turn around time
void turnTime(int process[], int n, int burstT[], int waitT[], int turnT[])
{
//turn around time is found by adding the burst time [i] with the wait time [i]
for (int i = 0; i < n ; i++)
    turnT[i] = burstT[i] + waitT[i];
}

//third function will caclcuate the average time for processes
void averageTime(int process[], int n, int burstT[], int quant)
{
int waitT[n], turnT[n], total_waitT = 0, total_turnT = 0;
//bringing in waitTime function for the waiting time of all processes
waitTime(process, n, burstT, waitT, quant);
//bringing in turnTime function to find the turn around time of all processes
turnTime(process, n, burstT, waitT, turnT);
//printfs to display the process number, burst time, wait time, and turn around time
printf("T = Time\n");
printf( "Processes Burst T Waiting T Turn around T\n");

//calculating the total turn around time and waiting time and printing data
for (int i=0; i<n; i++)
{
  total_waitT = total_waitT + waitT[i];
  total_turnT = total_turnT + turnT[i];
  printf(" %d \t\t %d \t %d \t\t %d",i+1, burstT[i] ,waitT[i] ,turnT[i]);
  printf("\n");
}
  printf("Average waiting time = %f"
  ,(float)total_waitT / (float)n);
  printf("\nAverage turn around time = %f"
  ,(float)total_turnT / (float)n);
}

//main 
int main()
{
   //initinilizing process identifiers
   int process[] = { 1, 2, 3};
   int n = sizeof process / sizeof process[0];

   //setting burst time of all processes
   int burst_time[] = {15, 20, 25};

   //setting time quant
   int quantum = 2;
   averageTime(process, n, burst_time, quantum);
   return 0;
}

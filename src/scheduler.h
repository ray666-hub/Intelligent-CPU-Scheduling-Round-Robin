#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX 20

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void roundRobin(Process p[], int n, int time_quantum);
void printGanttChart(int gantt[], int time[], int len);

#endif

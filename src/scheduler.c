#include <stdio.h>
#include "scheduler.h"

void roundRobin(Process p[], int n, int tq) {
    int time = 0, completed = 0;
    int gantt[100], gantt_time[100];
    int g = 0;

    while (completed < n) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 && p[i].arrival_time <= time) {
                done = 0;
                gantt[g] = p[i].pid;
                gantt_time[g++] = time;

                if (p[i].remaining_time > tq) {
                    time += tq;
                    p[i].remaining_time -= tq;
                } else {
                    time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    p[i].completion_time = time;
                    completed++;
                }
            }
        }
        if (done) time++;
    }

    gantt_time[g] = time;
    printGanttChart(gantt, gantt_time, g);

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].completion_time, p[i].waiting_time,
               p[i].turnaround_time);
    }
}

void printGanttChart(int gantt[], int time[], int len) {
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < len; i++)
        printf(" P%d |", gantt[i]);

    printf("\n%d", time[0]);
    for (int i = 1; i <= len; i++)
        printf("   %d", time[i]);
    printf("\n");
}

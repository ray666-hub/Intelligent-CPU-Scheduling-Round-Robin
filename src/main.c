#include <stdio.h>
#include "scheduler.h"

int main() {
    int n, tq;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time & Burst Time for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    roundRobin(p, n, tq);
    return 0;
}


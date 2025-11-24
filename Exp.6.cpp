#include <stdio.h>

struct Process {
    int pid, bt, at, priority;
    int rt;   // remaining time
};

int main() {
    int n, completed = 0, time = 0, i, minP, totalWT = 0, totalTAT = 0;
    float avgWT, avgTAT;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter priority (lower number = higher priority): ");
        scanf("%d", &p[i].priority);

        p[i].pid = i+1;
        p[i].rt = p[i].bt;
    }

    printf("\nGantt Chart (Process Execution Order):\n");

    while(completed != n) {
        minP = -1;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0) {
                if(minP == -1 || p[i].priority < p[minP].priority)
                    minP = i;
            }
        }

        if(minP == -1) {
            time++;
            continue;
        }

        printf("P%d -> ", p[minP].pid);

        p[minP].rt--;
        time++;

        if(p[minP].rt == 0) {
            completed++;
            int tat = time - p[minP].at;  // Turnaround time
            int wt = tat - p[minP].bt;    // Waiting time

            totalWT += wt;
            totalTAT += tat;
        }
    }

    avgWT = (float)totalWT / n;
    avgTAT = (float)totalTAT / n;

    printf("\n\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}

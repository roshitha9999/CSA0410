#include <stdio.h>

struct Process {
    int pid, bt, at, wt, tat, finished;
};

int main() {
    int n, time = 0, completed = 0, i, shortest;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);

        p[i].finished = 0;
    }

    printf("\nExecution Order (Gantt Chart):\n");

    while (completed != n) {
        shortest = -1;

        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].finished == 0) {
                if (shortest == -1 || p[i].bt < p[shortest].bt) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        printf("P%d -> ", p[shortest].pid);
        time += p[shortest].bt;
        p[shortest].tat = time - p[shortest].at;
        p[shortest].wt = p[shortest].tat - p[shortest].bt;
        p[shortest].finished = 1;
        completed++;
    }

    printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", 
            p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);

        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}

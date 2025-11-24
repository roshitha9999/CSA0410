#include <stdio.h>

int main() {
    int burst[20], priority[20], process[20], waiting[20], turnaround[20];
    int n, i, j, temp;
    float avg_wait = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process\n");
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &burst[i]);
        printf("P%d Priority (smaller number = higher priority): ", i+1);
        scanf("%d", &priority[i]);
    }

    // Sort by priority (Non-preemptive)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                // swap priority
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // swap burst
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                // swap process IDs
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    waiting[0] = 0; // first process has no wait

    for (i = 1; i < n; i++)
        waiting[i] = waiting[i-1] + burst[i-1];

    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        avg_wait += waiting[i];
        avg_tat += turnaround[i];
    }

    avg_wait /= n;
    avg_tat /= n;

    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", process[i], burst[i], priority[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wait);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

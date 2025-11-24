#include <stdio.h>

int main() {
    int burst[20], process[20], waiting[20], turnaround[20];
    int i, j, n, temp;
    float avg_wait = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &burst[i]);
        process[i] = i + 1; // Store process ID
    }

    // Sort processes by burst time (SJF)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst[i] > burst[j]) {
                // swap burst times
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

    // Waiting time for first process is 0
    waiting[0] = 0;

    // Calculate waiting times
    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        avg_wait += waiting[i];
        avg_tat += turnaround[i];
    }

    avg_wait /= n;
    avg_tat /= n;

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", process[i], burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wait);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

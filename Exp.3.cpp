	#include <stdio.h>

int main() {
    int burst[20], waiting[20], turnaround[20];
    int i, n;
    float avg_wait = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &burst[i]);
    }

    waiting[0] = 0;  // First process has 0 waiting time

    // Calculate waiting time
    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        avg_wait += waiting[i];
        avg_tat += turnaround[i];
    }

    // Display results
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, burst[i], waiting[i], turnaround[i]);
    }

    avg_wait /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wait);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

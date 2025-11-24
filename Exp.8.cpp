#include <stdio.h>

int main() {
    int n, tq, i, time = 0, remain, flag = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];
    
    for(i = 0; i < n; i++){
        printf("Enter Burst Time for Process P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // copy burst time to remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;
    printf("\nGantt Chart:\n");

    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                printf("P%d -> ", i+1);

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                    remain--;
                }
            }
        }
    }

    printf("\n\nProcess\tBT\tWT\tTAT\n");
    float avgWT = 0, avgTAT = 0;

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}

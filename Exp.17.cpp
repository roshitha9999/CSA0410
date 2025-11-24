#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m];
    int f[n], ans[n], ind = 0;

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (k = 0; k < n; k++)
        f[k] = 0;

    int need[n][m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nSafe Sequence: ");

    for (k = 0; k < n; k++) {  
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;

                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    f[i] = 1;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            printf("\nSystem is NOT in a safe state! (Deadlock possible)\n");
            return 0;
        }
    }

    for (i = 0; i < n; i++)
        printf("P%d ", ans[i]);

    printf("\nSystem is in a SAFE state.\n");

    return 0;
}


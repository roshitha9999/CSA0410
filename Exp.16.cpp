#include <stdio.h>
#include <stdlib.h>

struct emp {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct emp e;
    int choice, pos;

    fp = fopen("employee.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("employee.dat", "wb+");
        if (fp == NULL) {
            printf("Cannot open file.\n");
            exit(1);
        }
    }

    while (1) {
        printf("\n1. Add Record\n2. Display Record by Position\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Emp ID, Name, Salary: ");
            scanf("%d %s %f", &e.id, e.name, &e.salary);

            fseek(fp, 0, SEEK_END);
            fwrite(&e, sizeof(e), 1, fp);

            printf("Record Added!\n");
            break;

        case 2:
            printf("Enter record position to read (starting from 1): ");
            scanf("%d", &pos);

            if (pos < 1) {
                printf("Invalid position!\n");
                break;
            }

            fseek(fp, (pos - 1) * sizeof(e), SEEK_SET);

            if (fread(&e, sizeof(e), 1, fp))
                printf("ID: %d  Name: %s  Salary: %.2f\n", e.id, e.name, e.salary);
            else
                printf("Record not found!\n");
            break;

        case 3:
            fclose(fp);
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }
}


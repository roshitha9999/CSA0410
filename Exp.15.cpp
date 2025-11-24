#include <stdio.h>
#include <string.h>

struct
{
    char dname[20], fname[20][20];
    int fcount;
} dir[20];

int main()
{
    int dcount = 0, ch, i, j;
    char d[20], f[20];

    while (1)
    {
        printf("\n1. Create Directory\n2. Create File\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter directory name: ");
            scanf("%s", dir[dcount].dname);
            dir[dcount].fcount = 0;
            dcount++;
            printf("Directory created!\n");
            break;

        case 2:
            printf("Enter directory name: ");
            scanf("%s", d);

            for (i = 0; i < dcount; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf("Enter file name: ");
                    scanf("%s", f);
                    strcpy(dir[i].fname[dir[i].fcount], f);
                    dir[i].fcount++;
                    printf("File created!\n");
                    break;
                }
            }

            if (i == dcount)
                printf("Directory not found!\n");

            break;

        case 3:
            printf("\nDirectory Structure:\n");
            for (i = 0; i < dcount; i++)
            {
                printf("\nDirectory: %s\n", dir[i].dname);
                printf("Files:\n");

                if (dir[i].fcount == 0)
                    printf("  (No files)\n");

                for (j = 0; j < dir[i].fcount; j++)
                    printf("  %s\n", dir[i].fname[j]);
            }
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}


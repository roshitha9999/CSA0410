#include <stdio.h>
#include <string.h>

struct
{
    char dname[20];
    char fname[20][20];
    int fcount;
} dir;

int main()
{
    int ch;
    char fname[20];

    strcpy(dir.dname, "root");
    dir.fcount = 0;

    printf("\nSingle Level Directory Simulation\n");

    while (1)
    {
        printf("\n1. Create File\n2. Delete File\n3. Search File\n4. Display Files\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter file name: ");
            scanf("%s", fname);
            strcpy(dir.fname[dir.fcount], fname);
            dir.fcount++;
            printf("File created!\n");
            break;

        case 2:
            printf("Enter file name to delete: ");
            scanf("%s", fname);
            {
                int found = 0;
                for (int i = 0; i < dir.fcount; i++)
                {
                    if (strcmp(fname, dir.fname[i]) == 0)
                    {
                        found = 1;
                        printf("File deleted!\n");

                        // Replace deleted file with last file
                        strcpy(dir.fname[i], dir.fname[dir.fcount - 1]);

                        dir.fcount--;
                        break;
                    }
                }
                if (!found)
                    printf("File not found!\n");
            }
            break;

        case 3:
            printf("Enter file name to search: ");
            scanf("%s", fname);
            {
                int found = 0;
                for (int i = 0; i < dir.fcount; i++)
                {
                    if (strcmp(fname, dir.fname[i]) == 0)
                    {
                        found = 1;
                        printf("File found: %s\n", fname);
                        break;
                    }
                }
                if (!found)
                    printf("File not found!\n");
            }
            break;

        case 4:
            printf("\nDirectory name: %s\n", dir.dname);
            printf("Files:\n");
            for (int i = 0; i < dir.fcount; i++)
                printf("%s\n", dir.fname[i]);
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}


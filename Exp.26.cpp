#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f1, *f2;
    int ch;  // must be int for EOF checking

    // Create and write to file
    f1 = fopen("file1.txt", "w");
    if (f1 == NULL) {
        printf("Error opening file1.txt for writing\n");
        return 1;
    }
    fprintf(f1, "Operating Systems Lab Practice\n");
    fclose(f1);

    // Read and display file content
    f1 = fopen("file1.txt", "r");
    if (f1 == NULL) {
        printf("Error opening file1.txt for reading\n");
        return 1;
    }

    printf("Contents of file1.txt:\n");
    while ((ch = fgetc(f1)) != EOF)
        putchar(ch);
    fclose(f1);

    // Copy contents to another file
    f1 = fopen("file1.txt", "r");
    f2 = fopen("copy.txt", "w");

    if (f1 == NULL || f2 == NULL) {
        printf("Error copying files\n");
        return 1;
    }

    while ((ch = fgetc(f1)) != EOF)
        fputc(ch, f2);

    fclose(f1);
    fclose(f2);

    // Delete original file
    if (remove("file1.txt") == 0)
        printf("\nfile1.txt deleted successfully.\n");
    else
        printf("\nError deleting file1.txt.\n");

    return 0;
}


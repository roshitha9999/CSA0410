#include <stdio.h>
#include <string.h>

int main() {
    char word[50], line[200];
    FILE *fp = fopen("sample.txt", "r");

    if (!fp) {
        printf("sample.txt not found\n");
        return 0;
    }

    printf("Enter search word: ");
    scanf("%s", word);

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word)) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}


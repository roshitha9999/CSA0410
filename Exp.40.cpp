#include <stdio.h>

int main() {
    // Print the title for the section
    printf("Linux File Access Permissions:\n\n");

    // Print the types of users that permissions apply to
    printf("Types of Users:\n");
    printf("1. Owner (u) 2. Group (g) 3. Others (o)\n\n");

    // Print the different types of permissions
    printf("Permissions:\n");
    printf("r = Read\n");
    printf("w = Write\n");
    printf("x = Execute\n\n");

    // Print examples of permission strings and their meanings
    printf("Examples:\n");
    printf("rw- (Read+Write, no Execute)\n");
    printf("rwx (Read+Write+Execute)\n");
    printf("drwx (Directory with full access)\n\n");

    // Print command examples using chmod
    printf("Command Examples:\n");
    printf("chmod u+x file -> Add execute for owner\n");
    printf("chmod g-w file -> Remove write for group\n");
    printf("chmod 755 file -> rwx for owner, r-x for others\n");

    return 0;
}

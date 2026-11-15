#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int hasNumber = 0, hasSpecial = 0;

    printf("Enter a password to test: ");
    scanf("%99s", password);

    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isdigit((char)password[i])) {
            hasNumber = 1;
        } else if (!isalnum(( char)password[i])) {
            hasSpecial = 1;
        }
    }

    printf("\n--- Password Security Report ---\n");
    if (length >= 8 && hasNumber && hasSpecial) {
        printf("Status: STRONG PASSWORD\n");
    } else {
        printf("Status: WEAK PASSWORD\n");
        if (length < 8) printf("- Must be at least 8 characters long.\n");
        if (!hasNumber) printf("- Must include at least one number (0-9).\n");
        if (!hasSpecial) printf("- Must include at least one special character (@, #, $, etc.).\n");
    }

    return 0;
}

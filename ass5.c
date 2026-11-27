#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], lower[100], upper[100], reverse[100];
    int choice;

    printf("Enter a string: ");
    scanf("%s", str1);

    while (1) {
        printf("\n----- STRING OPERATIONS MENU -----\n");
        printf("1. Find string length\n");
        printf("2. Convert to lowercase\n");
        printf("3. Convert to uppercase\n");
        printf("4. Reverse string\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Length of string = %zu\n", strlen(str1));
                break;

            case 2:
                strcpy(lower, str1);
                printf("Lowercase string = %s\n", strlwr(lower));
                break;

            case 3:
                strcpy(upper, str1);
                printf("Uppercase string = %s\n", strupr(upper));
                break;

            case 4:
                strcpy(reverse, str1);
                strrev(reverse);
                printf("Reversed string = %s\n", reverse);
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please enter correct operation.\n");
        }
    }

    return 0;
}
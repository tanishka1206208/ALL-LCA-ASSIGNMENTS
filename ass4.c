#include <stdio.h>

int main()
{
    int A[2][2], B[2][2], result[2][2];
    int i, j, k, choice;

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    /* Repeat only until a valid choice is entered */
    do
    {
        printf("\nChoose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice < 1 || choice > 3);

    switch (choice)
    {
        case 1:
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    result[i][j] = A[i][j] + B[i][j];
                }
            }

            printf("\nAddition Result:\n");
            break;

        case 2:
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    result[i][j] = A[i][j] - B[i][j];
                }
            }

            printf("\nSubtraction Result:\n");
            break;

        case 3:
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    result[i][j] = 0;

                    for (k = 0; k < 2; k++)
                    {
                        result[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            printf("\nMultiplication Result:\n");
            break;
    }

    printf("\nResult:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
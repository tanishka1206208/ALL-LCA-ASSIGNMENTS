#include <stdio.h>

int main()
{
    float number, sum = 0, average;
    int i;

    printf("Enter 5 numbers:\n");

    for (i = 1; i <= 5; i++)
    {
        scanf("%f", &number);
        sum = sum + number;
    }

    average = sum / 5;

    printf("Average = %.2f\n", average);

    return 0;
}
#include <stdio.h>
#include <string.h>


void multiplyString(char num[], int factor) 
{
    int len = strlen(num);
    int carry = 0;

    
    for (int i = len - 1; i >= 0; i--) 
    {
        int digit = num[i] - '0';
        int product = digit * factor + carry;

        num[i] = (product % 10) + '0';
        carry = product / 10;
    }

    
    while (carry) 
    {
        int len_str = strlen(num);

        
        for (int i = len_str; i >= 0; i--) 
        {
            num[i + 1] = num[i];
        }

        num[0] = (carry % 10) + '0';
        carry /= 10;
    }
}

void factorialStringRecursive(int N, char fact[]) 
{

    if (N <= 1) 
    {
        strcpy(fact, "1");
        return;
    }


    factorialStringRecursive(N - 1, fact);
    multiplyString(fact, N);
}

int main() 
{
    int n;
    char fact[40000];

    printf("Enter a number: ");

    if (scanf("%d", &n) != 1 || n < 0) 
    {
        printf("Invalid Input! Please enter a valid non-negative integer.\n");
        return 1;
    }

    factorialStringRecursive(n, fact);

    printf("Factorial of %d is:\n%s\n", n, fact);

    return 0;
}
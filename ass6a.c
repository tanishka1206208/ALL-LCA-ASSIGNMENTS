#include <stdio.h>
long long factorial(int n)
{
    if(n==1 || n==0)
    return 1;
    else
    return n*factorial(n-1);
}

int main() 
{
    int n;
    printf("Enter a number=");
    scanf("%d",&n);
    if (n<0)
    printf("Factorial cannot be negative.\n");
    else
    printf("Factorial is=%lld",factorial(n));
    return 0;
}
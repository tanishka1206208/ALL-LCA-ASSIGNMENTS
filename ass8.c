#include<stdio.h>

int main()
{
	int a,b,c;
	int *p;
	int *q;
	printf("Enter two numbers: ");
	scanf("%d %d",&a,&b);
	printf("Before swapping:\na=%d\tb=%d\n",a,b);
	p=&a;
	q=&b;
	c=*p;
	*p=*q;
	*q=c;
	printf("After swapping\na=%d\tb=%d",a,b);
	return 0;
}
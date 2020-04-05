#include<stdio.h>

int factorial(int);

int main()
{
	int  n;
	scanf("%d", &n);
	printf("%d", factorial(n));
	return 0;
};

int factorial(int n)
{
	int a=n;
	for(n; n>1; n--)
	{
		a=a*(n-1);
	}
	return a;
};
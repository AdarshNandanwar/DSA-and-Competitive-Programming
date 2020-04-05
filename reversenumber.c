#include<stdio.h>

int main()
{
	int number, a = 0;
	printf("Enter a number to reverse: ");
	scanf("%d", &number);
	while(number!= 0)
	{
		a = a * 10 + (number % 10);
		number /= 10;
	}
	printf("%d", a);
	return 0;
}

#include <stdio.h>

int main()
{
	int X;
	float Y;
	scanf("%d %f", &X, &Y);
	if (X%5==0 && (X+0.5)<=Y)
		printf("%f\n", Y-X-0.5);
	else
		printf("%f\n", Y);
	return 0;
}
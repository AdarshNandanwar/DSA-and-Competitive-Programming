#include<stdio.h>
int main()
{
	int a=5,c;
	int b=2,d;
	double e;
	c=a%b;
	d=a%b;
	printf("%d %d\n", c, d);
	e=(double)a/b;
	d=(double)a/b;
	printf("%f %d\n", e, d);
	e=(a/b);
	d=(a/b);
	printf("%f %d", e, d);
	return 0;
}

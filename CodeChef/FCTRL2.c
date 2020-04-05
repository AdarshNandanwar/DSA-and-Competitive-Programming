#include<stdio.h>

double factorial(int);

int main()
{
	int  N, n[100];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &n[i]);
	}

	// for (int i = 0; i < N; ++i)
	// {
	// 	printf("%lf\n", factorial(n[i]));
	// }

	for (int i = 0; i < N; ++i)
	{
		double a=n[i];
		for(n[i]; n[i]>1; n[i]--)
		{
			a=a*(n[i]-1);
		}
		printf("%lf\n", a);
	}

	
	return 0;
};

// double factorial(int n)
// {
// 	if(n==0) return 1;
// 	double a=n;
// 	for(n; n>1; n--)
// 	{
// 		a=a*(n-1);
// 	}
// 	return a;
// };
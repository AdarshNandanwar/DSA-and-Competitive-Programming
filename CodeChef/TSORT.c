#include <stdio.h>

int main()
{
	long t, N[1000000];
	scanf("%ld", &t);
	for (long i = 0; i < t; ++i)
	{
		scanf("%ld", &N[i]);
	}
	for (long j = 0; j < t; ++j)
	{
		for (long i = 0; i < t-j; ++i)
		{
			if (N[i+1]<N[i])
			{
				N[i+1]=N[i]+N[i+1];
				N[i]=N[i+1]-N[i];
				N[i+1]=N[i+1]-N[i];
			}
		}
	}
	for (long i = 0; i < t; ++i)
	{
		printf("%ld", N[i]);
	}
}
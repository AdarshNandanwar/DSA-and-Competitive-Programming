#include<stdio.h>
int main()
{
	unsigned long N,K;
	scanf("%lu %lu",&N,&K);
	if(N<=K)
		printf("1\n");
	else
	{
		unsigned long a[200000],s=0,e=K;
		for (unsigned long i = 0; i < K; ++i)
		{
			a[i]=1;
		}
		while(N>e)
		{
			a[e]=0;
			for (unsigned long i = s; i < e; ++i)
			{
				a[e]+=a[i]%1000000007;
			}
			s++;
			e++;
		}
		printf("%lu\n", (a[e-1])%1000000007);
	}
	return 0;
}
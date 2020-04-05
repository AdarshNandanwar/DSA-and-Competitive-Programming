#include <stdio.h>

int main()
{
	long n, k, t, count=0;
	scanf("%ld %ld", &n, &k);
	for (long i = 0; i < n; ++i)
	{
		scanf("%ld", &t);
		if(t%k==0)
			count++;
	}
	printf("%ld", count);

	return 0;
}
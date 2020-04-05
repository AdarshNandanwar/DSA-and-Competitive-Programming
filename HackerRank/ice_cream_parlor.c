#include<stdio.h>

int main()
{
	int t,n;
	scanf("%d", &t);
	while(t--)
	{
		int m, n, cost[10000];
		scanf("%d %d", &m, &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &cost[i]);
		for (int i = 1; i <= n; ++i)
			for (int j = i+1; j <= n; ++j)
				if ((cost[i]+cost[j])==m)
					printf("%d %d\n", i, j);
	}
	return 0;
}
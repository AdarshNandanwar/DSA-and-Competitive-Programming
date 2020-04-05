#include <stdio.h>

int main()
{
	// int T, D, d, p[100], t, Q, dead[100], req[100], sum[32];
	int T, D, d, p[100], t, Q, dead, req, sum[32];

	scanf("%d", &T);
	for (int j = 0; j < T; ++j)
	{
		for (int i = 0; i < 32; ++i)
			p[i]=0;
		scanf("%d", &D);
		for (int i = 0; i < D; ++i)
		{
			scanf("%d %d", &d, &t);
			p[d]=t;
		}

		sum[0]=0;
		for (int i = 0; i < 31; ++i)
			sum[i+1]=sum[i]+p[i+1];

		scanf("%d", &Q);
		// for (int i = 0; i < Q; ++i)
		// 	scanf("%d %d", &dead[i], &req[i]);

		// for (int i = 0; i < Q; ++i)
		// 	if (sum[dead[i]]>=req[i])
		// 		printf("Go Camp\n");
		// 	else
		// 		printf("Go Sleep\n");

		for (int i = 0; i < Q; ++i)
		{
			scanf("%d %d", &dead, &req);
			if (sum[dead]>=req)
				printf("Go Camp\n");
			else
				printf("Go Sleep\n");
		}
	}

	return 0;
}
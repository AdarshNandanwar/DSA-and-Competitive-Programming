#include <stdio.h>

int main()
{
	int T, N, index=1, p=1;
	long U, D, H[101];
	scanf("%d", &T);
	for (int j = 0; j < T; ++j)
	{
		scanf("%d %ld %ld", &N, &U, &D);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%ld", &H[i]);
		}

		for (int i = 1; i < N; ++i)
		{
			if ((H[i+1]-H[i])<=U && (H[i+1]-H[i])>=(-D))
			{
				index++;
			}
			else if (p==1 && (H[i+1]-H[i])<(-D))
			{
				p=0;
				index++;
			}
			else
				break;
		}
		printf("%d", index);
		index=1;
	}
	return 0;
}
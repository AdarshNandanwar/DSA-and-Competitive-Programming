#include<stdio.h>
int main()
{
	int a[100][100], n, m;
	printf("Enter the n and m value of n x m matrix: ");
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
		
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
		
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int f=0;
			for(int I = 0; I < n; I++)			//min in col, max in row STRICTLY
			{
				if (a[i][j] >= a[I][j])
					f=1;
			}
			for(int J = 0; J < m; J++)
			{
				if (a[i][j] <= a[i][J])
					f=1;
			}

			if (f==0) {
				printf("%d ", a[i][j]);
			}
			
			f=0;
			for(int I = 0; I < n; I++)			//max in col, min in row STRICTLY
			{
				if (a[i][j] <= a[I][j])
					f=1;
			}
			for(int J = 0; J < m; J++)
			{
				if (a[i][j] >= a[i][J])
					f=1;
			}

			if (f==0) {
				printf("%d ", a[i][j]);
			}
			
		}
		
	}
	printf("\n");
	return 0;
}

#include<stdio.h>
int main()
{
	int n, a[1000];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}

	//Insertion Sort
	int min,j;
	for (int i = 1; i < n; ++i)
	{
		j=i+1;
		min=a[j];
		while(a[j-1]>min && j>1)
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=min;
		for (int i = 1; i <= n; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}
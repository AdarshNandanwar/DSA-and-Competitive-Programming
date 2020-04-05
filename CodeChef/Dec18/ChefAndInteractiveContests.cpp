#include<stdio.h>

int main()
{
	int N,r,i,a[1000];
	scanf("%d %d", &N, &r);
	for (i=0;i<N;i++)
	{
		scanf("%d", &a[i]);
	}
	for (i=0;i<N;i++)
	{
		if(a[i]<r)
			printf("Bad boi\n");
		else
			printf("Good boi\n");
	}
	return 0;
}
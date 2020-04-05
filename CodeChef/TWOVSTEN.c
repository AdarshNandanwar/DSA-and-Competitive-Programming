#include<stdio.h>
int main()
{
	int T,X;
	scanf("%d",&T);
	for(int i=0; i<T; i++)
	{
		scanf("%d",&X);
		if(X%5==0)
			if(X%2==0)
				printf("0\n");
			else
				printf("1\n");
		else
			printf("-1\n");
	}
	return 0;
}
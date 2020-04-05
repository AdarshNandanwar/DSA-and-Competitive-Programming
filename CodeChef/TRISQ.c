#include<stdio.h>
int main()
{
	int T,B,sum;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		sum=0;
		scanf("%d",&B);
		for(int j=B;j>=4;j=j-2)
		{
			sum=sum+((j-2)/2);
		}
		printf("%d\n",sum);
	}
	return 0;
}
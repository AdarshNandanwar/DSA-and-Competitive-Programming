#include<stdio.h>
int main()
{
	int t,n,c,sum;
	scanf("%d",&t);
	for(int i=0; i<t; i++)
	{
		sum=0;
		scanf("%d",&n);
		for(int j=0; j<n; j++)
		{
			scanf("%d",&c);
			sum+=c;
		}
		if(sum%2==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
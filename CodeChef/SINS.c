#include<stdio.h>
int main()					//Time limit exceeded error
{
	int T;
	int X,Y;
	scanf("%d",&T);
	for(int k=0;k<T;k++)
	{
		scanf("%d %d",&X,&Y);
		while(X!=Y && X!=0 && Y!=0)
		{
			if(X>Y)
				X-=Y;
			else
				Y-=X;
		}
		printf("%d\n",X+Y);
	}
	return 0;
}
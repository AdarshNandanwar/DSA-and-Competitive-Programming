#include<stdio.h>					//Time limit exceeded
int check_spam(int, int, int [], int []);
int main()
{
	int T,N,minX,maxX;
	scanf("%d",&T);
	while(T>0)
	{
		int w[100000],b[100000],spam=0,notspam=0;
		scanf("%d %d %d",&N,&minX,&maxX);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d",&w[i],&b[i]);
		}
		for (int i = minX; i <= maxX; ++i)
		{
			if(check_spam(i,N,w,b))
				spam++;
			else
				notspam++;
		}
		printf("%d %d\n",notspam,spam);
		T--;
	}
	return 0;
}
int check_spam(int user, int N, int w[], int b[])
{
	for (int i = 0; i < N; ++i)
	{
		user=(user*w[i])+b[i];
	}
	if(user%2==1)
		return 1;
	else
		return 0;
}
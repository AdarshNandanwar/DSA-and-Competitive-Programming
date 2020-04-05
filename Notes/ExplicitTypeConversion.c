#include<stdio.h>
#include<math.h>
int main()
{
	int T,X1,X2,X3,V1,V2;
	float T1,T2;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d %d %d %d %d",&X1,&X2,&X3,&V1,&V2);
		T1=fabs((float)(X3-X1)/V1);
		T2=fabs((float)(X3-X2)/V2);
		if(T1>T2)
			printf("Kefa\n");
		else
			if(T1<T2)
				printf("Chef\n");
			else
				printf("Draw\n");
	}
	return 0;
}
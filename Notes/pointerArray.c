#include<stdio.h>
int main()
{
	int n, *a;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", *(a + i));
	}
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%p ", (void*)(a + i));
	}

	// int *t,*s;
	// for (int i = 0; i < n; ++i)
	// {
	// 	t=*(a+i);
	// 	s=*(a+n-1-i);
	// 	*(a+i)=s;
	// 	*(a+n-1-i)=t;
	// }
	// for (int i = 0; i < n; ++i)
	// {
	// 	printf("%d ", *(a + i));
	// }
	// printf("\n");
	// for (int i = 0; i < n; ++i)
	// {
	// 	printf("%p ", (void*)(a + i));
	// }

	return 0;
}
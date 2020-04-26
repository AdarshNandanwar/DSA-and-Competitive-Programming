#include<stdio.h>

int main()
{
	int a[100], n, b;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("Enter sorted array:\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter the sum of the 2 numbers: ");
	scanf("%d", &b);

	int l=0, h=n-1, s, f=0;
	while(l<h)
	{
		s=a[l]+a[h];
		if (s>b)
			h--;
		else if (s<b)
			l++;
		else
		{
			printf("The 2 elements are %d and %d.\n", a[l], a[h]);
			h--;
			l++;
			f=1;
		}
	}
	if (f==0)
		printf("No such elements found.\n");
	return 0;
}
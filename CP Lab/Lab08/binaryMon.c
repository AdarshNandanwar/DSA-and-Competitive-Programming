#include<stdio.h>
int main()
{
	int a[100],n,x;
	printf("Enter number of elements in the array:");
	scanf("%d", &n);
	printf("Enter the sorted array:\n");
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	printf("Enter the sum of digits of the required number: \n");
	scanf("%d", &x);

	int sa[100];
	for (int i = 0; i < n; ++i)
	{
		sa[i]=0;
		int temp, e=a[i];
		while(e!=0)
		{
			temp=e%10;
			sa[i]+=temp;
			e/=10;
		}
	}
	int mid, low=0, high=n-1;
	while(low<=high)
	{
		mid=(low+high)*0.5;
		if (sa[mid]<x)
			low=mid+1;
		else if (sa[mid]>x)
			high=mid-1;
		else if (sa[mid]==x)
		{
			printf("\nThe required element is: %d\n", a[mid]);
			return 0;
		}
	}
	printf("\nElement not found!");
	return 0;
}

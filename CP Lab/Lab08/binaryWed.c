#include<stdio.h>

int main()
{
	int a[100],n;
	printf("Enter number of elements in the array:");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}

	//Code to check for valid ascending and then descending array

	int f=0;
	for (int i = 0; i < n-1; ++i)
	{
		if (a[i+1]>a[i] && f==0)
			continue;
		else if (a[i+1]>a[i] && f==1)
		{
			f=2;
			break;
		}
		else if (a[i+1]<a[i] && f==0)
			f=1;
		else if (a[i+1]<a[i] && f==1)
			continue;
	}
	if (a[0]>a[1])
		f=2;
	if (f==2 || f==0)
	{
		printf("Invalid array input!\n");
		return 0;
	}

	//Code to find the maximum element int the array by binary search

	int l=0, h=n-1, m;
	while(l<=h)
	{
		m=(l+h)*0.5;
		if (a[m-1]<a[m] && a[m]<a[m+1])
			l=m+1;
		else if (a[m-1]>a[m] && a[m]>a[m+1])
			h=m-1;
		else 					//logic fails when array has 3 consecutive same elements
			break;
	}
	printf("Maximum element is %d at the position %d.\n", a[m], m+1);
	return 0;
}

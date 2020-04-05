#include<stdio.h>
int main()
{
	//code to take input of a character array
	int n;
	char a[100];
	printf("Enter the number of array elements: ");
	scanf("%d", &n);
	printf("Enter the elements of the array: ");
	for(int i=0; i<n; i++)
	{
		scanf(" %c", &a[i]);	//its very important to have a space before %c
	}
	printf("The entered elements of the array are: ");
	for(int i=0; i<n; i++)
	{
		printf("%c ", a[i]);
	}
	printf("\n");
	return 0;
}

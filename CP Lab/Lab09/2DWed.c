#include<stdio.h>
int main()
{
	int a[100][100], n, m, temp;
	printf("Enter the n and m value of n x m matrix: ");
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
		
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
		
	}

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i][m-1] > a[j][m-1])
            {
                for(int k = 0; k < m; k++)
                {
                    temp=a[i][k];
                    a[i][k]=a[j][k];
                    a[j][k]=temp;
                }
            }
        }
        
    }
    
	printf("\n");

    	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
		
	}
   	printf("\n");

	return 0;
}

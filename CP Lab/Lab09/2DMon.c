#include<stdio.h>
int main()
{
    int n, num, a[100][100], b[100][100], m, k=0;
    printf("Enter the size n of the square matrix nxn: ");
    scanf("%d", &n);
    for(int  i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            a[i][j]=0;
            b[i][j]=0;
        }
        
    }

    //array a
    
    printf("Enter the elements of first array: \n");
    for(int  i = 0; i < n*n; i++)
    {
        scanf("%d", &num);
        m=num%n;
        a[m][a[m][n]]=num;
        a[m][n]++;
    }
    
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

    //array b

    printf("Enter the elements of second array: \n");
    for(int  i = 0; i < n*n; i++)
    {
        scanf("%d", &num);
        m=num%n;
        b[m][b[m][n]]=num;
        b[m][n]++;
    }
    
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

    //check for permutation

    int flag;
    while(k<n)
    {
        for(int i = 0; i < n; i++)
        {
            flag=0;
            for(int j = 0; j < n; j++)
            {
                if(a[k][i]==b[k][j])
                    flag=1;
            }
            if(flag==0)
            {
                printf("\nThe first matrix is not the premutation of second matrix\n");
                return 0;
            }
        }
        k++;
    }

    printf("\nThe first matrix is the premutation of second matrix\n");
    return 0;
}
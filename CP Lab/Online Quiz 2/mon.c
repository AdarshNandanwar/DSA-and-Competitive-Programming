#include<stdio.h>
int isprime(int);
int lcm(int, int);
int ithprime(int);

int main()
{
    int m,n,k,a[100][100];
    printf("\nEnter the values of m, n, k: ");
    scanf("%d %d %d", &m, &n, &k);

    if(isprime(k)) printf("Prime");else printf("Not prime");

    printf("\nEnter the values of the mxn matrix: ");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
        
    }

    for(int i = 0; i < m; i++)
    {
        printf("\n");
        for(int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        
    }
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            a[i][j]=lcm(a[i][j-1],a[i][j]);
        }
        
    }
    

    printf("\nLCM matrix: ");
    for(int i = 0; i < m; i++)
    {
        printf("\n");
        for(int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j]=ithprime(a[i][j]);
        }
        
    }
    
    printf("\nFinal matrix: ");
    for(int i = 0; i < m; i++)
    {
        printf("\n");
        for(int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        
    }

    printf("\n");
    return 0;
}

int isprime(int k)
{
    int f=1;
    for(int i = 2; i <= k/2; i++)
    {
        if(k%i==0)
            f=0;
    }
    return f;
}

int lcm(int a , int b)
{
    int l=a;
    while(!((l%a)==0 && (l%b)==0))
        l++;
    return l;
}

int ithprime(int k)
{
    int n=2, count=1;
    while(count<k)
    {
        n++;
        while(!(isprime(n)))
            n++;
        count++;
    } 
    return n;
}
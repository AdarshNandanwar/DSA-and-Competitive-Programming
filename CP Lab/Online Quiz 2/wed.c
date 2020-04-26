#include<stdio.h>
int minor(int, int, int[3][3]);
void allminor(int [3][3], int [3][3]);
void cofactor_transpose(int a[3][3], int b[3][3]);

int main()
{
    int a[3][3];
    printf("Enter the valude os the 3x3 matrix: ");
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            scanf("%d", &a[i][j]);
    
    printf("\nThe entered matrix is: ");
    for(int i=0; i<3; i++)
    {
        printf("\n");
        for(int j=0; j<3; j++)
            printf("%d ", a[i][j]);
    }

    int b[3][3];
    allminor(a,b);

    cofactor_transpose(a,b);

    printf("\n");
    return 0;
}

int minor(int x, int y, int a[3][3])
{
    int i=x, j=y;
    int p,q,r,s;
    if((x+1)<3)
        x++;
    else
        x-=2;
    if((y+1)<3)
        y++;
    else
        y-=2;
    p=a[x][y];

    if((x+1)<3)
        x++;
    else
        x-=2;
    q=a[x][y];
                
    if((y+1)<3)
        y++;
    else
        y-=2;
    s=a[x][y];

    x=i;
    y=j;
    if((x+1)<3)
        x++;
    else
        x-=2;
    if((y+2)<3)
        y+=2;
    else
        y-=1;
    r=a[x][y];

    int minor=(p*s-q*r);
    if((i+j)%2==1)
        minor*=(-1);
    return minor;
}

void allminor(int a[3][3],int b[3][3])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
           b[i][j]=minor(i,j,a);

    printf("\nThe minor matrix is: ");
    for(int i=0; i<3; i++)
    {
        printf("\n");
        for(int j=0; j<3; j++)
            printf("%d ", b[i][j]);
    }
}

void cofactor_transpose(int a[3][3], int b[3][3])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if((i+j)%2==1)
            b[i][j]*=(-1);
        }

    int det=a[0][0]*b[0][0]+a[0][1]*b[0][1]+a[0][2]*b[0][2];
    printf("\nThe determinant of the entered matrix is: %d", det);

    for(int i=0; i<3; i++)
        for(int j=(i+1); j<3; j++)
        {
            int temp=b[i][j];
            b[i][j]=b[j][i];
            b[j][i]=temp;
        }
    printf("\nThe cofactor transpose matrix is: ");
    for(int i=0; i<3; i++)
    {
        printf("\n");
        for(int j=0; j<3; j++)
            printf("%d ", b[i][j]);
    }
}
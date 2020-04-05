#include<stdio.h>

void swap(int *, int *);
int max_element(int [], int );
void sort_array(int [], int);

int main()
{

    //call by reference
    int x, y;
    printf("Enter any 2 numbers: ");
    scanf("%d %d", &x, &y);
    printf("x=%d\ny=%d", x, y);
    swap(&x, &y);
    printf("\nAfter swapping\nx=%d\ny=%d", x, y);

    //passing array
    int n, a[100];
    printf("\n\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nMaximum element of the entered array is: %d", max_element(a,n));

    //function to show that array call is always by reference
    sort_array(a, n);
    printf("\nThe sorted array is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int max_element(int arr[], int n)
{
    int max=arr[0];
    for(int i=0; i<n ;i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    return max;
}

void sort_array(int arr[], int n)
{
    for(int i=0; i<n ; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
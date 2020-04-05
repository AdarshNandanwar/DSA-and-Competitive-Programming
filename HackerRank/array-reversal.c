#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, *temp;
    scanf("%d", &num);
    int arr[1000];
    for(i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    for(int j=0; j<num/2; j++)
    {
        temp=arr[j];
        arr[j]=arr[num-j-1];
        arr[num-j-1]=temp;
    }
    /* Write the logic to reverse the array. */

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}


#include<stdio.h>
#include<stdlib.h>

int main(){
    int * arr = (int *) malloc(10*sizeof(int));
    for(int i = 0; i<10; i++){
        arr[i] = i;
    }
    int i = 5;
    printf("%d %d %d\n", *(arr+i), arr[i], i[arr]);

}
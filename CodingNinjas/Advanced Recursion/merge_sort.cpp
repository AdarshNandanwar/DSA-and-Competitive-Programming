// Merge Sort Code
// Send Feedback
// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.
// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 1000
// Sample Input:
// 6 
// 2 6 8 5 4 3
// Sample Output:
// 2 3 4 5 6 8


#include<bits/stdc++.h>
using namespace std;

void merge(int* input, int start, int mid, int end){
    int* arr = new int[end-start+1];
    int i=start, j=mid+1, k=0;
    while(i<=mid && j<=end){
        if(input[i]<input[j]){
            arr[k++]=input[i++];
        }else{
            arr[k++]=input[j++];
        }
    }
    while(i<=mid){
        arr[k++]=input[i++];
    }
    while(j<=end){
        arr[k++]=input[j++];
    }
    for(int i=0; i<k; i++){
        input[start++]=arr[i];
    }
    delete[] arr;
}

void recurse_merge(int * input, int start, int end){
    if(start>=end){
        return;
    }
    int mid=start+((end-start)/2);
    recurse_merge(input, start, mid);
    recurse_merge(input, mid+1, end);
    merge(input, start, mid, end);
    return;
}

void mergeSort(int input[], int size){
	// Write your code here
     recurse_merge(input, 0, size-1);   
}

int main(){
    int n;
    cin>>n;
    int* arr= new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";;
    }
    
    delete[] arr;
    return 0;
}
// Quick Sort Code
// Send Feedback
// Sort an array A using Quick Sort.
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

void swap (int & a, int & b){
    int temp = b;
    b=a;
    a=temp;
}

int partition(int * input, int start, int end){
    int count=0;
    for(int i=start+1; i<=end; i++){
        if(input[i]<input[start]){
            count++;
        }
    }

    swap(input[start+count], input[start]);

    int i=start, j=start+count+1;
    while(i<start+count && j<=end){
        if(input[i]<input[start+count]){
            i++;
        }else if(input[j]>=input[start+count]){
            j++;
        }else{
            swap(input[i++], input[j++]);
        }
    }

    return start+count;
}

void quick_recurse(int * input, int start, int end){
    if(start>=end){
        return;
    }
    int pos=partition(input, start, end);
    quick_recurse(input, start, pos-1);
    quick_recurse(input, pos+1, end);
    return;
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    quick_recurse(input, 0, size-1);
}

int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quickSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    delete[] arr;
    
    return 0;
}
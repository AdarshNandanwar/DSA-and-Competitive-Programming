#include<bits/stdc++.h>
using namespace std;

// BINARY SEARCH APPROACH
// int main(){
//     int n, k;
//     cin>>n>>k;
//     int* arr = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }

//     sort(arr, arr+n);
//     int count=0;
//     for (int i = 0; i < n; i++)
//     {
//         int lower = lower_bound(arr+i+1, arr+n, arr[i]+k)-arr;
//         count+=(n-lower);
//     }
//     cout<<count;
//     delete[] arr;
//     return 0;
// }

//TWO POINTER APPROACH
// int main(){
//     int n, k;
//     cin>>n>>k;
//     int* arr = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }

//     sort(arr, arr+n);
//     int count=0;
//     int* i=arr;
//     int* j=arr+1;
//     while(i<arr+n && j<arr+n){
//         if(*j-*i>=k){
//             i++;
//             count+=(&arr[n-1]-j+1);
//         }else{
//             j++;
//         }
//     }
//     cout<<count;
//     delete[] arr;
//     return 0;
// }

//TWO INDEX APPROACH
int main(){
    int n, k;
    cin>>n>>k;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr+n);
    int count=0, i=0, j=1;
    while(i<n && j<n){
        if(arr[j]-arr[i]>=k){
            i++;
            count+=(n-j);
            cout<<count<<endl;
        }else{
            j++;
        }
    }
    cout<<count;
    delete[] arr;
    return 0;
}
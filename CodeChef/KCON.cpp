#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadanes(int* arr, int n){
    ll max_sum=INT_MIN, sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        max_sum=max(max_sum, sum);
        if(sum<0){
            sum=0;
        }
    }
    return max_sum;
}

ll subarray_start(int* arr, int n){
    ll max_sum=INT_MIN, sum=0;
    for (int i = n-1; i >=0 ; i--)
    {
        sum+=arr[i];
        max_sum=max(max_sum, sum);
    }
    return max_sum;
    // if(max_sum>0){
    //     return max_sum;
    // }else{
    //     return 0;
    // }
}

ll subarray_end(int* arr, int n){
    ll max_sum=INT_MIN, sum=0;
    for (int i = 0; i<n ; i++)
    {
        sum+=arr[i];
        max_sum=max(max_sum, sum);
    }
    return max_sum;
    // if(max_sum>0){
    //     return max_sum;
    // }else{
    //     return 0;
    // }
}

ll arr_sum(int* arr, int size){
    ll sum=0;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

ll find_max_sum(int* arr, int size, int k){
    ll sum = arr_sum(arr,size);
    if(k==1){
        return kadanes(arr, size);
    }
    if(sum>0){
        return max(subarray_start(arr,size)+subarray_end(arr,size)+(k-2)*sum, kadanes(arr, size));
    }else{
        return max(kadanes(arr, size), subarray_start(arr, size)+subarray_end(arr, size));
    }
}

int main(void){
    int n, k, t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int* arr = new int[n];
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<find_max_sum(arr, n, k)<<endl;
        delete[] arr;
    }
    return 0;
}
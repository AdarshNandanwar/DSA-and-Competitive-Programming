#include<bits/stdc++.h>
using namespace std;

int maximum_product_subarray(int* arr, int n){
    int pos_prod=1, neg_prod=1, max_prod=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>0){
            pos_prod*=arr[i];
            neg_prod=min(1, neg_prod*arr[i]);
        }else if(arr[i]<0){
            int temp=pos_prod;
            pos_prod=min(1, neg_prod*arr[i]);
            neg_prod=temp*arr[i];
        }else{
            pos_prod=1;
            neg_prod=1;
        }
        max_prod=max(max_prod, pos_prod);
    }
    return max_prod;
}

int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<maximum_product_subarray(arr, n);

    return 0;
}
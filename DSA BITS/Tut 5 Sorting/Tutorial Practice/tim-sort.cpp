#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void insertion_sort(ll * arr, ll n){
    for (ll i = 1; i < n; i++)
    {
        ll temp = arr[i];
        ll j = i-1;
        while(j >= 0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void combine(ll * arr, ll l, ll m, ll r){
    ll l_size = m-l+1;
    ll r_size = r-m;
    ll * left = new ll[l_size+1];
    ll * right = new ll[r_size+1];
    left[l_size] = INT_MAX;
    right[r_size] = INT_MAX;
    for (ll i = 0; i < l_size; i++)
    {
        left[i] = arr[l+i];
    }
    for (ll i = 0; i < r_size; i++)
    {
        right[i] = arr[m+1+i];
    }
    
    ll i = l, j = 0, k = 0;
    while(i <= r){
        if(left[j] < right[k]){
            arr[i] = left[j];
            j++;
        } else {
            arr[i] = right[k];
            k++;
        }
        i++;
    }
    delete [] left, right;
}

void mergeSort(ll * arr, ll l, ll r){
    if(l>=r){
        return;
    }
    ll run = 32;
    if(r-l+1 < run){
        insertion_sort(arr+l, r-l+1);
    } else {
        ll m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        combine(arr, l, m, r);
    }
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for (ll i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete [] arr;
    
    return 0;
}
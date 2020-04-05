#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inversion_count = 0;

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
    ll less_count = 0;
    while(i <= r){
        if(left[j] <= right[k]){
            arr[i] = left[j];
            // inversion_count += less_count;
            less_count = 0;
            j++;
        } else {
            arr[i] = right[k];
            // less_count++;
            inversion_count += (m-l);
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
    ll m = l+(r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    combine(arr, l, m, r);
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

    cout<<inversion_count<<endl;

    delete [] arr;
    
    return 0;
}
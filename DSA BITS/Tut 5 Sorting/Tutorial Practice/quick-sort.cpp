#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(ll & a, ll & b){
    ll temp = a;
    a = b;
    b = temp;
}

ll partition(ll * arr, ll l, ll r){
    ll pivot = arr[r];
    ll i = l;
    for (ll j = l; j < r; j++)
    {
        if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

void quickSort(ll * arr, ll l, ll r){
    if(l>=r){
        return;
    }
    ll m = partition(arr, l, r);
    quickSort(arr, l, m-1);
    quickSort(arr, m+1, r);
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

    quickSort(arr, 0, n-1);

    for (ll i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete [] arr;
    
    return 0;
}
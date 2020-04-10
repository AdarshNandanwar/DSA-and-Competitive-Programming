#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(ll * arr, ll n){

    
    ll max_len = 1, len = 1;
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] > arr[i-1]){
            len++;
        } else if(arr[i] < arr[i-1]){
            max_len = max(max_len, len);
            len = 1;
        }
    }
    max_len = max(max_len, len);
    len = 1;

    ll count_inc = 0;
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] > arr[i-1]){
            len++;
        } else if(arr[i] < arr[i-1]){
            if(max_len == len){
                count_inc++;
            }
            len = 1;
        }
    }
    if(max_len == len){
        count_inc++;
    }
    len = 1;

    // cout<<max_len<<" "<<count_inc<<endl;

    max_len = 1; len = 1;
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] < arr[i-1]){
            len++;
        } else if(arr[i] > arr[i-1]){
            max_len = max(max_len, len);
            len = 1;
        }
    }
    max_len = max(max_len, len);
    len = 1;

    ll count_dec = 0;
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] < arr[i-1]){
            len++;
        } else if(arr[i] > arr[i-1]){
            if(max_len == len){
                count_dec++;
            }
            len = 1;
        }
    }
    if(max_len == len){
        count_dec++;
    }
    len = 1;

    // cout<<max_len<<" "<<count_dec<<endl;

    return count_inc == count_dec;
}

int main(){
    ll n, q;
    cin>>n>>q;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    while(q--){
        ll l, r;
        cin>>l>>r;
        l--; r--;
        cout<<(solve(arr+l, r-l+1)?"YES\n":"NO\n");
    }
    
    delete [] arr;

    return 0;
}
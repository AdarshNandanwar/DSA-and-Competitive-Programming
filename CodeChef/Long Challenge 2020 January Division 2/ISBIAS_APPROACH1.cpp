#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(ll * arr, ll l, ll r){
    map<ll, ll> inc, dec;
    ll max_inc = 0, max_dec = 0;

    ll length = 1;
    for (ll i = l+1; i <= r; i++)
    {
        if(arr[i] > arr[i-1]){
            length++;
        } else {
            max_inc = max(max_inc, length);
            inc[length]++;
            length = 1;
        }
    }
    max_inc = max(max_inc, length);
    inc[length]++;

    length = 1;
    for (ll i = l+1; i <= r; i++)
    {
        if(arr[i] < arr[i-1]){
            length++;
        } else {
            max_dec = max(max_dec, length);
            dec[length]++;
            length = 1;
        }
    }
    max_dec = max(max_dec, length);
    dec[length]++;
    cout<<"inc["<<max_inc<<"] "<<inc[max_inc]<<endl<<"dec["<<max_dec<<"] "<<dec[max_dec]<<endl;
    return inc[max_inc] == dec[max_dec];
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
        if(solve(arr, l, r)) cout<<"YES\n"; else cout<< "NO\n";
    }
    
    return 0;
}
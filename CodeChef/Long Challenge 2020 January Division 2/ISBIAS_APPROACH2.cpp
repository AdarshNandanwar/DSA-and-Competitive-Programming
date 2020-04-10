#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(ll * inc_end, ll * dec_end, ll l, ll r){

    ll * inc_lim = new ll[r-l+1];    
    ll * dec_lim = new ll[r-l+1];
    ll length = 1, max_inc = 0, max_dec = 0;
    map<ll, ll> inc_map, dec_map;
    for (ll i = 0; i < r-l+1; i++)
    {
        inc_lim[i] = length <= inc_end[i+l] ? length: inc_end[i+l];
        dec_lim[i] = length <= dec_end[i+l] ? length: dec_end[i+l];
        inc_map[inc_lim[i]]++;
        dec_map[dec_lim[i]]++;
        max_inc = max(max_inc, inc_lim[i]);
        max_dec = max(max_dec, dec_lim[i]);
        length++;
    }

    delete [] inc_lim;
    delete [] dec_lim;

    // cout<<max_inc<<" "<<inc_map[max_inc]<<endl;
    // cout<<max_dec<<" "<<dec_map[max_dec]<<endl;
    return inc_map[max_inc] == dec_map[max_dec];
}

int main(){
    ll n, q;
    cin>>n>>q;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    ll * inc_end = new ll[n];
    ll * dec_end = new ll[n];
    inc_end[0] = dec_end[0] = 1;
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] > arr[i-1]){
            inc_end[i] = inc_end[i-1]+1;
        } else {
            inc_end[i] = 1;
        }
    }
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] < arr[i-1]){
            dec_end[i] = dec_end[i-1]+1;
        } else {
            dec_end[i] = 1;
        }
    }
    

    while(q--){
        ll l, r;
        cin>>l>>r;
        l--; r--;
        if(solve(inc_end, dec_end, l, r)) cout<<"YES\n"; else cout<< "NO\n";
    }
    
    delete [] arr;
    delete [] inc_end;
    delete [] dec_end;

    return 0;
}
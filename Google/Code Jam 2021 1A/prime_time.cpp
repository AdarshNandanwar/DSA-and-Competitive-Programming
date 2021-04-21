#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll ans = 0;

void helper(unordered_map<ll, ll>::iterator itr, unordered_map<ll, ll> & freq, ll sum, ll prod){
    if(itr == freq.end()){
        if(sum && prod && sum == prod) ans = max(ans, sum);
        return;
    }
    auto cur = *itr;
    itr++;
    for(ll i = 0; i<cur.second; i++){
        helper(itr, freq, sum+(i*cur.first), prod*pow(cur.first, cur.second-i));
        helper(itr, freq, sum+((cur.second-i)*cur.first), prod*pow(cur.first, i));
    }
}

void solve(ll t){

    ans = 0;

    ll m;
    cin>>m;
    unordered_map<ll, ll> freq;
    for(ll i = 0; i<m; i++){
        ll a, b;
        cin>>a>>b;
        freq[a] = b;
    }

    helper(freq.begin(), freq, 0, 1);

    cout<<"Case #"<<t<<": "<<ans<<endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    for(ll i = 1; i<= t; i++){
        solve(i);
    }
    return 0;
}
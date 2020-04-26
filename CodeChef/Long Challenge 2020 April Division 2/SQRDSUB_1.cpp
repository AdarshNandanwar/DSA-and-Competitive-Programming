#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    scanf("%lld", &n);
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        scanf("%lld", &v[i]);
    
    vector<ll> mod_v;
    for(ll i = 0; i<n; i++){
        if(v[i]%4==2){
            mod_v.push_back(i);
        }
    }
    ll count = 0, count1, count2; 
    for(ll i = 0; i<mod_v.size(); i++){
        count1 = 1; 
        for(ll j = mod_v[i]-1; j >= 0; j--){
            if(v[j]%2 != 0){
                count1++;
            } else {
                break;
            }
        }
        count2 = 1;
        for(ll j = mod_v[i]+1; j<n; j++){
            if(v[j]%2 != 0){
                count2++;
            } else {
                break;
            }
        }
        count += count1*count2;
    }
    ll ans = ((n*(n+1))/2) - count;
    printf("%lld\n", ans);
}
 
int main(){

    ll t;
    scanf("%lld", &t);
    while(t--){
        solve();
    }
    return 0;
}
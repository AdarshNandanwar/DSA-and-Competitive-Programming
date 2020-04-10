#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll data;
        cin>>data;
        v.push_back(data);
    }
    vector<ll> mod_v;
    for(ll i = 0; i<n; i++){
        if(v[i]%4==2){
            mod_v.push_back(i);
        }
    }
    ll count = 0, count1, count2; 
    for(ll i = 0; i<mod_v.size(); i++){
        cout<<v[mod_v[i]]<<endl;
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
        cout<<count1<<" "<<count2<<endl;
        count += count1*count2;
    }
    cout<<count<<endl;
    ll ans = ((n*(n+1))/2) - count;
    cout<<ans<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k, ans = 0;
    cin>>n>>k;
    map<ll,ll> m;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        m[temp%k]++;
    }
    if(m[0]>0){
        ans++;
    }
    // cout<<ans<<endl;
    if(k%2){
        for (ll i = 1; i <= k/2; i++)
        {
            ans += m[i] > m[k-i] ? m[i] : m[k-i]; 
        }
    } else {
        for (ll i = 1; i < k/2; i++)
        {
            ans += m[i] > m[k-i] ? m[i] : m[k-i]; 
        }
        if(m[k/2] > 0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
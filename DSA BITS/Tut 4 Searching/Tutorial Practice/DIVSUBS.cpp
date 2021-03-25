#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll b[n+1];
    b[0] = 0;
    map<ll, ll> m;
    ll i;
    for (i = 1; i <= n; i++)
    {
        b[i] = b[i-1] + a[i-1];
        if(m[b[i]%n] != 0){
            break;
        }
        m[b[i]%n] = i;
    }
    cout<<i-m[b[i]%n]<<endl;
    for (ll j = m[b[i]%n]+1; j <= i; j++)
    {
        cout<<j<<" ";
    }
    cout<<endl;
    

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
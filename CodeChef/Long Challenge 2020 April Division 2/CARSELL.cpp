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
    sort(v.begin(), v.end(), greater<ll>());
    ll sum = 0, age = 0;
    for(auto i : v){
        sum = (sum+max((ll)0, i-age))%MOD;
        age++;
    }
    cout<<sum<<endl;
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
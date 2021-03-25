#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    ll m, k;
    cin>>n>>m>>k;
    ll ** ans = new ll*[n];
    for (ll i = 0; i < n; i++)
    {
        unordered_map<ll, ll> m;
        ll maxFreq = -1, maxElement;
        ans[i] = new ll[k];
        for (ll j = 0; j < k; j++)
        {
            cin>>ans[i][j];
            m[ans[i][j]]++;
            if(m[ans[i][j]] > maxFreq){
                maxFreq = m[ans[i][j]];
                maxElement = ans[i][j];
            }
        }
        cout<<maxElement<<" ";
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
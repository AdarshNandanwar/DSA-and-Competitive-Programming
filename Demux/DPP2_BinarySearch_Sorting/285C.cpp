// http://codeforces.com/problemset/problem/285/C

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<int> v(n);
    for(auto & i:v) cin>>i;
    ll res = 0;
    sort(v.begin(), v.end());
    for(int i = 1; i<=n; i++) res += abs(i-v[i-1]);
    cout<<res<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t= 1;
    while(t--){
        solve();
    }
    return 0;
}
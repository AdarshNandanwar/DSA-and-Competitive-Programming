#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef unsigned long long ll;

ll n;

void solve(){

    cin>>n;
    if(n%2050){
        cout<<-1<<endl;return;
    }
    n/=2050;
    ll res = 0;
    while(n){
        res += (n%10);
        n/=10;
    }
    cout<<res<<endl;
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
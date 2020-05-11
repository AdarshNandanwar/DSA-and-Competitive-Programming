#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    ll g_min = a-b;
    ll g_max = a+b;
    ll t_min = c-d;
    ll t_max = c+d;
    // cout<<g_min<<" "<<g_max<<" "<<n*g_min<<" "<<n*g_max<<" "<<t_min<<" "<<t_max<<" "<<endl;
    if(t_min>n*g_max || n*g_min>t_max) cout<<"No\n";
    else cout<<"Yes\n";
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
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll m;
    cin>>n>>m;
    if(n == 1 || m == 1) {
        cout<<"YES"<<endl;
        return ;
    }
    if( n == 2 && m == 2){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n"<<endl;
    return;


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
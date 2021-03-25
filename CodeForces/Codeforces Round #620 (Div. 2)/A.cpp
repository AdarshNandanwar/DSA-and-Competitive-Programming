#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){

    ll x, y, a, b;
    cin>>x>>y>>a>>b;
    if((y-x)%(a+b) == 0){
        cout<<(y-x)/(a+b)<<endl;
    } else {
        cout<<-1<<endl;
    }

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
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef unsigned long long int ll;

ll n;

void solve(){

    ll m, x;
    cin>>n>>m>>x;
    x--;

    ll col_i = x%n;
    ll col_j = x/n;

    cout<<m*col_i+col_j+1<<endl;    

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
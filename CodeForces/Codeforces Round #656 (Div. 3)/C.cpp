#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;

    vector<int> v(n);
    for(auto & i:v) cin>>i;

    int i;
    bool down = false, up = false;
    for(i = n-2; i>=0; i--){
        if(v[i] < v[i+1]){
            down = true;
        } else if(v[i] > v[i+1]){
            if(down) break;
        }
    }
    cout<<i+1<<endl;

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
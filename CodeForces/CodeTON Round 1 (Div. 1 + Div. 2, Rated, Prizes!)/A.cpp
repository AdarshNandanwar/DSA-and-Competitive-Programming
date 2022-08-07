#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<int> v(n, 0);
    for(auto &i:v) cin>>i;
    int i = 1+min_element(v.begin(), v.end())-v.begin();
    int j = 1+max_element(v.begin(), v.end())-v.begin();
    cout<<i<<" "<<j<<endl;

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
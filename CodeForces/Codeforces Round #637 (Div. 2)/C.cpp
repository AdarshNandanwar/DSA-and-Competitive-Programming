#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<ll> v(n);
    set<ll> s;
    for(int i = 0; i<n ;i++){
        cin>>v[i];
    }
    ll l_min = v[0];
    s.insert(v[0]);
    for(int i =1; i<n; i++){
        if(s.find(v[i]) != s.end()){
            cout<<"No\n";
            return;
        }
        if(v[i]>v[i-1]){
            if(v[i]-v[i-1] > 1){
                cout<<"No\n";
                return;
            }   
        } else {
            if(v[i] < l_min){
                l_min = v[i];
            } else {
                cout<<"No\n";
                return;
            }
        }
        s.insert(v[i]);
    }
    cout<<"Yes\n";
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
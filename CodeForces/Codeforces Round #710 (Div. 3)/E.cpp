#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<ll> v(n), v_min, v_max;

    for(auto & i:v) cin>>i;

    unordered_set<ll> s1, s2;
    ll cur_min = 1, cur_max = 0;



    for(ll i = 0; i<n; i++){
        if(i == 0 or v[i-1] != v[i]){
            cur_max = v[i];
            v_min.push_back(v[i]);
            v_max.push_back(v[i]);
            s1.insert(v[i]);
            s2.insert(v[i]);
        } else {
            while(s1.count(cur_min)) cur_min++;
            v_min.push_back(cur_min);
            s1.insert(cur_min);
            cur_min++;
            while(s2.count(cur_max)) cur_max--;
            v_max.push_back(cur_max);
            s2.insert(cur_max);
            cur_max--;
        }
    }

    for(auto i:v_min) cout<<i<<" "; cout<<endl;
    for(auto i:v_max) cout<<i<<" "; cout<<endl;

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
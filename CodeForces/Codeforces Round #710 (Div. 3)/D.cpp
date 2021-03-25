#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<ll> v(n);
    unordered_map<ll, ll> m;

    for(auto & i:v){
        cin>>i;
        m[i]++;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> pq;

    for(auto i:m){
        pq.push({i.second, i.first});
    }

    while(1){
        if(pq.empty()){
            cout<<0<<endl;
            return;
        } 
        auto a = pq.top();
        pq.pop();

        if(pq.empty()){
            cout<<a.first<<endl;
            return;
        }
        auto b = pq.top();
        pq.pop();

        a.first--;
        b.first--;
        
        if(a.first) pq.push(a);
        if(b.first) pq.push(b);
        // cout<<a.second<<","<<b.second<<" ";

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
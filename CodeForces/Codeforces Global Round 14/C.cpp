#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    ll m, x;
    cin>>m>>x;
    vector<pair<ll, ll>> v(n, {0,0});
    vector<ll> ans(n);
    for(int i = 0; i<n; i++){
        cin>>v[i].first;
        v[i].second = i;
    } 
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for(ll i = 0; i<m; i++) pq.push({0, i});

    for(int i = 0; i<n; i++){
        auto cur = pq.top();
        pq.pop();
        cur.first += v[i].first;
        pq.push(cur);
        ans[v[i].second] = cur.second+1;
    }

    // check if any 0
    ll min_ele = INT_MAX, max_ele = INT_MIN;
    while(!pq.empty()){
        auto cur = pq.top();
        min_ele = min(min_ele, cur.first);
        max_ele = max(max_ele, cur.first);
        pq.pop();
        if(cur.first == 0 or max_ele-min_ele > x){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
    for(auto & i:ans) cout<<i<<" "; cout<<endl;
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
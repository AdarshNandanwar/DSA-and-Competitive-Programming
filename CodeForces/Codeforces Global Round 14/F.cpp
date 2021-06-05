#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

ll root(ll x, vector<ll> & id){
    if(id[x] == x) return x;
    return id[x] = root(id[x], id);
}

void merge(ll r0, ll r1, vector<ll> & id, vector<ll> & sz, vector<ll> & asp, ll x){
    if(sz[r0] < sz[r1]){
        id[r0] = r1;
        sz[r1] += sz[r0];
        asp[r1] += (asp[r0]-x);
    } else {
        id[r1] = r0;
        sz[r0] += sz[r1];
        asp[r0] += (asp[r1]-x);
    }
}

void solve(){
    ll m, x;
    cin>>n>>m>>x;

    ll r0, r1;
    ll count = 0;
    vector<ll> id(n, 0), sz(n, 1), asp(n);
    priority_queue<vector<ll>, vector<vector<ll>>> pq;

    for(auto & i:asp) cin>>i;
    for(ll i = 0; i<m; i++){
        ll a, b;
        cin>>a>>b;
        a--; b--;
        pq.push({asp[a]+asp[b], a, b, i});
    }
    for(ll i = 0; i<n; i++) id[i] = i;
    vector<ll> ans;
    ll no_change = 0;
    while(!pq.empty()){
        auto edge = pq.top();
        cout<<edge[0]<<" "<<edge[1]<<" "<<edge[2]<<endl;
        pq.pop();
        if(ans.size() == n-1){
            break;
        }
        r0 = root(edge[1], id);
        r1 = root(edge[2], id);
        if(r0 == r1){
            continue;
        }
        if(asp[r0]+asp[r1] < x){
            edge[0] = asp[r0]+asp[r1];
            pq.push(edge);
            no_change++;
            continue;
        } else {
            no_change = 0;
        }
        if(no_change == pq.size()){
            cout<<"NO\n";
            return;
        }
        merge(r0, r1, id, sz, asp, x);
        ans.push_back(edge[3]);
    }
    cout<<"YES\n";
    for(auto & i:ans) cout<<i<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}
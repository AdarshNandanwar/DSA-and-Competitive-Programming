#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void getTopoSort(vector<vector<ll>> & dirEdges, vector<ll> & inDeg, vector<ll> & topoSort, ll & n){
    queue<int> q;
    for(int i = 0; i<n; i++){
        if(inDeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        topoSort.push_back(cur);
        for(auto nbr:dirEdges[cur]){
            inDeg[nbr]--;
            if(inDeg[nbr] == 0) q.push(nbr);
        }
    }
}

void solve(){
    ll m, t, n1, n2;
    cin>>n>>m;
    vector<vector<ll>> dirEdges(n);
    vector<ll> inDeg(n, 0);
    vector<pair<ll, ll>> unDirEdges;

    for(int i = 0; i<m;i++){
        cin>>t>>n1>>n2; n1--; n2--;
        if(t){
            dirEdges[n1].push_back(n2);
            inDeg[n2]++;
        } else {
            unDirEdges.push_back({n1, n2});
        }
    }
    
    vector<ll> topoSort;
    getTopoSort(dirEdges, inDeg, topoSort, n);

    if(topoSort.size() < n){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

    vector<int> order(n);
    for(int i = 0; i<n; i++){
        order[topoSort[i]] = i;
    }
    for(int i = 0; i<n; i++){
        for(auto j:dirEdges[i]){
            cout<<i+1<<" "<<j+1<<endl;
        }
    }
    for(auto [i,j]:unDirEdges){
        if(order[i] > order[j]) swap(i, j);
        cout<<i+1<<" "<<j+1<<endl;
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
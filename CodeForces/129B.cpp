// http://codeforces.com/contest/129/problem/B

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int is_leaf(vector<vector<bool>> & graph, int cur){
    ll nbr = -1;
    for(int i = 0; i<graph.size(); i++){
        if(graph[cur][i]){
            if(nbr != -1) return -1;
            nbr = i;
        }
    }
    return nbr;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, a, b, ans = 0;
    cin>>n>>m;
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    while(m--){
        cin>>a>>b;
        a--; b--;
        graph[a][b] = graph[b][a] = true;
    }

    while(true){
        vector<pair<int, int>> grp;
        for(ll i = 0; i<n; i++){
            ll nbr = is_leaf(graph, i);
            if(nbr != -1) grp.push_back({i, nbr});
        }
        for(auto i:grp){
            graph[i.first][i.second] = graph[i.second][i.first] = false;
        }
        if(grp.size()) ans++;
        else break;
    }
    cout<<ans<<endl;

    return 0;
}
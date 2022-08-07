#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

bool find_cycle(int pos, const vector<vector<int>> & adj, vector<int> & visited, vector<int> & path, bool & found){
    path.push_back(pos);
    if(visited[pos]){
        found = true;
        return true;
    } else {
        visited[pos] = true;

        for(auto & nbr:adj[pos]){
            auto res = find_cycle(nbr, adj, visited, path, found);
            if(res) return true;
        }
        visited[pos] = false;
    }
    path.pop_back();
    return false;
}

void solve(){

    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i<m; i++){
        int st, end;
        cin>>st>>end;
        adj[st-1].push_back(end-1);
    }

    vector<int> visited(n, 0);
    vector<int> path(0);

    bool res, found = false;

    for(int i = 0; i<n; i++){
        res = find_cycle(i, adj, visited, path, found);
        if(res) break;
    }

    if(res){

        int st = path.back();
        vector<int> ans = {st};
        path.pop_back();
        while(path.back() != st){
            ans.push_back(path.back());
            path.pop_back();
        }
        sort(ans.begin(), ans.end());
        for(auto &i:ans){
            cout<<i+1<<" ";
        }
        cout<<endl;
    } else {
        cout<<"0\n";
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
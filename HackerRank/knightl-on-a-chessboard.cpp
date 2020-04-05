#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> addPair(pair<ll, ll> p1, pair<ll, ll> p2){
    return make_pair(p1.first+p2.first, p1.second+p2.second);
}

bool isValid(pair<ll, ll> p, ll n){
    ll i = p.first, j = p.second;
    if(i<0 || j<0 || i>=n || j>=n){
        return false;
    } else {
        return true;
    }
}

ll bfs(ll x, ll y, ll n, vector<pair<ll, ll>> ** adj_list, bool ** visited){
    pair<ll, ll> origin = make_pair(x, y);
    queue<pair<ll, ll>> q;
    map<pair<ll,ll>,ll> level;
    level[origin] = 0;
    q.push(origin);
    visited[x][y] = true;
    while(!q.empty()){
        pair<ll, ll> curr = q.front();
        q.pop();
        if(curr.first == n-1 && curr.second == n-1){
            return level[curr];
        }
        vector<pair<ll,ll>>::iterator itr;
        for(itr = adj_list[curr.first][curr.second].begin(); itr != adj_list[curr.first][curr.second].end(); itr++){
            if(!visited[(*itr).first][(*itr).second]){
                visited[(*itr).first][(*itr).second] = true;
                level[*itr] = level[curr] + 1;
                q.push(*itr);
            }
        }
    }
    return -1;
}

ll solve(ll n, ll x, ll y){
    
    vector<pair<ll,ll>> modify;
    modify.push_back(make_pair(x,y));
    modify.push_back(make_pair(-x,y));
    modify.push_back(make_pair(x,-y));
    modify.push_back(make_pair(-x,-y));
    modify.push_back(make_pair(y,x));
    modify.push_back(make_pair(-y,x));
    modify.push_back(make_pair(y,-x));
    modify.push_back(make_pair(-y,-x));
    
    bool ** visited = new bool*[n];
    vector<pair<ll, ll>> ** adj_list = new vector<pair<ll,ll>>*[n];
    for (ll i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        adj_list[i] = new vector<pair<ll,ll>>[n];
        for (ll j = 0; j < n; j++)
        {
            visited[i][j] = false;
            
            vector<pair<ll,ll>>::iterator itr;
            for(itr = modify.begin(); itr != modify.end(); itr++){
                pair<ll, ll> temp = addPair(make_pair(i, j),*itr);
                if(isValid(temp, n)){
                    adj_list[i][j].push_back(temp);
                }
            }
        }
    }
    

    return bfs(0, 0, n, adj_list, visited);
}

int main(){
    ll n;
    cin>>n;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j < n; j++)
        {
            cout<<solve(n,i,j)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
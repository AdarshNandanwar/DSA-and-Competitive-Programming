#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void swap(ll & a, ll & b){
    ll temp = b;
    b = a;
    a = temp;
}

void solve(){
    ll m;
    cin>>n>>m;
    // {val, col}
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    vector<vector<ll>> ans(n, vector<ll>(m, -1));
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            cin>>v[i][j];
            pq.push({v[i][j], {i,j}});
        }
    }

    for(int k = 0; k<m; k++){
        auto cur = pq.top();
        pq.pop();
        int row = cur.second.first;
        int col = cur.second.second;
        ans[row][k] = cur.first;
        v[row][col] = -1;
        // cout<<">>> "<<row<<" "<<col<<" "<<cur.first<<endl;
    }

    for(ll i = 0; i<n; i++){
        int col = 0;
        for(ll j = 0; j<m; j++){
            if(ans[i][j] == -1){
                while(v[i][col] == -1) col++;
                ans[i][j] = v[i][col];
                col++;
            }
        }
    }

    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
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
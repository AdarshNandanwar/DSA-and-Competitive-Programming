#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

vector<ll> dir = {0, -1, 0, 1, 0};

ll n;

void solve(){

    ll m, k;
    cin>>n>>m>>k;
    if(k%2){
        cout<<-1<<endl;
        return;
    }
    vector<vector<ll>> eh(n, vector<ll>(m-1, 0));
    vector<vector<ll>> ev(n-1, vector<ll>(m, 0));
    vector<vector<ll>> ans(n, vector<ll>(m, INT_MAX));
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m-1; j++){
            cin>>eh[i][j];
        }
    }
    for(ll i = 0; i<n-1; i++){
        for(ll j = 0; j<m; j++){
            cin>>ev[i][j];
        }
    }
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            // {cost, steps, row, col}
            priority_queue<pair<ll,pair<ll,pair<ll,ll>>>, vector<pair<ll,pair<ll,pair<ll,ll>>>>, greater<pair<ll,pair<ll,pair<ll,ll>>>>> pq;
            ll r = k/2;
            vector<vector<ll>> d(2*r+1, vector<ll>(2*r+1, INT_MAX));
            vector<vector<ll>> candidate(2*r+1, vector<ll>(2*r+1, INT_MAX));

            // for(ll ii = 0; ii<2*r+1; ii++){
            //     for(ll jj = 0; jj<2*r+1; jj++){
            //         if(i+ii-k>=0 and i+ii-k<n and j+jj-k>=0 and j+jj-k<m){
            //             ans[i+ii-k][j+jj-k] = min(ans[i+ii-k][j+jj-k], candidate[ii][jj]);
            //         }
            //     }
            // }


            d[r][r] = 0;
            pq.push({0,{0,{r,r}}});
            while(!pq.empty()){
                cout<<"size: "<<pq.size()<<endl;
                auto cur = pq.top();
                pq.pop();
                ll cw = cur.first;
                ll cs = cur.second.first;
                ll ci = cur.second.second.first;
                ll cj = cur.second.second.second;
                cout<<ci<<" "<<cj<<" "<<cw<<" "<<cs<<endl;
                if(cs != 0 and r%cs == 0) candidate[ci][cj] = min(candidate[ci][cj], 2*cw*(r/cs));
                if(cs == r) continue;
                if(d[ci][cj] < cw) continue;
                // left
                if(i+ci-k>=0 and i+ci-k<n and j+cj-k-1>=0 and j+cj-k-1<m){
                    ll cost = eh[i+ci-k][j-1+cj-k];
                    if(d[ci][cj-1] > cw+cost){
                        d[ci][cj-1] = cw+cost;
                        pq.push({d[ci][cj-1], {cs+1, {ci, cj-1}}});
                    }
                }
                // right
                if(i+ci-k>=0 and i+ci-k<n and j+cj-k>=0 and j+cj-k<m){
                    ll cost = eh[i+ci-k][j+cj-k];
                    if(d[ci][cj+1] > cw+cost){
                        d[ci][cj+1] = cw+cost;
                        pq.push({d[ci][cj+1], {cs+1, {ci, cj+1}}});
                    }
                }
                // top
                if(i+ci-k-1>=0 and i+ci-k-1<n and j+cj-k+1>=0 and j+cj-k+1<m){
                    ll cost = eh[i+ci-k-1][j+cj-k];
                    if(d[ci-1][cj] > cw+cost){
                        d[ci-1][cj] = cw+cost;
                        pq.push({d[ci-1][cj], {cs+1, {ci-1, cj}}});
                    }
                }
                // bottom
                if(i+ci-k>=0 and i+ci-k<n and j+cj-k+1>=0 and j+cj-k+1<m){
                    ll cost = eh[i+ci-k][j+cj-k];
                    if(d[ci+1][cj] > cw+cost){
                        d[ci+1][cj] = cw+cost;
                        pq.push({d[ci+1][cj], {cs+1, {ci+1, cj}}});
                    }
                }
            }

            for(ll ii = 0; ii<2*r+1; ii++){
                for(ll jj = 0; jj<2*r+1; jj++){
                    if(i+ii-k>=0 and i+ii-k<n and j+jj-k>=0 and j+jj-k<m){
                        ans[i+ii-k][j+jj-k] = min(ans[i+ii-k][j+jj-k], candidate[ii][jj]);
                    }
                }
            }
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
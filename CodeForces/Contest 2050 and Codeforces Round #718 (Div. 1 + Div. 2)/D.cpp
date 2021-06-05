#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

vector<ll> dir = {0, -1, 0, 1, 0};

ll n;

void solve(){

    ll m, k;
    cin>>n>>m>>k;
    vector<vector<ll>> eh(n, vector<ll>(m-1, 0));
    vector<vector<ll>> ev(n-1, vector<ll>(m, 0));
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
    if(k%2){    
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<m; j++){
                cout<<"-1 ";
            }
            cout<<endl;
        }  
        return;
    }

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(k+1, INT_MAX)));
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            dp[i][j][0] = 0;
        }
    }
    k /= 2;
    for(ll a = 1; a<k+1; a++){
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<m; j++){
                if(i-1 >= 0) dp[i][j][a] = min(dp[i][j][a], ev[i-1][j] + dp[i-1][j][a-1]);
                if(j-1 >= 0) dp[i][j][a] = min(dp[i][j][a], eh[i][j-1] + dp[i][j-1][a-1]);
                if(i+1 < n) dp[i][j][a] = min(dp[i][j][a], ev[i][j] + dp[i+1][j][a-1]);
                if(j+1 < m) dp[i][j][a] = min(dp[i][j][a], eh[i][j] + dp[i][j+1][a-1]);
            }
        }
    }
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            cout<<2*dp[i][j][k]<<" ";
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
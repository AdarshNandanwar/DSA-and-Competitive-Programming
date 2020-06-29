#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    int cap;
    cin>>cap>>n;

    // size, val
    vector<pair<int, int>> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }
    
    // dp[index][cap] = max(dp[index+1][cap], v[index].second + dp[index+1][cap-v[index].first])
    vector<vector<int>> dp(2, vector<int>(cap+1, 0));

    for(int i = n-1; i>= 0; i--){
        for(int j =0; j<=cap; j++){
            // exclude
            dp[i%2][j] = dp[(i+1)%2][j];
            // include
            if(j-v[i].first >= 0){
                dp[i%2][j] = max(dp[i%2][j], v[i].second + dp[(i+1)%2][j-v[i].first]);
            }
        }
    }
    cout<<dp[0%2][cap]<<endl;

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
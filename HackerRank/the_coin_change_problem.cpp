#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<long> c, ll ** dp, ll index){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(index >= c.size()){
        return 0;
    }
    if(dp[index][n]!=-1){
        return dp[index][n];
    }
    dp[index][n] = solve(n, c, dp, index+1) + solve(n-c[index], c, dp, index);
    return dp[index][n];
}

long getWays(int n, vector<long> c) {
    ll ** dp = new ll*[c.size()];
    for (ll i = 0; i < c.size(); i++)
    {
        dp[i] = new ll[n+1];
        for (ll j = 0; j < n+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    ll ans = solve(n, c, dp, 0);
    for (ll i = 0; i < c.size(); i++)
    {
        delete [] dp[i];
    }   
    delete [] dp;
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<long> v;
    for (ll i = 0; i < m; i++)
    {
        long temp;
        cin>>temp;
        v.push_back(temp);
    }
    cout<<getWays(n, v)<<endl;
    return 0;
}
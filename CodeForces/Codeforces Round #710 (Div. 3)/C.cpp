#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

string a;
string b;

ll helper(ll ai, ll aj, ll bi, ll bj, vector<vector<vector<vector<int>>>> & dp){
    if(dp[ai][aj][bi][bj] != -1) return dp[ai][aj][bi][bj];
    dp[ai][aj][bi][bj] = INT_MAX;

    if(ai>=aj) return dp[ai][aj][bi][bj] = bj-bi;
    if(bi>=bj) return dp[ai][aj][bi][bj] = aj-ai;

    if(aj-ai == bj-bi and a.substr(ai, aj-ai) == b.substr(bi, bj-bi)) return dp[ai][aj][bi][bj] = 0;

    return dp[ai][aj][bi][bj] = 1+min(min(helper(ai+1, aj, bi, bj, dp), helper(ai, aj-1, bi, bj, dp)), min(helper(ai, aj, bi+1, bj, dp), helper(ai, aj, bi, bj-1, dp)));

}

void solve(){

    cin>>a;
    cin>>b;

    int n = a.length(), m = b.length();

    vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(m+1, vector<int>(m+1, -1))));

    cout<<helper(0, n, 0, m, dp)<<endl;

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
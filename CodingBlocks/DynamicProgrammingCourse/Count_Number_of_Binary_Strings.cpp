// You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

// Constraints
// 1<=t<=100 1<=n<=90

// Output Format
// Print the number of all possible binary strings.

// Sample Input
// 2
// 2
// 3
// Sample Output
// 3
// 5
// Explanation
// 1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    // dp[i][j] = number of strings of length i ending with j
    vector<vector<ll>> dp(n+1, vector<ll>(2, 1));
    for(int i = 2; i<=n; i++){
        dp[i][0] = dp[i-1][0]+dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    cout<<dp[n][0]+dp[n][1]<<endl;
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
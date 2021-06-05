// Given a string s and m queries . Each query consists of (l,r) where 1 <= l <= r <= n(size of string).

// You need to print whether l to r is a palindromic string or not.

// A string can be called palindrome if its reverse is same as itself . Ex - "aba" .

// Input Format
// First line contains n Second lines contains a string of length n. Next line contains m where m is the number of queries . Next m lines contains two integers l,r as described in the question.

// Constraints
// n <= 1000

// m <= 100000

// Output Format
// for every query from l to r print "YES" if s[l…..r] is palindrome else print "NO" without quotes in a new line.

// Sample Input
// 5
// abbac
// 2
// 1 4
// 2 4
// Sample Output
// YES
// NO
// Explanation
// s[1….4]="abba", it is a palindrome.

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll helper(ll i, ll j, string & s, vector<vector<ll>> & dp){
    if(dp[i][j] != -1) return dp[i][j];
    if(j<=i) return dp[i][j] = 1;
    if(s[i] == s[j]) return dp[i][j] = helper(i+1, j-1, s, dp);
    else return dp[i][j] = 0;
}

ll n;

void solve(){

    cin>>n;
    string s;
    cin>>s;
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    ll m;
    cin>>m;
    for(int i = 0; i<m; i++){
        ll a, b;
        cin>>a>>b;
        cout<<(helper(a-1, b-1, s, dp)?"YES":"NO")<<endl;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}
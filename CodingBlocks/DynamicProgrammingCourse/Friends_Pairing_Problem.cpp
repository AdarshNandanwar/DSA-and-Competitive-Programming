// Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

// Input Format
// First line contains an integer t denoting the number of test cases. Next t lines contain an integer n each.

// Constraints
// 1<= n < 30

// Output Format
// Output t lines each line describing the answer.

// Sample Input
// 1
// 3
// Sample Output
// 4
// Explanation
// {1}, {2}, {3} : all single {1}, {2,3} : 2 and 3 paired but 1 is single. {1,2}, {3} : 1 and 2 are paired but 3 is single. {1,3}, {2} : 1 and 3 are paired but 2 is single. Note that {1,2} and {2,1} are considered same.

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;

    // dp[i] = number of ways of pairing i friends
    vector<ll> dp(n+1, 1);
    for(ll i = 2; i<=n; i++) dp[i] = dp[i-1]+(i-1)*dp[i-2];
    cout<<dp[n]<<endl;
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
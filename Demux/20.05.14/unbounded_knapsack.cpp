// https://www.hackerrank.com/challenges/unbounded-knapsack/problem

// Method 1 (First element, DP):

int unboundedKnapsack(int k, vector<int> arr) {

    // first element decision
    vector<int> dp(k+1, 0);
    int n = arr.size();
    for(int i=0; i<=k; i++){
        for(int j =0; j<n; j++){
            if(i-arr[j] >= 0){
                dp[i] = max(dp[i], arr[j]+dp[i-arr[j]]);
            }
        }
    }
    return dp[k];
}

// Method 2 (Include/Exclude, DP):

int unboundedKnapsack(int k, vector<int> arr) {
    int n = arr.size();
    // include exclude
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=k; j++){
            // exclude
            dp[i][j] = dp[i+1][j];
            // include
            if(j-arr[i]>= 0){
                dp[i][j] = max(dp[i][j], arr[i] + dp[i][j-arr[i]]);
            }
        }
    }
    return dp[0][k];
}

// Method 1 (First element, Recursion DP):

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

int helper(vector<int> v, int sum, vector<int> & dp){

    if(sum==0){
        return 0;
    }
    if(dp[sum] != -1){
        return dp[sum];
    }

    int res = 0;
    for(int i =0; i<v.size(); i++){
        if(sum-v[i] >= 0)
            res = max(res, v[i]+helper(v, sum-v[i], dp));
    }
    return dp[sum] = res;
}

void solve(){
    int k;
    cin>>n>>k;
    vector<int> v(n), dp(k+1, -1);

    for (int i = 0; i < n; i++)
        cin>>v[i];

    cout<<helper(v, k, dp)<<endl;
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


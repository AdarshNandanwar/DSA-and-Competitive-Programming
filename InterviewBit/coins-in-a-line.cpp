// https://www.interviewbit.com/problems/coins-in-a-line/

// Method 1 (DP, O(n2)):

#include<bits/stdc++.h>
int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    // dp[i][j] = diff between the scores of players (current-opponent) if the array is [i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // base case
    for(int i = 0; i<n; i++) dp[i][i] = A[i];
    for(int i = n-1; i>=0; i--){
        for(int j = i+1; j<n; j++){
            dp[i][j] = max(A[i]-dp[i+1][j], A[j]-dp[i][j-1]);
        }
    }
    return (accumulate(A.begin(), A.end(), 0)+dp[0][n-1])/2;
}

// Method 2 (DP, O(n2)):

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    // prefixSum[i] = sum A[0, i)
    vector<int> prefixSum(n+1, 0);  
    for(int i = 1; i<=n; i++) prefixSum[i] = A[i-1]+prefixSum[i-1];
    // dp[i][j] = max score of the current player if the array is [i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // base case
    for(int i = 0; i<n; i++) dp[i][i] = A[i];
    for(int i = n-1; i>=0; i--){
        for(int j = i+1; j<n; j++){
            dp[i][j] = prefixSum[j+1]-prefixSum[i]+max(-dp[i+1][j], -dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}
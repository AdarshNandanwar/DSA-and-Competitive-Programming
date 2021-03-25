// https://www.interviewbit.com/problems/flip-array/

// Method 1 (0/1 Knapsack Problem, O(n*sum)):

int Solution::solve(const vector<int> &A) {
    int sum = 0, n = A.size();
    if(n == 0) return 0;
    for(auto i:A) sum += i;
    int target = sum/2;
    
    // dp[i][j] = min number of elements that has be picked in [i..n-1] to get sum j
    vector<vector<int>> dp(n+1, vector<int>(target+1, n+1));
    // base case
    for(int i = 0; i<=n; i++) dp[i][0] = 0;
    
    for(int i = n-1; i>=0; i--){
        for(int j = 1; j<=target; j++){
            dp[i][j] = dp[i+1][j];
            if(j-A[i]>=0) dp[i][j] = min(dp[i][j], 1+dp[i+1][j-A[i]]);
        }
    }
    for(int i = target; i>=0; i--){
        if(dp[0][i] <= n) return dp[0][i];
    }
    return n;
}

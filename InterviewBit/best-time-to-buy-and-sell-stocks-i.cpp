// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

// Method 1 (O(n) time, O(1) space):

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n <= 1) return 0;
    int minLeft = A[0], res = -1;;
    for(int i = 0; i<n; i++){
        res = max(res, A[i]-minLeft);
        minLeft = min(minLeft, A[i]);
    }
    return res;
}

// Method 2 (DP, General structure, O(n) time, O(n) space):

int Solution::maxProfit(const vector<int> &A) {
    
    // dp[i][1] = max profit in [0..i] when 1 stock bought
    
    // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+A[i]);
    // dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-A[i]);
    
    int n = A.size();
    if(n <= 1) return 0;
    
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, 0)));
    
    // base case
    for(int j = 1; j<2; j++) dp[0][j][1] = -A[0];
    
    for(int i = 1; i<n; i++){
        for(int j = 1; j<2; j++){
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+A[i]);
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-A[i]);
        }
    }
    return dp[n-1][1][0];
}

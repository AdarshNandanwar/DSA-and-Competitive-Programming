// https://www.interviewbit.com/problems/max-product-subarray/

// Method 1 (DP):

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    int res = INT_MIN;
    vector<vector<int>> dp(n+1, vector<int>(2, 1));
    for(int i = n-1; i>=0; i--){
        dp[i][0] = min(A[i], min(A[i]*dp[i+1][0], A[i]*dp[i+1][1]));
        dp[i][1] = max(A[i], max(A[i]*dp[i+1][0], A[i]*dp[i+1][1]));
        res = max(res, max(dp[i][0], dp[i][1]));
    }
    return res;
}

// Alternate Code

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    int res = INT_MIN;
    vector<vector<int>> dp(n+1, vector<int>(2, 1));
    for(int i = n-1; i>=0; i--){
        if(A[i] > 0){
            dp[i][0] = min(A[i], A[i]*dp[i+1][0]);
            dp[i][1] = max(A[i], A[i]*dp[i+1][1]);
        } else {
            dp[i][0] = min(A[i], A[i]*dp[i+1][1]);
            dp[i][1] = max(A[i], A[i]*dp[i+1][0]);
        }
        res = max(res, max(dp[i][0], dp[i][1]));
    }
    return res;
}
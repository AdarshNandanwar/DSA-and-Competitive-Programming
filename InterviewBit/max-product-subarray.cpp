// https://www.interviewbit.com/problems/max-product-subarray/

// Method 1 (DP, O(n)):

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size(), res = INT_MIN;
    if(n == 0) return 0;
    // {pos, neg}
    vector<pair<int, int>> dp(n, make_pair(-1, 1));

    // base case
    res = dp[0].first = dp[0].second = A[0];
    
    for(int i = 1; i<n; i++){
        dp[i].first = max(A[i], max(A[i]*dp[i-1].first, A[i]*dp[i-1].second));
        dp[i].second = min(A[i], min(A[i]*dp[i-1].first, A[i]*dp[i-1].second));
        res = max(res, dp[i].first);
    }
    return res;
}

// Method 2 (DP, O(n)):

int Solution::maxProduct(const vector<int> &A) {
    
    int n = A.size();
    if(n == 0) return 0;
    // {pos, neg}
    vector<pair<int, int>> dp(n, make_pair(-1, 1));
    
    int res = *max_element(A.begin(), A.end());
    
    // base case
    if(A[0]>=0) dp[0] = make_pair(A[0], 1);
    else dp[0] = make_pair(-1, A[0]);
    
    for(int i = 1; i<n; i++){
        if(A[i] == 0){
            dp[i] = make_pair(0, 1);
        } else if(A[i]>0){
            dp[i].first = max(A[i], dp[i-1].first>=0 ? A[i]*dp[i-1].first : -1);
            dp[i].second = dp[i-1].second<0 ? A[i]*dp[i-1].second : 1;
        } else {
            dp[i].first = dp[i-1].second<0 ? A[i]*dp[i-1].second : -1;
            dp[i].second = min(A[i], dp[i-1].first>=0 ? A[i]*dp[i-1].first : 1);
        }
        if(dp[i].first >= 0)res = max(res, dp[i].first);
    }
    return res;
}

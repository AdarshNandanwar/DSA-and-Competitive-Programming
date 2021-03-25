// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

// Method 1 (Prefix Suffix DP):

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    // dp[i] = minRight[i+1, n-1]
    vector<int> dp(n);
    dp[n-1] = INT_MAX;
    for(int i = n-2; i>=0; i--) dp[i] = min(dp[i+1], A[i+1]);
    int p1 = 0, p2 = n-1;
    while(p1<n){
        if(dp[p1] < A[p1]) break;
        if(p1-1>=0 and A[p1-1] > A[p1]) break;
        p1++;
    }
    if(p1 == n) return {-1};
    // dp[i] = maxLeft[0, i-1]
    dp[0] = INT_MIN;
    for(int i = 1; i<n; i++) dp[i] = max(dp[i-1], A[i-1]);
    while(p2<n){
        if(dp[p2] > A[p2]) break;
        if(p2+1<n and A[p2] > A[p2+1]) break;
        p2--;
    }
    return {p1, p2};
}
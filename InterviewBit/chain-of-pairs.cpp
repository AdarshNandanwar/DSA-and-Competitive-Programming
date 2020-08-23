// https://www.interviewbit.com/problems/chain-of-pairs/

// Method 1 (DP, O(n2)):

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), res = 1;;
    vector<int> dp(n, 1);
    // dp[i] = len of max subseq ending at i
    // dp[i] = max(dp[i], 1+dp[j])
    for(int  i =0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(A[i][0] > A[j][1]) res = max(res, dp[i] = max(dp[i], 1+dp[j]));
        }
    }
    return res;
}

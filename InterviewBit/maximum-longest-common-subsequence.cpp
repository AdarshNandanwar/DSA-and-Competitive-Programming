// https://www.interviewbit.com/problems/maximum-longest-common-subsequence/?test_id=11890

// Method 1 (DP, O(n2)):

vector<int> Solution::maxLCS(string A) {
    int n = A.length(), maxJ = -1, res = -1;
    if(n <= 1) return {1, 0};
    // dp[i][j] = LCS in A[0,p1] and rev(A[p2, n-1])
    vector<vector<int>> dp(n, vector<int>(n));
    for(int p1 = 0; p1<n-1; p1++){
        for(int p2 = n-1; p2>p1; p2--){
            if(A[p1] == A[p2]){
                if(p1 == 0 or p2 == n-1) dp[p1][p2] = 1;
                else dp[p1][p2] = 1+dp[p1-1][p2+1];
            } else {
                dp[p1][p2] = 0;
                if(p1 != 0) dp[p1][p2] = max(dp[p1][p2], dp[p1-1][p2]);
                if(p2 != n-1) dp[p1][p2] = max(dp[p1][p2], dp[p1][p2+1]);
            }
        }
        if(dp[p1][p1+1]>res){
            res = dp[p1][p1+1];
            maxJ = p1+1;
        }
    }
    return {maxJ, res};
}

// Method 2 (DP with useless extra loop, O(n3)):

int helper(const string & A, int st, int mid, int end){
    // dp[i][j] = LCS in A[0,i] and rev(A[j, end])
    int n = A.length();
    vector<vector<int>> dp(n, vector<int>(n));
    for(int p1 = st; p1<mid; p1++){
        for(int p2 = end; p2>=mid; p2--){
            if(A[p1] == A[p2]){
                if(p1 == st or p2 == end) dp[p1][p2] = 1;
                else dp[p1][p2] = 1+dp[p1-1][p2+1];
            } else {
                dp[p1][p2] = 0;
                if(p1 != st) dp[p1][p2] = max(dp[p1][p2], dp[p1-1][p2]);
                if(p2 != end) dp[p1][p2] = max(dp[p1][p2], dp[p1][p2+1]);
            }
        }
    }
    return dp[mid-1][mid];
}

vector<int> Solution::maxLCS(string A) {
    int n = A.length(), maxJ = -1, res = -1;
    if(n <= 1) return {1, 0};
    for(int j = 1; j<n; j++){
        int h = helper(A, 0, j, n-1);
        if(h>res){
            res = h;
            maxJ = j;
        }
    }
    return {maxJ, res};
}

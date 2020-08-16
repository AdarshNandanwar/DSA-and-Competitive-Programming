// https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/

// Method 1 (3D DP, O(n*m*k)):

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int n = B.size(), m = B[0].size();
    // dp[k][i][j] = max element within k dist from B[i][j]
    vector<vector<vector<int>>> dp(A+1, vector<vector<int>>(n, vector<int>(m, 0)));
    dp[0] = B;
    for(int k = 1; k<=A; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                dp[k][i][j] = B[i][j];
                if(i-1>=0) dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j]);
                if(i+1<n) dp[k][i][j] = max(dp[k][i][j], dp[k-1][i+1][j]);
                if(j-1>=0) dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j-1]);
                if(j+1<m) dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j+1]);
            }
        }
    }
    return dp[A];
}

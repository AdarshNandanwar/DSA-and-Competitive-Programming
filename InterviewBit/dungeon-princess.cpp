// https://www.interviewbit.com/problems/dungeon-princess/

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    // base case
    dp[n-1][m-1] = max(1, 1-A[n-1][m-1]);
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(i == n-1 and j == m-1) continue;
            if(i != n-1) dp[i][j] = min(dp[i][j], max(1, dp[i+1][j]-A[i][j]));
            if(j != m-1) dp[i][j] = min(dp[i][j], max(1, dp[i][j+1]-A[i][j]));
        }
    }
    return dp[0][0];
}

// https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    int n = A.size();
    if(n == 0){
        return 0;
    }
    int m = A[0].size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    if(A[0][0]) return 0;
    
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(i == n-1 and j == m-1){
                dp[i][j] = 1;
            } if(A[i][j]){
                dp[i][j] = 0;
            } else {
                dp[i][j] += dp[i+1][j];
                dp[i][j] += dp[i][j+1];
            }
        }
    }
    
    return dp[0][0];
}

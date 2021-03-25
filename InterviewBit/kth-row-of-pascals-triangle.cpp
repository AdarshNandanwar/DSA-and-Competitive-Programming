// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

long long int fact(int n, unordered_map<int, long long int> & dp){
    if(n <= 1) return 1;
    if(dp.count(n)) return dp[n];
    return dp[n] = n*fact(n-1, dp);
}

vector<int> Solution::getRow(int A) {
    vector<vector<int>> dp(2, vector<int>(A+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i<=A; i++){
        dp[i%2][0] = 1;
        for(int j = 1; j<=i; j++){
            dp[i%2][j] = dp[(i-1)%2][j-1]+dp[(i-1)%2][j];
        }
    }
    return dp[A%2];
}

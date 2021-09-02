// https://www.interviewbit.com/problems/coin-sum-infinite/

// Method 1 (O(c*n) time, O(n) space):

int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size();
    
    vector<int> dp(B+1, 0);
    dp[0] = 1;
    
    for(int i = n-1; i>=0; i--){
        for(int j = A[i]; j<=B; j++){
            dp[j] = (dp[j]+dp[j-A[i]])%1000007;
        }
    }
    return dp[B];
}

// Method 2 (Bottom Up, MLE, O(c*n) time O(c*n) space):

int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size();
    
    // dp[i][j] = number of unique ways to make sum j using [i..n-1] coins
    vector<vector<int>> dp(n+1, vector<int>(B+1, 0));
    for(int i = 0; i<=n; i++) dp[i][0] = 1;
    
    for(int i = n-1; i>=0; i--){
        for(int j = B; j>0; j--){
            int sum = 0;
            while(j-sum >=0){
                dp[i][j] = (dp[i][j]+dp[i+1][j-sum])%1000007;
                sum += A[i];
            }
        }
    }
    return dp[0][B];
}

// Method 3 (Top Down, MLE, O(c*n) time O(c*n) space):

int helper(int cur, vector<int> & coins, int B, vector<vector<int>> & dp){
    int n = coins.size();
    if(B == 0) return 1;
    if(B < 0 or cur == n) return 0;
    if(dp[cur][B] != -1) return dp[cur][B];
    int sum = 0, res = 0;
    while(sum<=B){
        res = (res+helper(cur+1, coins, B-sum, dp))%1000007;
        sum += coins[cur];
    }
    return dp[cur][B] = res;
}

int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(B+1, -1));
    return helper(0, A, B, dp);
}
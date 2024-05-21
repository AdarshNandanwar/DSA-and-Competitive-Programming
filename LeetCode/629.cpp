// https://leetcode.com/problems/k-inverse-pairs-array/

// Method 1 (Bottom Up 2D DP, Time Optimized, O(n*k)):

#define MOD 1000000007
class Solution {
public:
    int kInversePairs(int n, int k) {
        // dp[i][j] = number of arrays with 1..i with j inverse pairs
        // We can create [0, i-1] new inverse pairs from the subproblem [0..i-1]
        // dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+...+dp[i-1][j-(i-2)]+dp[i-1][j-(i-1)]             ... eq1
        // dp[i][j-1] = dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][j-1-(i-2)]+dp[i-1][j-1-(i-1)]     ... eq2
        // Subtract eq1 and eq2
        // => dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1-(i-1)]
        // => dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-i]
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
                if(j-i>=0){
                    dp[i][j] = ((dp[i][j]-dp[i-1][j-i])%MOD + MOD)%MOD;
                }
            }
        }
        return dp[n][k];
    }
};

// Alternate Code

#define MOD 1000000007

class Solution {
public:
    int kInversePairs(int n, int k) {
        // dp[i][j] = number of ways to arrange [1..i] with exactly j inversions
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int i = 0; i<=n; i++) dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=k ; j++){
                // dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j-(n-2)] + dp[i-1][j-(n-1)]
                // dp[i][j-1] = dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][j-1-(n-2)] + dp[i-1][j-1-(n-1)]
                // => dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][i-j];
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
                if(j-i >= 0) dp[i][j] = (dp[i][j] - dp[i-1][j-i])%MOD;
            }
        }
        return dp[n][k]<0 ? dp[n][k]+MOD : dp[n][k];
    }
};

// Method 2 (Bottom Up DP, Prefix Sum, O(n*k)):

#define MOD 1000000007

class Solution {
public:
    int kInversePairs(int n, int k) {
        // dp[i][j] = number of ways to arrange array [1..i] with exactly j inversions.
        vector<vector<long>> dp(n+1, vector<long>(k+1));

        // Base case
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        // Calculate prefix sum for row 0
        vector<long> prevPrefixSum(k+1, 0);
        prevPrefixSum[0] = dp[0][0];
        for(int j=1; j<=k; j++){
            prevPrefixSum[j] = (dp[0][j] + prevPrefixSum[j-1]) % MOD;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){

                // Compute start and end index of the loop
                int minK = max(j-(i-1), 0);
                int maxK = min(j, ((i-2)*(i-1))/2);

                // Using Prefix Sum instead of loop to reduce time complexity.
                // Keeping the loop here to explain what we are trying to compute in O(1).
                // Using loop will increase the Time Complexity to O(n*k*k)

                // for(int x=minK; x<=maxK; x++){
                //     dp[i][j] = (dp[i][j] + dp[i-1][x]) % MOD;
                // }

                dp[i][j] = prevPrefixSum[maxK];
                if(minK-1 >= 0){
                    dp[i][j] = (dp[i][j] - prevPrefixSum[minK-1]) % MOD;
                }
            }

            // Calculate prefix sum for current row (i) for next iteration (i+1).
            prevPrefixSum[0] = dp[i][0];
            for(int j=1; j<=k; j++){
                prevPrefixSum[j] = (dp[i][j] + prevPrefixSum[j-1]) % MOD;
            }
        }

        // Since subtraction is involved, we need to ensure that % MOD is positive.
        if(dp[n][k] < 0){
            dp[n][k] += MOD;
        }
        return dp[n][k];
    }
};

// Method 3 (Bottom Up DP, O(n*k*k), TLE):

class Solution {
public:
    int kInversePairs(int n, int k) {
        // dp[i][j] = number of ways to arrange [1..i] with exactly j inversions
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int i = 0; i<=n; i++) dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=k ; j++){
                for(int a = 0; a<=min(i-1, j); a++){
                    dp[i][j] = (dp[i][j]+dp[i-1][j-a])%1000000007;
                }
            }
        }
        return dp[n][k];
    }
};

// Method 4 (Top Down DP, O(n*k*k), TLE):

class Solution {
public:
    int helper(int n, int k, vector<vector<int>> &dp){
        if(k == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        int res = 0;
        for(int i = 0; i<=min(n-1, k); i++){
            res = (res+helper(n-1, k-i, dp))%1000000007;
        }
        return dp[n][k] = res;
    }
    
    int kInversePairs(int n, int k) {
        // dp[i][j] = number of ways to arrange [1..i] with exactly j inversions
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return helper(n, k, dp);
    }
};

// Alternate Code:

#define MOD 1000000007

class Solution {
    int helper(int n, int k, vector<vector<int>>& dp){
        if(n == 0){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }

        long res = 0;

        int minK = max(k-(n-1), 0);
        int maxK = min(k, ((n-1)*n)/2);

        for(int i=minK; i<=maxK; i++){
            res = (res + helper(n-1, i, dp)) % MOD;
        }
        return dp[n][k] = res;
    }
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return helper(n, k, dp);
    }
};
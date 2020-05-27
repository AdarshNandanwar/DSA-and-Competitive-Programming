// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

// Method 1(1D DP):

#define MOD 1000000007
class Solution {
public:
    int countOrders(int n) {
        long long int prev = 1;
        for(int i=2; i<=n; i++)
            prev = (i*(2*i-1)*prev)%MOD;
        return prev;
    }
};

// Without State Save Optimization

#define MOD 1000000007
class Solution {
public:
    int countOrders(int n) {
        vector<long long int> dp(n+1,0);
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = ((((i%MOD)*((2*i-1)%MOD))%MOD)*(dp[i-1]%MOD))%MOD;
        }
        return dp[n];
    }
};

// Method 2 (2D DP):

#define MOD 1000000007

class Solution {
public:
    int countOrders(int n) {
        // dp[i][j] is number of ways in which i orders are picked and j orders are delivered
        vector<vector<long long int>> dp(n+1, vector<long long int>(n+1, 0));
        dp[0][0]= 1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=i; j++){
                if(j-1>=0){
                    dp[i][j] = (( ((n-i+1)%MOD) * (dp[i-1][j]%MOD) )%MOD + ( ((i-j+1)%MOD) * (dp[i][j-1]%MOD) )%MOD)%MOD;
                } else {
                    dp[i][j] = (((n-i+1)%MOD)*(dp[i-1][j]%MOD))%MOD;
                }
            }
        }
        return dp[n][n];
    }
};
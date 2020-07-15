// 

// Method 1 (DP, O(n2)):

class Solution {
public:
    
    int maxProfitBigK(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int right = n-1, left = n-1, ans = 0;
        for(int i = n-2; i>=0; i--){
            if(prices[i] <= prices[i+1]) left = i;
            else {
                ans += (prices[right]-prices[left]);
                right = left = i;
            }
        }
        ans += (prices[right]-prices[left]);
        return ans;
    }
    
    int maxProfit(int K, vector<int>& prices) {        
        int n = prices.size(), c =1;
        if(n <= 1) return 0;
        
        
        if(K >= n/2){
            
            return maxProfitBigK(prices);
            
        } else {
            
//             vector<vector<vector<int>>> dp(n, vector<vector<int>>(K+1, vector<int>(c+1, 0)));

//             // transaction begins at buy
//             // dp[i][j][k] = max profit in [0,i] with at most j transactions and k stock currently bought
//             // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
//             // dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);

//             // base case
//             for(int i=1; i<=K; i++) dp[0][i][1] = -prices[0];

//             for(int i = 1; i<n; i++){
//                 for(int j = 1; j<=K; j++){
//                     dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
//                     dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
//                 }
//             }

//             return dp[n-1][K][0];
            
            
            
            
            
            
            // STATE SPACE OPTIMIZATION
        

            vector<vector<vector<int>>> dp(2, vector<vector<int>>(K+1, vector<int>(c+1, 0)));

            // transaction begins at buy
            // dp[i][j][k] = max profit in [0,i] with at most j transactions and k stock currently bought
            // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
            // dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);

            // base case
            for(int i=1; i<=K; i++) dp[0%2][i][1] = -prices[0];

            for(int i = 1; i<n; i++){
                for(int j = 1; j<=K; j++){
                    dp[i%2][j][0] = max(dp[(i-1)%2][j][0], dp[(i-1)%2][j][1]+prices[i]);
                    dp[i%2][j][1] = max(dp[(i-1)%2][j][1], dp[(i-1)%2][j-1][0]-prices[i]);
                }
            }

            return dp[(n-1)%2][K][0];
               
        }
    }
};
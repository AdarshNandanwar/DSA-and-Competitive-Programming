// https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(), prev, next, temp;
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // in [i..j], we burst index-k in the last
        // so, we first solve the subproblems [i..k-1] and [k+1..j]
        // in which it is ensured that the kth balloon is not bursted
        
        // dp[i][j] =  k:i->j max(dp[i][k-1] + nums[k]*prev*next + dp[k+1][j])
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<n; j++){
                prev = (i-1 == -1)?1:nums[i-1];
                next = (j+1 == n)?1:nums[j+1];
                for(int k=i; k<=j; k++){
                    temp = nums[k]*prev*next;
                    if(k-1 >= i)
                        temp += dp[i][k-1];
                    if(k+1 <= j)
                        temp += dp[k+1][j];
                    
                    dp[i][j] = max(dp[i][j], temp);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
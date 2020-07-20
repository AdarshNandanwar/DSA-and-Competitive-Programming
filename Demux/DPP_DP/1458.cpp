// https://leetcode.com/problems/max-dot-product-of-two-subsequences/

// Method 1 (Not verbose):

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        // similar to https://leetcode.com/problems/edit-distance/
        
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -10e7));
        
        for(int i1 = n1-1; i1>=0; i1--){
            for(int i2 = n2-1; i2>=0; i2--){
                
                // include this pair
                dp[i1][i2] = nums1[i1]*nums2[i2];
                if(i1+1 < n1 and i2+1 < n2) dp[i1][i2] += max(0, dp[i1+1][i2+1]);
                
                // exclude this pair
                if(i1+1 < n1) dp[i1][i2] = max(dp[i1][i2], dp[i1+1][i2]);
                if(i2+1 < n2) dp[i1][i2] = max(dp[i1][i2], dp[i1][i2+1]);
            }
        }
        
        return dp[0][0];
    }
};
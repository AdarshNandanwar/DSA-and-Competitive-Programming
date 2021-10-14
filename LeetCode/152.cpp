// https://leetcode.com/problems/maximum-product-subarray/

// Method 1 (DP, O(n)):

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = dp[1][0] = nums[0];
        for(int i=1; i<n; i++){
            dp[0][i] = min(nums[i], min(dp[0][i-1]*nums[i], dp[1][i-1]*nums[i]));
            dp[1][i] = max(nums[i], max(dp[0][i-1]*nums[i], dp[1][i-1]*nums[i]));
            res = max(res, max(dp[0][i], dp[1][i]));
        }
        return res;
    }
};

// Method 2:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxProd = 0;
        vector<int> maxP(n, 0);     // pos
        vector<int> minP(n, 0);     // neg
        
        maxProd = maxP[0] = minP[0] = nums[0];
        for(int i=1; i<n; i++){
            maxP[i] = max(nums[i], max(nums[i]*maxP[i-1], nums[i]*minP[i-1]));
            minP[i] = min(nums[i], min(nums[i]*maxP[i-1], nums[i]*minP[i-1]));
            maxProd = max(maxProd, maxP[i]);
        }
        return maxProd;
    }
};

// Method 3:

class Product{
    public:
    int maxPos = 0;
    int maxNeg = 0;
    Product(){
        maxPos = maxNeg = 0;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxProd = INT_MIN;
        if(n == 0) return 0;
        // <pos, neg>
        Product p;
        vector<Product> dp(n, p);
        if(nums[0] > 0){
            dp[0].maxPos = nums[0];
        } else if (nums[0]<0){
            dp[0].maxNeg = nums[0];
        }
        maxProd = nums[0];
        for(int i =1; i<n; i++){
            if(nums[i] > 0){
                dp[i].maxPos = max(nums[i], nums[i]*dp[i-1].maxPos);
                dp[i].maxNeg = nums[i]*dp[i-1].maxNeg;
            } else if (nums[i]<0){
                dp[i].maxPos = nums[i]*dp[i-1].maxNeg;
                dp[i].maxNeg = min(nums[i], nums[i]*dp[i-1].maxPos);
            } else {
                dp[i].maxPos = 0;
                dp[i].maxNeg = 0;
            }
            maxProd = max(maxProd, dp[i].maxPos);
        }
        return maxProd;
    }
};
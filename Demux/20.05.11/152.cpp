// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxProd = 0;
        // product of longest subarray ending at i
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

// Longer code for same logic

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

// Same code with some other useless variables

class Product{
    public:
    int maxPos = 0;
    int minPos = 0;
    int maxNeg = 0;
    int minNeg = 0;
    Product(){
        maxPos = minPos = maxNeg = minNeg = 0;
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
            dp[0].maxPos = dp[0].minPos = nums[0];
        } else if (nums[0]<0){
            dp[0].maxNeg = dp[0].minNeg = nums[0];
        }
        maxProd = nums[0];
        // cout<<dp[0].maxPos<<" "<<dp[0].minPos<<" "<<dp[0].maxNeg<<" "<<dp[0].minNeg<<endl;
        for(int i =1; i<n; i++){
            if(nums[i] > 0){
                dp[i].maxPos = max(nums[i], nums[i]*dp[i-1].maxPos);
                dp[i].minPos = min(nums[i], nums[i]*dp[i-1].minPos);
                dp[i].maxNeg = nums[i]*dp[i-1].maxNeg;
                dp[i].minNeg = nums[i]*dp[i-1].minNeg;
                maxProd = max(maxProd, dp[i].maxPos);
                if(dp[i].minNeg) maxProd = max(maxProd, dp[i].minNeg);
            } else if (nums[i]<0){
                dp[i].maxPos = nums[i]*dp[i-1].maxNeg;
                dp[i].minPos = nums[i]*dp[i-1].minNeg;
                dp[i].maxNeg = min(nums[i], nums[i]*dp[i-1].maxPos);
                dp[i].minNeg = max(nums[i], nums[i]*dp[i-1].minPos);
                maxProd = max(maxProd, dp[i].minNeg);
                if(dp[i].maxPos) maxProd = max(maxProd, dp[i].maxPos);
            } else {
                dp[i].maxPos = 0;
                dp[i].minPos = 0;
                dp[i].maxNeg = 0;
                dp[i].minNeg = 0;
            }
            // cout<<dp[i].maxPos<<" "<<dp[i].minPos<<" "<<dp[i].maxNeg<<" "<<dp[i].minNeg<<endl;
        }
        return maxProd;
    }
};
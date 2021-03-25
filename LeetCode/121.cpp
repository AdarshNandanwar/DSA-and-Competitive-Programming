// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0, maxSuffix = INT_MIN;
        for(int i = n-2; i>=0; i--){
            maxSuffix = max(maxSuffix, prices[i+1]);
            ans = max(ans, maxSuffix-prices[i]);
        }
        return ans;
    }
};
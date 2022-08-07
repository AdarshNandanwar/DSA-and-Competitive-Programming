// https://leetcode.com/problems/min-cost-climbing-stairs/

// Method 1 (O(n) time, O(1) space):

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), prev = cost[1], prevPrev = cost[0];
        for(int i=2; i<n; i++){
            int cur = cost[i] + min(prev, prevPrev);
            prevPrev = prev;
            prev = cur;
        }
        return min(prev, prevPrev);
    }
};

// Method 2 (1D DP, O(n)):

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // dp[i] = min cost to reach index i
        vector<int> dp(cost);
        for(int i=2; i<n; i++){
            dp[i] = cost[i]+min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};

// Alternate Code:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        dp[n-1] = cost[n-1];
        for(int i = n-2; i>=0; i--){
            dp[i] = cost[i]+min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
};
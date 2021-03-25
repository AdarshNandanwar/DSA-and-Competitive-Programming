// https://leetcode.com/problems/minimum-cost-for-tickets/

// Method 1 (DP, O(30*n)):

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // dp[i] = min cost for [i..n-1]
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        for(int i = n-1; i>=0; i--){
            int j = i+1;
            while(j<n and days[j]-days[i]<1) j++;
            dp[i] = min(dp[i], costs[0]+dp[j]);
            while(j<n and days[j]-days[i]<7) j++;
            dp[i] = min(dp[i], costs[1]+dp[j]);
            while(j<n and days[j]-days[i]<30) j++;
            dp[i] = min(dp[i], costs[2]+dp[j]);
        }
        for(auto i:dp) cout<<i<<" ";
        return dp[0];
    }
};
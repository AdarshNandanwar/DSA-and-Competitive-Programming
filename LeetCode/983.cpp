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

// Method 2 (2D DP, O(nlogn)):

class Solution {
    int helper(int index, const vector<int>& days, const vector<int>& costs, vector<int> & dp){
        int n = days.size();
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int curDay = days[index];
        int res = INT_MAX;
        int nextIndex = n;

        nextIndex = lower_bound(days.begin() + index, days.end(), curDay + 1) - days.begin();
        res = min(res, helper(nextIndex, days, costs, dp) + costs[0]);
        nextIndex = lower_bound(days.begin() + index, days.end(), curDay + 7) - days.begin();
        res = min(res, helper(nextIndex, days, costs, dp) + costs[1]);
        nextIndex = lower_bound(days.begin() + index, days.end(), curDay + 30) - days.begin();
        res = min(res, helper(nextIndex, days, costs, dp) + costs[2]);

        return dp[index] = res;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return helper(0, days, costs, dp);
    }
};

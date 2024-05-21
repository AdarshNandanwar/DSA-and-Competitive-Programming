// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

// Method 1 (1D DP, Binary Search, O(nlogn)):

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n+1);
        dp[n] = 0;
        
        for(int i=n-1; i>=0; i--){
            dp[i] = dp[i+1];
            int curEndTime = jobs[i][1];
            int curProfit = jobs[i][2];
            vector<int> nextPossibleJob = {curEndTime, 0, 0};
            auto nextJobIndex = lower_bound(jobs.begin(), jobs.end(), nextPossibleJob)-jobs.begin();
            dp[i] = max(dp[i], curProfit + dp[nextJobIndex]);
        }

        return dp[0];
    }
};

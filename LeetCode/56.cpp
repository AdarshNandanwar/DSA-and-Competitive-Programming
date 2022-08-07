// https://leetcode.com/problems/merge-intervals/

// Method 1 (Sorting, O(n)):

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int curStart = intervals[0][0], curEnd = intervals[0][1];
        for(auto &interval:intervals){
            if(interval[0] > curEnd){
                ans.push_back({curStart, curEnd});
                curStart = interval[0];
            }
            curStart = min(curStart, interval[0]);
            curEnd = max(curEnd, interval[1]);
        }
        ans.push_back({curStart, curEnd});
        return ans;
    }
};
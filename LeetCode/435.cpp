// https://leetcode.com/problems/non-overlapping-intervals/

// Method 1 (Greedy, O(nlogn)):

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int curEnd = INT_MIN, count = 0;
        for(auto i:intervals){
            if(i[0] < curEnd){
                count++;
                // erasing the bigger interval among prev and cur
                curEnd = min(curEnd, i[1]);
            } else {
                curEnd = i[1];
            }
        }
        return count;
    }
};
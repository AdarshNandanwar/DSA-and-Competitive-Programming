// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

// Method 1 (Min Heap, O(n)):

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> endTimes;

        int maxOverlap = 0;
        for(auto interval:intervals){
            while(!endTimes.empty() and endTimes.top() < interval[0]){
                endTimes.pop();
            }
            endTimes.push(interval[1]);
            maxOverlap = max(maxOverlap, (int)endTimes.size());
        }

        return maxOverlap;
    }
};

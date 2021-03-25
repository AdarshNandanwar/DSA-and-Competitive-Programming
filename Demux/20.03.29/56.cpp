// https://leetcode.com/problems/merge-intervals/

bool comp(vector<int> &a, vector<int> &b){
    return a[0]<b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        vector<int> curr = intervals[0];
        for(int i = 1; i<intervals.size(); i++){
            if(curr[1] >= intervals[i][0]){
                curr[1] = max(curr[1], intervals[i][1]);
            } else {
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};
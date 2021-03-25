// https://leetcode.com/problems/find-right-interval/

// Method 1 (Sorting, Hash Table, O(nlogn)): 

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> orig(intervals.begin(), intervals.end());
        int n = intervals.size();
        // {start, index}
        unordered_map<int, int> m;
        for(int i = 0; i<n; i++) m[intervals[i][0]] = i;
        sort(intervals.begin(), intervals.end());
        vector<int> res;
        for(int i = 0; i<n; i++){
            vector<int> target = {orig[i][1], orig[i][1]};
            int ind = lower_bound(intervals.begin(), intervals.end(), target)-intervals.begin();
            if(ind == n) res.push_back(-1);
            else res.push_back(m[intervals[ind][0]]);
        }
        return res;
    }
};

// Method 2 (Sorting, O(nlogn)):

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> v(intervals.begin(), intervals.end());
        for(int i = 0; i<n; i++) v[i].push_back(i);
        sort(v.begin(), v.end());
        vector<int> res;
        for(int i = 0; i<n; i++){
            vector<int> target = {intervals[i][1], intervals[i][1], 0};
            int ind = lower_bound(v.begin(), v.end(), target)-v.begin();
            if(ind == n){
                res.push_back(-1);
            } else {
                res.push_back(v[ind][2]);
            }
        }
        return res;
    }
};
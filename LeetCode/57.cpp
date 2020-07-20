// https://leetcode.com/problems/insert-interval/

// Method 1 (Clean, O(n)):

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) return {newInterval};
        
        // To ensure last interval is inserted
        intervals.push_back({INT_MIN, INT_MIN});
        
        vector<vector<int>> res;
        vector<int> prev = intervals[0];
        bool added = false;
        for(auto cur:intervals){
            
            // merging prev interval with newInterval
            if(!(prev[1] < newInterval[0] or newInterval[1] < prev[0])){
                prev[0] = min(newInterval[0], prev[0]);
                prev[1] = max(newInterval[1], prev[1]);
                added = true;
            } 
            
            // merging prev interval with cur interval
            if(!(prev[1] < cur[0] or cur[1] < prev[0])){
                prev[0] = min(cur[0], prev[0]);
                prev[1] = max(cur[1], prev[1]);
            } else {
                if(!added and newInterval[0] < prev[0]){
                    res.push_back(newInterval);
                    added = true;
                } 
                res.push_back(prev);
                prev = cur;
            }
        }
        
        if(!added) res.push_back(newInterval);
        return res;
    }
};

// Method 1 (Unclean code):

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) return {newInterval};
        vector<vector<int>> res;
        vector<int> cur = intervals[0];
        bool added = false;
        for(auto i:intervals){
            if(!(cur[1] < newInterval[0] or newInterval[1] < cur[0])){
                cur[0] = min(newInterval[0], cur[0]);
                cur[1] = max(newInterval[1], cur[1]);
                added = true;
            } 
            if(!(cur[1] < i[0] or i[1] < cur[0])){
                cur[0] = min(i[0], cur[0]);
                cur[1] = max(i[1], cur[1]);
            } else {
                if(!added and newInterval[0] < cur[0]){
                    res.push_back(newInterval);
                    added = true;
                } 
                res.push_back(cur);
                cur = i;
            }
        }
        if(!(cur[1] < newInterval[0] or newInterval[1] < cur[0])){
            cur[0] = min(newInterval[0], cur[0]);
            cur[1] = max(newInterval[1], cur[1]);
            added = true;
        } 
        if(!added and newInterval[0] < cur[0]){
            res.push_back(newInterval);
            added = true;
        }
        res.push_back(cur);
        if(!added) res.push_back(newInterval);
        return res;
    }
};
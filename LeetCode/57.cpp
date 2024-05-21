// https://leetcode.com/problems/insert-interval/

// Method 1 (Merging in loop, O(n)):

class Solution {
    bool isOverlap(const vector<int> & a, const vector<int> & b){
        return !(a[1] < b[0] or a[0] > b[1]);
    }
    vector<int> merge(const vector<int> & a, const vector<int> & b){
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        bool added = false;
        for(int i=0; i<n; i++){
            if(isOverlap(intervals[i], newInterval)){
                vector<int> mergedInterval = merge(intervals[i], newInterval);
                while(i+1<n and isOverlap(intervals[i+1], newInterval)){
                    mergedInterval = merge(mergedInterval, intervals[i+1]);
                    i++;
                }
                res.push_back(mergedInterval);
                added = true;
            } else {
                if(!added and newInterval[0] < intervals[i][0]){
                    res.push_back(newInterval);
                    added = true;
                }
                res.push_back(intervals[i]);
            }
        }
        if(!added){
            res.push_back(newInterval);
        }
        return res;
    }
};

// Alternate Code:

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

// Alternate Code (Unclean):

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

// Method 2 (Find interval, O(n)):

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0){
            return {newInterval};
        }

        // Insert at start?
        if(newInterval[1] < intervals[0][0]){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }

        // Insert at end?
        if(newInterval[0] > intervals[n-1][1]){
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> res;
        int startIndex = -1;
        int endIndex = -1;
        for(int i=0; i<n; i++){
            if(startIndex == -1 and newInterval[0] <= intervals[i][1]){
                startIndex = i;
            }
            if(newInterval[1] >= intervals[i][0]){
                endIndex = i;
            }
        }
        
        for(int i=0; i<startIndex; i++){
            res.push_back(intervals[i]);
        }
        newInterval[0] = min(newInterval[0], intervals[startIndex][0]);
        newInterval[1] = max(newInterval[1], intervals[endIndex][1]);
        res.push_back(newInterval);
        for(int i=endIndex+1; i<n; i++){
            res.push_back(intervals[i]);
        }

        return res;
    }
};

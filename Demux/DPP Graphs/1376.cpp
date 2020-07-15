// https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    
    int getTime(int & n, vector<vector<int>> & sub, vector<int>& manager, vector<int>& informTime, int cur){
        int time = 0;
        for(auto s:sub[cur]){
            time = max(time, informTime[cur]+getTime(n, sub, manager, informTime, s));
        }
        return time;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> sub(n);
        for(int i=0; i<n; i++) if(manager[i] != -1) sub[manager[i]].push_back(i);        
        return getTime(n, sub, manager, informTime, headID);
    }
};
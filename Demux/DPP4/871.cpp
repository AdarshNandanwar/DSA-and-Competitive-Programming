// https://leetcode.com/problems/minimum-number-of-refueling-stops/

// Method 1 (Priority Queue, Max Heap):

class Solution {
public:
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {     
        int n = stations.size();
        int maxPos = startFuel;
        int index = 0;
        int count = 0;
        priority_queue<int, vector<int>> gasAvailable;
        
        while(true){
            while(index<n and stations[index][0]<=maxPos){
                gasAvailable.push(stations[index][1]);
                index++;
            }
            if(maxPos >= target){ 
                return count;
            }
            
            if(!gasAvailable.empty()){
                maxPos += gasAvailable.top();
                gasAvailable.pop();
                count++;
            } else {
                return -1;
            }
        }        
    }
};

// TLE (O(500*fuel)):

class Solution {
public:
    
    int solve(int & target, int pos, int fuel, vector<vector<int>> & stations, int index, vector<unordered_map<int, int>> & dp){
        if(target-pos <= fuel){
            return 0;
        }
        
        if(index >= stations.size()) return 10e3;
        
        if(dp[index].count(fuel)) return dp[index][fuel];
        
        int n = stations.size(), fuelReq, res = 10e3;
        for(int i = index; i<n; i++){
            fuelReq = stations[i][0]-pos;
            if(fuelReq > fuel) break;
            res = min(res, 1+solve(target, stations[i][0], fuel-fuelReq+stations[i][1], stations, i+1, dp));
        }
        return dp[index][fuel] = res;
    }
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(target <= startFuel) return 0;
        // ALREADY SORTED
        // sort(stations.begin(), stations.end(), [](const vector<int> & a, const vector<int> & b){
        //     if(a[0] == b[0]) return a[1]>b[1];
        //     else return a[0]<b[0];
        // });
        vector<unordered_map<int, int>> dp(stations.size());
        int res = solve(target, 0, startFuel, stations, 0, dp);
        return res>=10e3?-1:res;
    }
};
// https://leetcode.com/problems/minimum-number-of-refueling-stops/

// Method 1 (Max Heap):

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int, vector<int>> pq;
        int cur_range = startFuel, next_range = startFuel, count = 0, index = 0, n = stations.size();
        while(cur_range < target){
            while(index < n and stations[index][0] <= cur_range){
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty()) return -1;
            cur_range += pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};
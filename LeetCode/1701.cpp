// https://leetcode.com/problems/average-waiting-time/

// Method 1 (Greedy, O(n)):

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int nextFree = 0, n = customers.size();
        double totalWaitTime = 0;
        for(int i=0; i<n; i++){
            int waitTime = max(nextFree, customers[i][0]) + customers[i][1] - customers[i][0];
            totalWaitTime += waitTime;
            nextFree = customers[i][0] + waitTime;
        }
        return totalWaitTime/n;
    }
};

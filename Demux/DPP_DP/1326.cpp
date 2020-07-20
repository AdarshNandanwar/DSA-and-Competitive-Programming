// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

// Method 1 (DP, O(n)):

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        // similar to Jump Game II
        // implicit BFS
        
        unordered_map<int, int> maxRight;
        for(int i = 0; i<n+1; i++) maxRight[max(0, i-ranges[i])] = max(maxRight[max(0, i-ranges[i])], min(n, i+ranges[i]));
        
        int curRight = 0, maxChildRight = 0, count = 0;
        for(int i = 0; i<n; i++){
            maxChildRight = max(maxChildRight, maxRight[i]);
            if(maxChildRight >= n) return count+1;
            if(i == curRight){
                if(curRight == maxChildRight) return -1;
                curRight = maxChildRight;
                count++;
            }            
        }
        return -1;
    }
};
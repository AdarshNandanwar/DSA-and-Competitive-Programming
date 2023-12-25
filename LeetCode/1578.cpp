// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

// Method 1 (O(n)):

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length(), cost = 0, curMaxCost = neededTime[0], curSum = neededTime[0], curLength = 1;
        for(int i=1; i<n; i++){
            if(colors[i] != colors[i-1]){
                if(curLength>1){
                    cost += (curSum-curMaxCost);
                }
                curMaxCost = neededTime[i];
                curSum = neededTime[i];
                curLength = 1;
            } else {
                curMaxCost = max(curMaxCost, neededTime[i]);
                curSum += neededTime[i];
                curLength++;
            }
        }
        if(curLength>1){
            cost += (curSum-curMaxCost);
        }
        return cost;
    }
};
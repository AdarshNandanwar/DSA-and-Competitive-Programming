// https://leetcode.com/problems/paint-house-iii/

// Method 1 (3D DP, O(m*n*target)):

class Solution {
    int helper(vector<int>& houses, vector<vector<int>>& cost, int houseNumber, int curPaint, int neighborhoods, vector<vector<vector<int>>>& dp){
        
        int paintsCount = cost[0].size();
        
        if(houseNumber <= 0){
            if(neighborhoods <= 0){
                return 0;
            } else {
                return 1e7;
            }
        }
        
        if(neighborhoods <= 0){
            return 1e7;
        }
        
        if(houses[houseNumber-1] != 0 and houses[houseNumber-1] != curPaint){
            return 1e7;
        }
        
        if(dp[houseNumber][curPaint][neighborhoods] != INT_MAX){
            return dp[houseNumber][curPaint][neighborhoods];
        }
        
        int curPaintingCost = 0;
        if(houses[houseNumber-1] == 0){
            curPaintingCost = cost[houseNumber-1][curPaint-1];
        }
        
        int res = 1e7;
        
        res = min(res, curPaintingCost + helper(houses, cost, houseNumber-1, curPaint, neighborhoods, dp));

        for(int paint=1; paint<=paintsCount; paint++){
            if(paint == curPaint){
                continue;
            }
            res = min(res, curPaintingCost + helper(houses, cost, houseNumber-1, paint, neighborhoods-1, dp));
        }
        
        return dp[houseNumber][curPaint][neighborhoods] = res;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[i][j][k] = min cost to paint the first i houses with ith house painted j such that we have k neighborhoods
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(target+1, INT_MAX)));
        int res = INT_MAX;
        for(int paint = 1; paint<=n; paint++){
            res = min(res, helper(houses, cost, m, paint, target, dp));
        }
        return res>=1e7 ? -1 : res;
    }
};
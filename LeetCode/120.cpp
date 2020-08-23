// https://leetcode.com/problems/triangle/

// Method 1 (DP, O(n2) time, O(n) space):

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        // dp[i][j] = min path sum from bottom to row i
        vector<vector<int>> dp(2, vector<int>(n, 0));
        // base case
        dp[(n-1)%2] = triangle[n-1];
        for(int i = n-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                dp[i%2][j] = triangle[i][j]+min(dp[(i+1)%2][j], dp[(i+1)%2][j+1]);
            }
        }
        return dp[0][0];
    }
};

// Method 2 (DP, O(n2) time, O(n2) space):

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        // dp[i][j] = min path sum from bottom to row i
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // base case
        dp[n-1] = triangle[n-1];
        for(int i = n-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                dp[i][j] = triangle[i][j]+min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
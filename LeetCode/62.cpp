// https://leetcode.com/problems/unique-paths/

// Method 1 (Math Permutation, O(min(m+n))):

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n == 0 or m == 0) return 0;
        if(n == 1 or m == 1) return 1;
        n--; m--;
        // (n+m)! / (n! * m!)
        long long res = 1;
        for(int i = n+m; i>max(n, m); i--) res *= i;
        for(int i = min(n, m); i>=1; i--) res /= i;
        return res;
    }
};

// Method 2 (DP, O(mn)):

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
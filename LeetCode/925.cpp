// https://leetcode.com/problems/long-pressed-name/

// Method 1 (2 pointers, O(n+m)):

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size();
        int p1  = 0, p2 = 0;
        while(1){
            if(p1 == n and p2 == m) return 1;
            if(p1>=n or p2>=m or name[p1] != typed[p2]) return 0;
            while(p1<n and p2<m and name[p1] == typed[p2]){
                p1++;
                p2++;
            }
            while(p2<m and name[p1-1] == typed[p2]) p2++;
        }
        return 1;
    }
};

// Method 2 (DP, O(n*m)):

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.length(), m = typed.length();
        // dp[i][j] = is Possible in name[i..n-1] and typed[j..m-1]
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
        dp[n][m] = 1;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(name[i] == typed[j]) dp[i][j] = dp[i][j+1] or dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};
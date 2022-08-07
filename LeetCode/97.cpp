// https://leetcode.com/problems/interleaving-string/

// Method 1 (Bottom Up DP, O(n2)):

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1+l2 != l3) return false;
        
        // dp[i][j] = can s3[i+j:] be formed by interleaving s1[i:] and s2[j:]
        vector<vector<bool>> dp(l1+1, vector<bool>(l2+1, false));
        
        // base case
        dp[l1][l2] = true;
        for(int i = 1; i<=l1; i++){
            if(s1[l1-i] != s3[l3-i]) break;
            dp[l1-i][l2] = true;
        }
        for(int j = 1; j<=l2; j++){
            if(s2[l2-j] != s3[l3-j]) break;
            dp[l1][l2-j] = true;
        }
        
        for(int j = l2-1; j>=0; j--){
            for(int i = l1-1; i>=0; i--){
                if(s1[i] == s3[i+j]) dp[i][j] = dp[i][j] or dp[i+1][j];
                if(s2[j] == s3[i+j]) dp[i][j] = dp[i][j] or dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};

// Alternate Code

class Solution {
public:
    bool isInterleave(string A, string B, string C) {
        int na = A.length(), nb = B.length(), nc = C.length();
        if(na+nb != nc) return 0;

        // dp[i][j] = does A[i..na-1] and B[j..nb-1] interleave to make C[i+j..na+nb-1]
        vector<vector<bool>> dp(na+1, vector<bool>(nb+1, 0));

        // base cases
        dp[na][nb] = 1;
        for(int i = na-1; i>=0; i--){
            dp[i][nb] = dp[i+1][nb];
            if(A[i] != C[nb+i]) dp[i][nb] = 0;
        }
        for(int i = nb-1; i>=0; i--){
            dp[na][i] = dp[na][i+1];
            if(B[i] != C[na+i]) dp[na][i] = 0;
        }

        for(int i = na-1; i>=0; i--){
            for(int j = nb-1; j>=0; j--){
                if(A[i] == C[i+j]) dp[i][j] = dp[i][j] or dp[i+1][j];
                if(B[j] == C[i+j]) dp[i][j] = dp[i][j] or dp[i][j+1];
            }
        }

        return dp[0][0];        
    }
};

// Method 2 (Top Down DP, O(n2)):

class Solution {
public:
    
    bool helper(int i, int j, string & s1, string & s2, string & s3, vector<vector<int>> & dp){
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        int k = i+j;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == l1) return dp[i][j] = s2.substr(j)==s3.substr(k);
        if(j == l2) return dp[i][j] = s1.substr(i)==s3.substr(k);
        
        bool res = 0;
        if(s1[i] == s3[k]) res = res or helper(i+1, j, s1, s2, s3, dp);
        if(res) return dp[i][j] = res;
        if(s2[j] == s3[k]) res = res or helper(i, j+1, s1, s2, s3, dp);
        return dp[i][j] = res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1+l2 != l3) return false;
        
        // dp[i][j] = can s3[i+j:] be formed by interleaving s1[i:] and s2[j:]
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
        
        return helper(0, 0, s1, s2, s3, dp);
    }
};

// Method 3 (Top Down DP, O(n3)):

class Solution {
public:
    
    bool helper(int i, int j, int k, string & s1, string & s2, string & s3, vector<vector<vector<int>>> & dp){
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(k == l3) return dp[i][j][k] = (!(i|j));
        if(i == l1) return dp[i][j][k] = s2.substr(j)==s3.substr(k);
        if(j == l2) return dp[i][j][k] = s1.substr(i)==s3.substr(k);
        
        bool res = 0;
        if(s1[i] == s3[k]) res = res or helper(i+1, j, k+1, s1, s2, s3, dp);
        if(res) return dp[i][j][k] = res;
        if(s2[j] == s3[k]) res = res or helper(i, j+1, k+1, s1, s2, s3, dp);
        return dp[i][j][k] = res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1+l2 != l3) return false;
        
        // dp[i][j][k] = can s3[k:] be formed by interleaving s1[i:] and s2[j:]
        vector<vector<vector<int>>> dp(l1+1, vector<vector<int>>(l2+1, vector<int>(l3+1, -1)));
        
        return helper(0, 0, 0, s1, s2, s3, dp);
    }
};

// Method 4 (Bottom Up DP, O(n3)):

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1+l2 != l3) return false;
        
        // dp[i][j][k] = can s3[k:] be formed by interleaving s1[i:] and s2[j:]
        vector<vector<vector<bool>>> dp(l1+1, vector<vector<bool>>(l2+1, vector<bool>(l3+1, false)));
        
        // base case
        // k = l3
        dp[l1][l2][l3] = true;
        // j = l2
        for(int i = 1; i<=l1; i++){
            if(s1[l1-i] != s3[l3-i]) break;
            dp[l1-i][l2][l3-i] = true;
        }
        // i = l1
        for(int j = 1; j<=l2; j++){
            if(s2[l2-j] != s3[l3-j]) break;
            dp[l1][l2-j][l3-j] = true;
        }
        
        for(int k = l3-1; k>=0; k--){
            for(int j = l2-1; j>=0; j--){
                for(int i = l1-1; i>=0; i--){
                    if(s1[i] == s3[k]) dp[i][j][k] = dp[i][j][k] or dp[i+1][j][k+1];
                    if(s2[j] == s3[k]) dp[i][j][k] = dp[i][j][k] or dp[i][j+1][k+1];
                }
            }
        }
        
        return dp[0][0][0];
    }
};

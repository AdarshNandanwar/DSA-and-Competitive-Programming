// https://leetcode.com/problems/shortest-common-supersequence/

// Method 1 (LCS, O(n*m)):

class Solution {
public:
    
    string longestCommonSubsequence(string & s1, string & s2){      
        int n = s1.length(), m = s2.length();
        vector<vector<string>>  dp(n+1, vector<string>(m+1, ""));
        
        // dp[i][j] = lcs of s1[i..n-1] and s2[j..m-1]
        
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = string(1, s1[i])+dp[i+1][j+1];
                } else {
                    string t1 = dp[i+1][j];
                    string t2 = dp[i][j+1];
                    dp[i][j] = t1.length() >= t2.length() ? t1 : t2;
                }
            }
        }
        return dp[0][0];
    }
    
    string shortestCommonSupersequence(string s1, string s2) { 
        string lcs = longestCommonSubsequence(s1, s2);
        string res = "";
        int n = s1.length(), m = s2.length(), k = lcs.length(), p1 = 0, p2 = 0, p3 = 0;
        for(auto c:lcs){
            while(s1[p1] != c) res.push_back(s1[p1++]);
            while(s2[p2] != c) res.push_back(s2[p2++]);
            res.push_back(c);
            p1++; 
            p2++; 
        }
        while(p1<n) res.push_back(s1[p1++]);
        while(p2<m) res.push_back(s2[p2++]);
        return res;
    }
};

// Method 2 (TLE, O(n*m*(n+m))):

class Solution {
public:
    
    string helper(string & str1, string & str2, int p1, int p2, unordered_map<string, string> & dp){
        int n = str1.length(), m = str2.length();
        
        if(p1 == n) return str2.substr(p2);
        if(p2 == m) return str1.substr(p1);
        
        string key = to_string(p1)+","+to_string(p2);
        if(dp.count(key)) return dp[key];
        
        string res;
        if(str1[p1] == str2[p2]){
            res = string(1, str1[p1]) + helper(str1, str2, p1+1, p2+1, dp);
        } else {
            string h1 = string(1, str1[p1]) + helper(str1, str2, p1+1, p2, dp);
            string h2 = string(1, str2[p2]) + helper(str1, str2, p1, p2+1, dp);
            res = h1.length() > h2.length() ? h2 : h1;
        }
        return dp[key] = res;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        unordered_map<string, string> dp;
        return helper(str1, str2, 0, 0, dp);
    }
};

// Method 3 (TLE, O(2^n)):

class Solution {
public:
    
    void helper(string & str1, string & str2, int p1, int p2, string cur, string & ans){
        int n = str1.length(), m = str2.length();
        
        if(p1 == n){
            string temp = cur+str2.substr(p2);
            if(ans.length() > temp.length()) ans = temp;
            return;
        }
        if(p2 == m){
            string temp = cur+str1.substr(p1);
            if(ans.length() > temp.length()) ans = temp;
            return;
        }
        
        if(str1[p1] == str2[p2]){
            helper(str1, str2, p1+1, p2+1, cur+str1[p1], ans);
        } else {
            helper(str1, str2, p1+1, p2, cur+str1[p1], ans);
            helper(str1, str2, p1, p2+1, cur+str2[p2], ans);
        }
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        string cur = "", ans = str1+str2;
        helper(str1, str2, 0, 0, cur, ans);
        return ans;
    }
};
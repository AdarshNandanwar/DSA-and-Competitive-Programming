// https://leetcode.com/problems/palindromic-substrings/

// Method 1 (2D DP, O(n2)):

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int counter = n;
        // dp[i][j] = is [i..j] a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = false;
                }
                if(dp[i][j]){
                    counter++;
                }  
            }
        }
        return counter;
    }
};

// Method 2 (2 pointer, O(n2)):

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), counter = 0;
        for(int i=0; i<n; i++){
            int left, right;
            left = i;
            right = i;
            while(left>=0 and right<n and s[left]==s[right]){
                counter++;
                left--;
                right++;
            }
            left = i;
            right = i+1;
            while(left>=0 and right<n and s[left]==s[right]){
                counter++;
                left--;
                right++;
            }
        }
        return counter;
    }
};

// Alternate Code:

class Solution {
public:
    
    int countSubstrings(string s) {
        int n = s.length(), res = 0;
        // odd
        for(int i = 0; i<n; i++){
            for(int j = 0; i-j>=0 and i+j<n; j++){
                if(s[i-j] != s[i+j]) break;
                res++;
            }
        }
        // even
        for(int i = 0; i<n-1; i++){
            for(int j = 0; i-j>=0 and i+1+j<n; j++){
                if(s[i-j] != s[i+1+j]) break;
                res++;
            }
        }
        return res;
    }
};
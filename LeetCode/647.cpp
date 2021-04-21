// https://leetcode.com/problems/palindromic-substrings/

// Method 1:

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
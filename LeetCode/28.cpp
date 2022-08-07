// https://leetcode.com/problems/implement-strstr/

// Method 1 (KMP Algorithm, O(n+m)):

class Solution {
public:
    vector<int> getLps(string s){
        int n = s.length();
        vector<int> lps(n, 0);
        int i = 1;
        int j = lps[i-1];
        while(i<n){
            if(s[i] == s[j]){
                lps[i] = j+1;
                i++;
                j = lps[i-1];
            } else {
                if(j > 0){
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(m == 0) return 0;
        vector<int> lps = getLps(needle);
        int i = 0;
        int j = 0;
        while(i<n and j<m){
            while(i<n and j<m and haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j == m){
                return i-m;
            }
            if(j > 0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
        return -1;
    }
};
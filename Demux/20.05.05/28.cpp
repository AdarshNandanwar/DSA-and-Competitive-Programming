// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    
    void generateLPS(string & pattern, vector<int> & lps){
        int n = pattern.size(), i, j;
        
        lps[0] = 0;
        i = 1;
        j = lps[i-1];
        
        while(i<n){
            if(pattern[i] == pattern[j]){
                lps[i] = j+1;
                i++;
                j = lps[i-1];
            } else {
                if(j == 0){
                    lps[i] = 0;
                    i++;
                } else {
                    j = lps[j-1];
                }
            }   
        }
    }
    
    int kmp(string & text, string & pattern, vector<int> & lps){
        int n = pattern.size(), m = text.size(), i, j;
        i = 0; j = 0;
        
        while(true){
            while(i<m and j<n and text[i] == pattern[j]){
                i++; j++;
            }
            
            if(j == n) return (i-j);
            
            if(i == m) return -1;
            
            if(j != 0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
        
    }
    
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int n = needle.size(), m = haystack.size();
        vector<int> lps(n, 0);
        generateLPS(needle, lps);
        return kmp(haystack, needle, lps);   
    }
};
// https://leetcode.com/problems/longest-palindromic-substring/

// Manacher's Algorithm (O(n)):

class Solution {
public:
    
    void modifyString(string & s, string & s1){
        s1 = "#";
        for(char c:s){
            s1 += c;
            s1 += "#";
        }
    }
    
    void manacher(string & s, vector<int> & lps, int & maxLen, int & maxC){
        int n = s.length(), i, c, r, upper, lower;
        
        // r is inclusive

        i = 1; c = 0; r = 0;
        while(i<n){
            
            int mirror = 2*c-i;
            
            // use mirroring if possible
            if(i<=r)
                lps[i] = min(lps[mirror], r-i);
            
            
            // expansion on both sides
            lower = i-lps[i]-1;
            upper = i+lps[i]+1;
            while(lower >= 0 and upper < n and s[lower] == s[upper]){
                lps[i]++;
                lower--;
                upper++;
            }
            
            // expand center if needed
            if(i+lps[i]>r){
                c = i;
                r = i+lps[i];
            }
            
            // update answer
            if(maxLen < lps[i]){
                maxLen = lps[i];
                maxC = i;
            }
            
            i++;
        }
    }
    
    string longestPalindrome(string s) {
        
        int n = s.length(), maxLen = 0, maxC = 0;
        string s1;
        
        if(n == 0)
            return "";
        
        modifyString(s, s1);
        
        vector<int> lps(s1.length(), 0);
        
        manacher(s1, lps, maxLen, maxC);
        
        return s.substr((maxC-maxLen)/2, maxLen);
    }
};

//  Method 2 (O(n2)):

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), i, j, maxLen = 1, maxC = 0;
        for(int c= 0; c<n; c++){
            
            // odd
            i = c-1; j = c+1;
            while(i>=0 and j<n and s[i]==s[j]){
                i--;
                j++;
            }
            if(maxLen < j-i-1){
                maxLen = j-i-1;
                maxC = c;
            }
            
            
            // even
            if(c+1<n and s[c]==s[c+1]){
                i = c-1; j = c+2;
                while(i>=0 and j<n and s[i]==s[j]){
                    i--;
                    j++;
                }
                if(maxLen < j-i-1){
                    maxLen = j-i-1;
                    maxC = c;
                }
                
            }
        }
        
        return s.substr(maxC-((maxLen-1)/2), maxLen);
        
    }
};
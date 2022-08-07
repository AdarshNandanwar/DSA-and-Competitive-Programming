// https://leetcode.com/problems/repeated-string-match/

// Method 1 (KMP Algorithm, O(n+m));

class Solution {
public:
    vector<int> getLps(string s){
        // get longest proper prefix which is also a proper suffix
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
                if(j == 0){
                    i++;
                } else {
                    j = lps[j-1];
                }
            }
        }
        return lps;
    }
    
    bool kmp(string s, string pattern){
        int n = s.length(), m = pattern.length();
        vector<int> lps = getLps(pattern);
        int i = 0, j = 0;
        while(i<n and j<m){
            while(i<n and j<m and s[i] == pattern[j]){
                i++;
                j++;
            }
            if(j == m){
                return true;
            }
            if(j == 0){
                i++;
            } else {
                j = lps[j-1];                
            }
        }
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
        int aLength = a.length(), bLength = b.length();
        
        int count = bLength/aLength;
        string aRepeated = "";
        for(int i=0; i<count; i++){
            aRepeated += a;
        }
        
        if(kmp(aRepeated, b)) return count;
        if(kmp(aRepeated+a, b)) return count+1;
        if(kmp(aRepeated+a+a, b)) return count+2;
        return -1;
    }
};

// Method 2 (STL Find, O(n+m));

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int aLength = a.length(), bLength = b.length();
        
        int repeat = 2+bLength/aLength;
        string aRepeated = "";
        for(int i=0; i<repeat; i++){
            aRepeated += a;
        }
        
        string option1 = aRepeated.substr(2*aLength);
        string option2 = aRepeated.substr(aLength);
        string option3 = aRepeated;
        if(option1.find(b) < option1.length()) return repeat-2;
        if(option2.find(b) < option2.length()) return repeat-1;
        if(option3.find(b) < option3.length()) return repeat;
        return -1;
    }
};
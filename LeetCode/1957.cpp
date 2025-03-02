// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

// Method 1 (Loops, O(n)):

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        int consecutiveCount = 1;
        string fancyString;
        fancyString += s[0];
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                consecutiveCount++;
            } else {
                consecutiveCount = 1;
            }
            if(consecutiveCount < 3){
                fancyString += s[i];
            }
        }
        return fancyString;
    }
};

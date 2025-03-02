// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

// Method 1 (Loop, O(n)):

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int count = 0;
        for(int i=1; i<n; i += 2){
            if(s[i] != s[i-1]){
                count++; 
            }
        }
        return count;
    }
};

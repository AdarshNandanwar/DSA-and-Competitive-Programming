// https://leetcode.com/problems/rotate-string/

// Method 1 (Loops, O(n2)):

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        for(int i=0; i<n; i++){
            bool found = true;
            for(int j=0; j<n; j++){
                if(goal[(i+j)%n] != s[j]){
                    found = false;
                }
            }
            if(found){
                return true;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

// Method 1 (Loop, O(n)):

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        char c1, c2;
        int diff = 0;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                if(diff == 0){
                    c1 = s1[i];
                    c2 = s2[i];
                    diff++;
                } else if(diff == 1){
                    if(s1[i] != c2 or s2[i] != c1){
                        return false;
                    }
                    diff++;
                } else {
                    return false;
                }
            }
        }
        return diff % 2 == 0;
    }
};

// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

// Method 1 (2 pointer, O(n+m));

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        int p1 = 0, p2 = 0;
        while(p1 < n1 and p2 < n2){
            if(s[p1] == t[p2]){
                p2++;
            }
            p1++;
        }
        return n2-p2;
    }
};

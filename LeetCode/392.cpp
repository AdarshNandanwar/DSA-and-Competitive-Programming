// https://leetcode.com/problems/is-subsequence/

// Method 1 (2 Pointers, O(n+m)):

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        int p1 = 0, p2 = 0;
        while(p1<sLen and p2<tLen){
            if(s[p1] == t[p2]){
                p1++;
            }
            p2++;
        }
        return p1 == sLen;
    }
};
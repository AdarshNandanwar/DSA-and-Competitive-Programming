// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, bool> m;
        int p1 = 0, p2 = 0, max_len = 0;
        while(p2<n){
            if(m[s[p2]]){
                m[s[p1]] = false;
                p1++;
            } else {
                m[s[p2]] = true;
                p2++;
            }
            max_len = max(max_len, p2-p1);
        }
        return max_len;
    }
};
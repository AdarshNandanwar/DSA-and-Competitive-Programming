// https://leetcode.com/problems/count-binary-substrings/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, prev_len = 0, prev = -1, cur_len = 0;
        for(int c:s){
            if(c-'0' != prev){
                prev = c-'0';
                prev_len = cur_len;
                cur_len = 0;
            }
            cur_len++;
            if(prev_len >= cur_len) ans++;
        }
        return ans;        
    }
};
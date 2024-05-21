// https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/

// Method 1 (O(n)):

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> firstIndex(26, -1);
        int n = s.length();
        int res = -1;
        for(int i=0; i<n; i++){
            if(firstIndex[s[i]-'a'] != -1){
                res = max(res, i-firstIndex[s[i]-'a']-1);
            } else {
                firstIndex[s[i]-'a'] = i;
            }
        }
        return res;
    }
};
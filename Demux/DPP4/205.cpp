// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        vector<int> m(128, -1);
        vector<bool> allotted(128, false);
        for(int i=0; i<n; i++){
            if(m[s[i]] == -1){
                if(!allotted[t[i]]){
                    allotted[t[i]] = true;
                    m[s[i]] = t[i];
                } else {
                    return false;
                }
            } else {
                if(m[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};
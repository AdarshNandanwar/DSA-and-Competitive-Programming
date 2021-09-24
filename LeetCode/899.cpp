// https://leetcode.com/problems/orderly-queue/

// Method 1 (Logic, O(n)):

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        for(int i = 0; i<s.length(); i++){
            s.push_back(s[0]);
            s.erase(s.begin());
            if(s < res) res = s;
        }
        return res;
    }
};
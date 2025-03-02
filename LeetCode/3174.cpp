// https://leetcode.com/problems/clear-digits/

// Method 1 (Loop, O(n)):

class Solution {
public:
    string clearDigits(string s) {
        reverse(s.begin(), s.end());
        string res;
        int toDelete = 0;
        for(char c:s){
            if(isdigit(c)){
                toDelete++;
            } else {
                if(toDelete){
                    toDelete--;
                } else {
                    res.push_back(c);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

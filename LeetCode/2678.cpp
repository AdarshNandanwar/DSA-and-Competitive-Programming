// https://leetcode.com/problems/number-of-senior-citizens/

// Method 1 (Loop, O(n)):

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniors = 0;
        for(const string & s:details){
            if(s[11] > '6' or (s[11] == '6' and s[12] > '0')){
                seniors++;
            }
        }
        return seniors;
    }
};

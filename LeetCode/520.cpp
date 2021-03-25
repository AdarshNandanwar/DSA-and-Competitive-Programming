// https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int i;
        istringstream iss(word);
        string s;
        while(getline(iss, s, ' ')){
            bool allUpper = ('A'<=s[0] and s[0]<='Z'), allLower = 1;
            for(int i =1; i<s.length(); i++){
                if('a'<=s[i] and s[i]<='z') allUpper = 0;
                else allLower = 0;
            }
            if(!allUpper and !allLower) return 0;
        }
        return 1;
    }
};
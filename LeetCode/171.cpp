// https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length(), res = 0;
        for(int i = n-1; i>=0; i--) res += ((s[i]-'A'+1)*pow(26, n-1-i));
        return res;
    }
};
// https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while(n){
            s.push_back('A'+(n-1)%26);
            n = (n-1)/26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
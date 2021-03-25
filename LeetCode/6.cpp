// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 0) return "";
        if(numRows == 1) return s;
        int sz = 2*numRows-2, n = s.length();
        string res = "";
        for(int r = 0; r<numRows; r++){
            for(int i = 0; i<n+sz; i += sz){
                if(0<=i-r and i-r<n and s[i-r] != '-'){
                    res.push_back(s[i-r]);
                    s[i-r] = '-';
                }
                if(i+r<n and s[i+r] != '-'){
                    res.push_back(s[i+r]);
                    s[i+r] = '-';
                }
            }
        }
        return res;
    }
};
// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int res = 0, maxNum = 0;
        for(int i = n-1; i>=0; i--){
            if(m[s[i]] >= maxNum) res += m[s[i]];
            else res -= m[s[i]];
            maxNum = max(maxNum, m[s[i]]);
        }
        return res;
    }
};
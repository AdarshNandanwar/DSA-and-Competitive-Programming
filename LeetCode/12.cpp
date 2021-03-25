// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        vector<string> mapping = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                                  "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                                  "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        return string(num/1000, 'M')+mapping[20+(num/100)%10]+mapping[10+(num/10)%10]+mapping[num%10];
    }
};
// https://www.interviewbit.com/problems/integer-to-roman/

string Solution::intToRoman(int A) {
    string s = "";
    vector<vector<string>> v = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    };
    for(int i = 0;; i++){
        if(!A) return s;
        s = v[i][A%10]+s;
        A /= 10;
    }
    return s;
}

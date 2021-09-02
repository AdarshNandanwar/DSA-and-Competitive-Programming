// https://leetcode.com/problems/reverse-integer/

// Method 1 (using only int):

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        bool sign = x>=0;
        int res = 0;
        x = abs(x);
        while(x){
            if(INT_MAX/10 < res or INT_MAX - x%10 < 10*res) return 0;
            res = 10*res + x%10;            
            x /= 10;
        }
        return sign ? res : -res;
    }
};
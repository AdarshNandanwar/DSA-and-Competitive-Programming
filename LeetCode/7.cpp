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

// Alternate Code:

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN){
            return 0;
        }
        
        bool sign = x>=0;
        x = abs(x);
        
        int ans = 0;
        while(x){
            int digit = x%10;
            
            // check if overflow
            if(INT_MAX/10 < ans or (INT_MAX/10 == ans and digit > INT_MAX%10)){
                return 0;
            }
            ans = 10*ans + digit;
            x /= 10;
        }
        return sign ? ans: -ans;
    }
};
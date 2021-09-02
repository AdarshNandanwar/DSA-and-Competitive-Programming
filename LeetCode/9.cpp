// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        int len = 0, temp = x;
        while(temp){
            len++;
            temp /= 10;
        }
        int lo = 1, hi = pow(10, len-1);
        while(lo<hi){
            if((x/lo)%10 != (x/hi)%10) return 0;
            lo *= 10;
            hi /= 10;
        }
        return 1;
    }
};
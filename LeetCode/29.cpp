// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -dividend;
        if(divisor == 0) return INT_MAX;

        int q = 0;
        bool isPos = (dividend>=0 == divisor>=0);
        long a = abs((long)dividend), b = abs((long)divisor);
        while(a >= b){
            int p = 0;
            // p: (1<<p) is the max number of times (power of 2) B can be removed from A
            while(a >= (b<<(p+1))) p++;
            q += (1<<p);
            a -= (b<<p);
        }
        return isPos ? q : -q;
    }
};
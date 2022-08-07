// https://leetcode.com/problems/divide-two-integers/

// Method 1 (O(1)):

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend<0) ^ (divisor<0);
        if(dividend == 0){
            return 0;
        }      
        if(divisor == INT_MIN){
            return dividend == INT_MIN;
        }
        
        bool addOne = false;
        if(dividend == INT_MIN){
            if(divisor == 1){
                return dividend;
            }
            dividend = INT_MAX;
            addOne = true;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        int quotient = 0;
        while(dividend >= divisor){
            int chunk = divisor;
            int power = 1;
            while((chunk<<1) >= chunk and dividend >= (chunk<<1)){
                // if not overflow
                chunk <<= 1;
                power <<= 1;
            }
            dividend -= chunk;
            quotient += power;
            
        }
        if(addOne and (dividend+1 == divisor)){
            if(quotient < INT_MAX){
                quotient++;
            }
        }
        return sign ? -quotient : quotient;
    }
};

// Method 2 (If long allowed, O(1)):

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
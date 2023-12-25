// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

// Method 1 (Bit Manipulation, O(n)):

#define MOD 1000000007
class Solution {
    int countBits(int n){
        int count = 0;
        while(n){
            count++;
            n >>= 1;
        }
        return count;
    }
public:
    int concatenatedBinary(int n) {
        int val = 0;
        for(int i=1; i<=n; i++){
            int bitCount = countBits(i);
            for(int j=bitCount-1; j>=0; j--){
                val = (2*val)%MOD;
                val = (val+((i>>j)&1))%MOD;
            }
        }
        return val;
    }
};
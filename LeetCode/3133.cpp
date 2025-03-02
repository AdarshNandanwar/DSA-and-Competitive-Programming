// https://leetcode.com/problems/minimum-array-end/

// Method 1 (Bit Manipulation, O(1)):

class Solution {
public:
    long long minEnd(int n, int x) {
        long long end = x;
        n--;
        long long pos = 0;
        for(long long i=0; (n>>i); i++){
            long long curBit = ((n>>i)&1);
            while((end>>pos)&1){
                pos++;
            }
            end |= (curBit<<pos);
            pos++;
        }

        return end;
    }
};

// https://leetcode.com/problems/complement-of-base-10-integer/

// Method 1 (Bit Manipulation, O(1)):

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int res = 0;
        for(int i=0; i<32 and (n>>i)>0; i++){
            if(((n >> i) & 1) == 0){
                res |= (1 << i);
            }
        }
        return res;
    }
};

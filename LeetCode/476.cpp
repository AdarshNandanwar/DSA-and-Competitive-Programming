// https://leetcode.com/problems/number-complement/

// Method 1 (Bit Manipulation, O(1)):

class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        for(int i=0; i<32 and (num>>i)>0; i++){
            if(((num >> i) & 1) == 0){
                res |= (1 << i);
            }
        }
        return res;
    }
};

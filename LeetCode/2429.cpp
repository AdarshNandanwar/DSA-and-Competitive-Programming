// https://leetcode.com/problems/minimize-xor/

// Method 1 (Bit Manipulation, O(n)):

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitCount1=0, bitCount2 = 0;
        for(int i=0; i<32; i++){
            if((num1>>i)&1){
                bitCount1++;
            }
            if((num2>>i)&1){
                bitCount2++;
            }
        }

        int bitCountDiff = abs(bitCount1 - bitCount2);
        if(bitCount1 > bitCount2){
            for(int i=0; i<32 and bitCountDiff>0; i++){
                if((num1>>i)&1){
                    num1 = (num1 & (~(1<<i)));
                    bitCountDiff--;
                }
            }
        } else {
            for(int i=0; i<32 and bitCountDiff>0; i++){
                if(((num1>>i)&1) == 0){
                    num1 = (num1 | (1<<i));
                    bitCountDiff--;
                }
            }
        }

        return num1;
    }
};

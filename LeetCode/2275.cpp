// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero

// Method 1 (Bit Manipulation, O(n)):

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(32, 0);
        for(int candidate:candidates){
            for(int i=0; i<32; i++){
                bitCount[i] += ((candidate>>i)&1);
            }
        }
        return *max_element(bitCount.begin(), bitCount.end());
    }
};

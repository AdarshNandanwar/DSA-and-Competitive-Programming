// https://leetcode.com/problems/neighboring-bitwise-xor/

// Method 1 (Bit Manipulation, O(n)):

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        // Let's assume we always have 0 in original[0]
        int prevBit = derived[0];
        derived[0] = 0;
        for(int i=1; i<n; i++){
            int curBit = derived[i];
            derived[i] = prevBit ^ derived[i-1];
            prevBit = curBit;
        }
        return derived[0] == prevBit ^ derived[n-1];
    }
};

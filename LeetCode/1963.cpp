// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

// Method 1 (Counter, O(n)):

class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int openCount = 0;
        int closeCount = 0;
        int swaps = 0;
        for(char c:s){
            if(c == '['){
                if(openCount < n/2){
                    // This must be swapped out as we can't close more. Assume this is ']'
                    openCount++;
                } else {
                    closeCount++;
                }
            } else {
                if(openCount > closeCount){
                    closeCount++;
                } else {
                    // Swap and assume this is '['
                    swaps++;
                    openCount++;
                }
            }
        }
        return swaps;
    }
};

// https://leetcode.com/problems/find-the-pivot-integer/

// Method 1 (Brute Force, O(n)):

class Solution {
public:
    int pivotInteger(int n) {
        int suffixSum = (n*(n+1))/2;
        int prefixSum = 0;
        for(int i=1; i<=n; i++){
            prefixSum += i;
            if(prefixSum == suffixSum){
                return i;
            }
            suffixSum -= i;
        }
        return -1;
    }
};
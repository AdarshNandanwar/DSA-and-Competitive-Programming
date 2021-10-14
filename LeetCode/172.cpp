// https://leetcode.com/problems/factorial-trailing-zeroes/

// Method 1 (faster, O(log5n)):

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int i=5; i<=n; i*=5) res += n/i;
        return res;
    }
};

// Method 2:

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int i = 5; i<=n; i++){
            for(int j = i; j%5 == 0; j /= 5) res++;
        }
        return res;
    }
};
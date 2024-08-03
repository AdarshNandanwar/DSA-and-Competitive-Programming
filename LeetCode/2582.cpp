// https://leetcode.com/problems/pass-the-pillow/

// Method 1 (Math, O(1)):

class Solution {
public:
    int passThePillow(int n, int time) {
        int mod = 2 * (n-1);
        int pos = (time % mod);
        int index = pos < n ? pos : mod - pos;
        return index + 1;
    }
};

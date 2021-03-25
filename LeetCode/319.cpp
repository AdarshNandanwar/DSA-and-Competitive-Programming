// https://leetcode.com/problems/bulb-switcher/

class Solution {
public:
    int bulbSwitch(int n) {
        // bulb i (1 indexed) is on if i has odd number of factors
        // only prefect squares have odd number of factors
        return sqrt(n);
    }
};
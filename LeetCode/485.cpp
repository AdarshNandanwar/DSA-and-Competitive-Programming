// https://leetcode.com/problems/max-consecutive-ones/

// Method 1 (O(n)):

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0, res = 0;
        for(auto &i:nums){
            if(i) cur++;
            else cur = 0;
            res = max(res, cur);
        }
        return res;
    }
};
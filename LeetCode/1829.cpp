// https://leetcode.com/problems/maximum-xor-for-each-query/

// Method 1 (Bit Manipulation, O(n)):

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask = (1<<maximumBit) - 1;
        vector<int> res;
        int n = nums.size();
        int curXor = 0;
        for(int i=0; i<n; i++){
            curXor ^= nums[i];
        }
        for(int i=n-1; i>=0; i--){
            res.push_back(curXor^mask);
            curXor ^= nums[i];
        }
        return res;
    }
};

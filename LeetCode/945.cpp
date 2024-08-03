// https://leetcode.com/problems/minimum-increment-to-make-array-unique/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), moves = 0, nextMin = 0;
        for(int i=0; i<n; i++){
            int cur = max(nums[i], nextMin);
            nextMin = 1 + cur;
            moves += (cur - nums[i]);
        }
        return moves;
    }
};

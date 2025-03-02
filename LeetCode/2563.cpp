// https://leetcode.com/problems/count-the-number-of-fair-pairs/

// Method 1 (Binary Search, O(nlogn)):

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long count = 0;
        for(int i=0; i<n; i++){
            int startIndex = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]) - nums.begin();
            int endIndex = lower_bound(nums.begin(), nums.begin() + i, upper - nums[i] + 1) - nums.begin();
            count += (endIndex - startIndex);
        }

        return count;
    }
};

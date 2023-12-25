// https://leetcode.com/problems/largest-perimeter-triangle/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size(), i = -1;
        sort(nums.begin(), nums.end());
        for(i=n-3; i>=0 and nums[i]+nums[i+1] <= nums[i+2]; i--);
        return i<0 ? 0 : nums[i]+nums[i+1]+nums[i+2];
    }
};
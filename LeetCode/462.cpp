// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

// Method 1 (Meeting Point, O(nlogn)):

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int i = 0, j = nums.size()-1, ans = 0;
        sort(nums.begin(), nums.end());
        while(i<j) ans += (nums[j--]-nums[i++]);
        return ans;
    }
};

// Method 2 (Median, O(nlogn)):

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(auto & i:nums) ans += (abs(i-nums[n/2]));
        return ans;
    }
};
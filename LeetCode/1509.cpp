// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

// Method 1 (Partial Sorting, O(n)):

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3){
            return 0;
        }

        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        vector<int> smallest4 = vector<int>(nums.begin(), nums.begin() + 4);
        partial_sort(nums.begin(), nums.begin() + 4, nums.end(), greater<int>());
        vector<int> largest4 = vector<int>(nums.begin(), nums.begin() + 4);
        
        return min(min(largest4[3]-smallest4[0], largest4[2]-smallest4[1]), min(largest4[1]-smallest4[2], largest4[0]-smallest4[3]));
    }
};

// Method 2 (Sorting, O(nlogn)):

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3){
            return 0;
        }
        sort(nums.begin(), nums.end());
        return min(min(nums[n-4]-nums[0], nums[n-3]-nums[1]), min(nums[n-2]-nums[2], nums[n-1]-nums[3]));
    }
};

// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int p1 = 0, p2 = n-1;
        while(p1<=p2 and nums[p1] < 0 and nums[p2] > 0){
            if(nums[p2] == -nums[p1]){
                return nums[p2];
            }
            if(nums[p2] < -nums[p1]){
                p1++;
            } else {
                p2--;
            }
        }
        return -1;
    }
};

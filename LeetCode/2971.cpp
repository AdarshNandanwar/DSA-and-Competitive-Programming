// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long runningSum = nums[0]+nums[1];
        long long res = -1;
        for(int i=2; i<n; i++){
            if(runningSum > nums[i]){
                res = runningSum + nums[i];
            }
            runningSum += nums[i];
        }
        return res;
    }
};

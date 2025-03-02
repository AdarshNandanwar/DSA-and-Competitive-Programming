// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// Method 1 (Loop, O(n)):

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool foundLesser = false;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                if(foundLesser){
                    return false;
                }
                foundLesser = true;
            }
        }
        if(foundLesser){
            return nums[0] >= nums[n-1];
        } else  {
            return true;
        }
    }
};

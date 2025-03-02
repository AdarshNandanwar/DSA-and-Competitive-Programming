// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/

// Method 1 (Loop, O(n)):

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int longestInc = 1, longestDec = 1;
        int curInc = 1, curDec = 1;
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                curInc++;
                curDec = 1;
            } else if(nums[i] < nums[i-1]){
                curInc = 1;
                curDec++;
            } else {
                curInc = 1;
                curDec = 1;
            }
            longestInc = max(longestInc, curInc);
            longestDec = max(longestDec, curDec);
        }

        return max(longestInc, longestDec);
    }
};

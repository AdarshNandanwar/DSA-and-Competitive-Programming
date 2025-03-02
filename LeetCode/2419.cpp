// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

// Method 1 (Loop, O(n)):

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int longestConsecutive = 0;
        int currentLength = 0;
        for(int num:nums){
            if(num == maxElement){
                currentLength++;
                longestConsecutive = max(longestConsecutive, currentLength);
            } else {
                currentLength = 0;
            }
        }

        return longestConsecutive;
    }
};

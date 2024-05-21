// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

// Method 1 (O(n) time, O(1) space):

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long prevLessMinK = -1, prevMoreMaxK = -1, prevMinK = -1, prevMaxK = -1;
        long long count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < minK){
                prevLessMinK = i;
            }
            if(nums[i] > maxK){
                prevMoreMaxK = i;
            }
            if(nums[i] == minK){
                prevMinK = i;
            }
            if(nums[i] == maxK){
                prevMaxK = i;
            }
            long long minLimit = max(prevLessMinK, prevMoreMaxK);
            long long maxLimit = min(prevMinK, prevMaxK);
            if(minLimit < maxLimit){
                count += (maxLimit - minLimit);
            }
        }
        return count;
    }
};

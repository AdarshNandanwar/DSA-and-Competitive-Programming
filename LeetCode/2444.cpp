// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

// Method 1 (O(n) time, O(1) space):

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int lastInvalidIndex = -1;
        int lastMinKIndex = -1;
        int lastMaxKIndex = -1;
        long long count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < minK or maxK < nums[i]){
                lastInvalidIndex = i;
            }
            if(nums[i] == minK){
                lastMinKIndex = i;
            }
            if(nums[i] == maxK){
                lastMaxKIndex = i;
            }

            /*

            Valid Subarrays:

            (lastInvalidIndex .. i]
            (lastInvalidIndex + 1 .. i]
            (lastInvalidIndex + 2 .. i]
            (lastInvalidIndex + 3 .. i]
            ...
            [min(lastMinKIndex, lastMaxKIndex) .. i]

            */

            int countEndingAtI = min(lastMinKIndex, lastMaxKIndex) - lastInvalidIndex;
            if(countEndingAtI > 0){
                count += countEndingAtI;
            }
        }
        
        return count;
    }
};

// Method 2 (O(n) time, O(1) space):

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

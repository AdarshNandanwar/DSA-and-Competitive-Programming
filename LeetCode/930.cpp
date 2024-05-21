// https://leetcode.com/problems/binary-subarrays-with-sum/

// Method 1 (2 Pointer, O(n) time, O(1) space):

class Solution {
    int numSubarraysWithSumLessThanEqualToGoal(const vector<int>& nums, int goal){
        int n = nums.size();
        int p1 = 0, p2 = 0;
        int sum = 0;
        int count = 0;
        // [p1..p2) represents subarray that has sum less than or equal to goal
        while(p2<n){
            sum += nums[p2];
            p2++;

            while(sum > goal){
                sum -= nums[p1];
                p1++;
            }

            // Add all subarrays ending at p2-1. These subarrays will have sum <= goal
            count += (p2-p1);
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal == 0){
            return numSubarraysWithSumLessThanEqualToGoal(nums, goal);
        }
        return numSubarraysWithSumLessThanEqualToGoal(nums, goal) - numSubarraysWithSumLessThanEqualToGoal(nums, goal-1);
    }
};

// Method 2 (Hash Map, O(n) time, O(n) space):

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        int prefixSum = 0;
        int count = 0;
        freq[0]++;
        for(int num:nums){
            prefixSum += num;
            if(prefixSum-goal >= 0){
                count += freq[prefixSum-goal];
            }
            freq[prefixSum]++;
        }
        return count;
    }
};
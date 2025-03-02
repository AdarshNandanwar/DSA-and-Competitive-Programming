// https://leetcode.com/problems/make-sum-divisible-by-p/

// Method 1 (Hash Map, O(n)):

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long sum = 0;
        for(auto num:nums){
            sum += num;
        }
        long mod = sum % p;
        if(mod == 0){
            return 0;
        }

        long minSubarrayLen = INT_MAX;
        
        unordered_map<long, long> lastMod; // {i, j} = Last index where we had mod == i
        lastMod[0] = -1;

        long runningSum = 0;
        for(long i=0; i<n; i++){
            runningSum += nums[i];
            long curMod = runningSum % p;
            long requiredMod = (curMod - mod + p) % p;
            if(lastMod.count(requiredMod) > 0){
                minSubarrayLen = min(minSubarrayLen, i - lastMod[requiredMod]);
            }
            lastMod[curMod] = i;
        }

        return minSubarrayLen == n ? -1 : minSubarrayLen;
    }
};

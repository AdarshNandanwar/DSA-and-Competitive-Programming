// https://leetcode.com/problems/continuous-subarray-sum/

// Method 1 (Hash Set, O(n)):

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> prevPrefixSumModulo;
        prevPrefixSumModulo.insert(0);
        int prevPrefixSum = 0;  // Ensures subarray length is atleast 2
        int prefixSum = nums[0];
        for(int i=1; i<n; i++){
            prefixSum += nums[i];
            
            int target = prefixSum % k;
            if(prevPrefixSumModulo.count(target)){
                return true;
            }

            prevPrefixSum += nums[i-1];
            prevPrefixSumModulo.insert(prevPrefixSum % k);
        }

        return false;
    }
};

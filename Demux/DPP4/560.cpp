// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        unordered_map<int, int> freq;
        freq[0]++;
        // cumulative sum
        for(int i = 0; i<n; i++){
            if(i>0) nums[i] += nums[i-1];
            count+=freq[nums[i]-k];
            freq[nums[i]]++;
        }
        return count;
    }
};
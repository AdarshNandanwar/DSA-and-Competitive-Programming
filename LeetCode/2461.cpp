// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

// Method 1 (2 pointers, O(n)):

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int p1 = 0, p2 = 0, n = nums.size();
        long long sum = 0, maxSum = 0;
        while(p2 < n){
            while(s.size() >= k or s.count(nums[p2])){
                s.erase(nums[p1]);
                sum -= nums[p1];
                p1++;
            }
            s.insert(nums[p2]);
            sum += nums[p2];
            p2++;
            if(s.size() == k){
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

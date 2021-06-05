// https://leetcode.com/problems/maximum-erasure-value/

// Method 1 (2 Pointer, Binary Vector):

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int p1 = 0, p2 = 0, n = nums.size(), max_sum = 0, sum = 0;
        vector<bool> v(10001, false);
        // subarray is [p1,p2]
        while(p2<n){
            while(v[nums[p2]]){
                sum -= nums[p1];
                v[nums[p1++]] = false;
            }
            sum += nums[p2];
            v[nums[p2++]] = true;
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};

// Method 1 (2 Pointer, Unordered Set):

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int p1 = 0, p2 = 0, n = nums.size(), max_sum = 0, sum = 0;
        unordered_set<int> s;
        // subarray is [p1,p2]
        while(p2<n){
            while(s.count(nums[p2])){
                sum -= nums[p1];
                s.erase(nums[p1++]);
            }
            sum += nums[p2];
            s.insert(nums[p2++]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};
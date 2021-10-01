// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

// Method 1 (Brute Force, O(4^n)):

class Solution {
public:
    
    bool helper(vector<int>& nums, vector<int> &subset_sum, int st, const int &target){
        int n = nums.size(), k = subset_sum.size();
        if(st == n) return true;
        for(int i=0; i<k; i++){
            if(subset_sum[i]+nums[st] > target) continue;
            subset_sum[i] += nums[st];
            if(helper(nums, subset_sum, st+1, target)) return true;
            subset_sum[i] -= nums[st];
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k != 0) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> subset_sum(k, 0);
        return helper(nums, subset_sum, 0, sum/k);
    }
};

// Method 2 (DFS):

class Solution {
public:
    
    void helper(vector<int> nums, int k, int target, int left, vector<int> visited, bool & ans, int start){
        if(target < 0){
            return;   
        }
        if(target == 0 && left == 0){
            ans = true;
            return;
        }
        if(left <= 0){
            return;
        }
        if(target == 0){
            target = k;
            start = 0;
        }
        for(int i = start; i<nums.size(); i++){
            if(i!=start && nums[i] == nums[i-1] && !visited[i-1]) continue;
            if(visited[i]) continue;
            visited[i] = true;
            helper(nums, k, target-nums[i], left-1, visited, ans, i+1);
            visited[i] = false;
        }
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = 0;
        int max_ele = INT_MIN;
        for(auto i:nums){
            sum += i;
            max_ele = max(max_ele, i);
        }
        if(sum%k || max_ele > sum/k) return false;
        bool ans = false;
        vector<int> visited(nums.size(), false);
        cout<<sum/k<<endl;
        sort(nums.begin(), nums.end());
        helper(nums, sum/k, sum/k, nums.size(), visited, ans, 0);
        return ans;
    }
};
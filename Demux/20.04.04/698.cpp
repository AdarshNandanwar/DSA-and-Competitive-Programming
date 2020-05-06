// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

// Method 1 (optimization by sorting and without using Map)

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

// Method 2 (Map optimization)

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
        unordered_map<int, int> mp;
        for(int i = start; i<nums.size(); i++){
            if(visited[i] || mp[nums[i]]) continue;
            mp[nums[i]]++;
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
        helper(nums, sum/k, sum/k, nums.size(), visited, ans, 0);
        return ans;
    }
};


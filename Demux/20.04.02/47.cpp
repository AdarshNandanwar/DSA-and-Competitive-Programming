// https://leetcode.com/problems/permutations-ii/

// Method 1 (Using Sets)

class Solution {
public:
    void helper(vector<int> nums, set<vector<int>> & ans, vector<int> cur, vector<bool> visited){
        if(cur.size() == nums.size()){
            ans.insert(cur);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(visited[i]) continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            helper(nums, ans, cur, visited);
            visited[i] = false;
            cur.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        set<vector<int>> ans;
        vector<int> cur;
        helper(nums, ans, cur, visited);
        vector<vector<int>> fans;
        for(auto i:ans){
            fans.push_back(i);
        }
        return fans;
    }
};

// Method 2 (Taking each element only once in each place)

class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> & ans, vector<int> cur, vector<bool> visited){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;
        }
        int prev = -1;
        unordered_map<int, bool> lm;
        for(int i = 0; i<nums.size(); i++){
            if(visited[i] || lm[nums[i]]) continue;
            visited[i] = true;
            lm[nums[i]] = true;
            cur.push_back(nums[i]);
            helper(nums, ans, cur, visited);
            visited[i] = false;
            cur.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> ans;
        vector<int> cur;
        helper(nums,  ans, cur, visited);
        return ans;
    }
};

// Method 3 (Without map or set)

class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> & ans, vector<int> cur, vector<bool> visited){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;
        }
        unordered_map<int, bool> lm;
        for(int i = 0; i<nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            if(visited[i]) continue;
            visited[i] = true;
            lm[nums[i]] = true;
            cur.push_back(nums[i]);
            helper(nums, ans, cur, visited);
            visited[i] = false;
            cur.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        helper(nums,  ans, cur, visited);
        return ans;
    }
};
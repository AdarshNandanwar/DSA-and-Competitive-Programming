// https://leetcode.com/problems/subsets/

// Method 1 (Recursion, O(2^n)):

class Solution {
public:
    void generateSubsets(const vector<int> & nums, const int & index, vector<int> & cur, vector<vector<int>> & ans){
        int n = nums.size();
        if(index == n){
            ans.push_back(cur);
            return;
        }
        generateSubsets(nums, index+1, cur, ans);
        cur.push_back(nums[index]);
        generateSubsets(nums, index+1, cur, ans);
        cur.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int index = 0;
        generateSubsets(nums, index, cur, ans);
        return ans;
    }
};
// https://leetcode.com/problems/subsets/

class Solution {
public:
    
    void helper(vector<int> nums, int index, vector<vector<int>> & ans){
        if(index == nums.size()){
            ans.push_back({});
            return;
        }
        helper(nums, index+1, ans);
        int n = ans.size();
        
        for(int i= 0; i<n; i++){
            vector<int> v = ans[i];
            v.push_back(nums[index]);
            ans.push_back(v);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
};
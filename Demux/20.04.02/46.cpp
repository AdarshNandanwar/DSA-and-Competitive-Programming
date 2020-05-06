// https://leetcode.com/problems/permutations/

class Solution {
public:
    
    void helper(vector<int> nums, vector<vector<int>> & ans, vector<int> cur, int * visited){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
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
    
    vector<vector<int>> permute(vector<int>& nums) {
        int * visited = new int[nums.size()];
        for(int i= 0; i< nums.size(); i++){
            visited[i] = false;
        }
        vector<vector<int>> ans;
        vector<int> cur;
        helper(nums, ans, cur, visited);
        return ans;
    }
};
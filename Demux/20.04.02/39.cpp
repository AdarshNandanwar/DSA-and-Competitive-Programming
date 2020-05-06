// https://leetcode.com/problems/combination-sum/

// Method 1

class Solution {
public:
    void helper(vector<int> candidates, int target, int index, vector<vector<int>> & ans, vector<int> curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target<0 || index >= candidates.size()){
            return;
        }
        // exclude 
        helper(candidates, target, index+1, ans, curr);
        // include
        curr.push_back(candidates[index]);
        helper(candidates, target-candidates[index], index, ans, curr);
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, target, 0, ans, curr);
        return ans;
    }
};

// Method 2

class Solution {
public:
    void helper(vector<int> candidates, int target, int index, vector<vector<int>> & ans, vector<int> curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target<0 || index >= candidates.size()){
            return;
        }
        for(int i = index; i<candidates.size(); i++){
            curr.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i, ans, curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, target, 0, ans, curr);
        return ans;
    }
};
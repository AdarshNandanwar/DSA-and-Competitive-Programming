// https://leetcode.com/problems/combination-sum-ii/

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
        int count = 1;
        for(int i = index+1; i<candidates.size(); i++){
            if(candidates[i] == candidates[i-1]) count++;
            else break;
        }
        for(int i = 0; i <= count; i++){
            if(i!=0) curr.push_back(candidates[index]);
            helper(candidates, target-i*candidates[index], index+count, ans, curr);
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
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
        for(int i = index; i < candidates.size(); i++){
            if(i!=index && candidates[i] == candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i+1, ans, curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, ans, curr);
        return ans;
    }
};
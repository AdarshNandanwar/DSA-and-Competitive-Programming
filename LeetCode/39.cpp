// https://leetcode.com/problems/combination-sum/

// Method 1 (Brute force recursion):

class Solution {
public:
    void generateCombination(const vector<int>& candidates, int index, int target, vector<vector<int>> & ans, vector<int>& cur, vector<int> & possible){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(index == candidates.size()){
            return;
        }
        if(target<0){
            return;
        }
        
        generateCombination(candidates, index+1, target, ans, cur, possible);
        
        cur.push_back(candidates[index]);
        generateCombination(candidates, index, target-candidates[index], ans, cur, possible);
        cur.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> possible(target+1, -1);
        sort(candidates.begin(), candidates.end());
        generateCombination(candidates, 0, target, ans, cur, possible);
        return ans;
    }
};
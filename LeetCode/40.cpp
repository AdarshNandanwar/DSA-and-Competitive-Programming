// https://leetcode.com/problems/combination-sum-ii/

// Method 1 (Recursion, Sorting Trick, O(2^n)):

class Solution {
public:
    void generateCombinations(const vector<int> & candidates, int start, int target, vector<vector<int>> & ans, vector<int> & cur){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(target < 0){
            return;
        }
        int n = candidates.size();
        if(start >= n){
            return;
        }
        for(int i=start; i<n; i++){
            if(i!=start and candidates[i]==candidates[i-1]){
                continue;
            }
            cur.push_back(candidates[i]);
            generateCombinations(candidates, i+1, target-candidates[i], ans, cur);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        generateCombinations(candidates, 0, target, ans, cur);
        return ans;
    }
};
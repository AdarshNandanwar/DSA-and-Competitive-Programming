// https://leetcode.com/problems/permutations/

// Method 1 (Recursion, O(n!)):

class Solution {
public:
    void generatePermutations(vector<int>& nums, unordered_set<int> & used, vector<vector<int>> & ans, vector<int> & cur){
        int n = nums.size();
        if(cur.size() == n){
            ans.push_back(cur);
            return;
        }
        for(auto &num:nums){
            if(used.count(num)){
                continue;
            }
            used.insert(num);
            cur.push_back(num);
            generatePermutations(nums, used, ans, cur);
            cur.pop_back();
            used.erase(num);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> used;
        vector<int> cur;
        generatePermutations(nums, used, ans, cur);
        return ans;
    }
};

// Alternate Code:

class Solution {
public:
    void generatePermutations(unordered_set<int> & remaining, vector<vector<int>> & ans, vector<int> & cur){
        if(remaining.empty()){
            ans.push_back(cur);
            return;
        }
        vector<int> candidates(remaining.begin(), remaining.end());
        for(auto &num:candidates){
            remaining.erase(num);
            cur.push_back(num);
            generatePermutations(remaining, ans, cur);
            cur.pop_back();
            remaining.insert(num);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> remaining(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        generatePermutations(remaining, ans, cur);
        return ans;
    }
};
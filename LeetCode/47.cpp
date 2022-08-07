// https://leetcode.com/problems/permutations-ii/

// Method 1 (Recursion, O(n!)):

class Solution {
    void generatePerm(const int & targetSize, unordered_map<int, int> & freq, vector<int> & cur, vector<vector<int>> & ans){
        int index = cur.size();
        if(index >= targetSize){
            ans.push_back(cur);
            return;
        }
        unordered_set<int> nums;
        for(auto & num:freq){
            nums.insert(num.first);
        }
        for(auto & num:nums){
            freq[num]--;
            if(freq[num] == 0){
                freq.erase(num);
            }
            cur.push_back(num);
            generatePerm(targetSize, freq, cur, ans);
            cur.pop_back();
            freq[num]++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size();
        unordered_map<int, int> freq;
        for(auto &i:nums){
            freq[i]++;
        }
        generatePerm(n, freq, cur, ans);
        return ans;
    }
};

// Method 2 (Recursion, O(n!)):

class Solution {
public:
    void generatePermutations(const int & n, unordered_map<int, int> & freq, vector<vector<int>> & ans, vector<int> & cur){
        if(cur.size() == n){
            ans.push_back(cur);
            return;
        }
        for(auto &i:freq){
            int num = i.first;
            int count = i.second;
            if(count){
                freq[num]--;
                cur.push_back(num);
                generatePermutations(n, freq, ans, cur);
                cur.pop_back();
                freq[num]++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto &num:nums){
            freq[num]++;
        }
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size();
        generatePermutations(n, freq, ans, cur);
        return ans;
    }
};
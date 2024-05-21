// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

// Method 1 (O(n)):

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        vector<vector<int>> res(0);
        for(int &i:nums){
            if(freq[i] >= res.size()){
                res.push_back({});
            }
            res[freq[i]].push_back(i);
            freq[i]++;
        }
        return res;
    }
};
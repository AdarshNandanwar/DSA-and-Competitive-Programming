// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> res(n/3);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            res[i/3].push_back(nums[i]);
            if(res[i/3].back() - res[i/3].front() > k){
                return vector<vector<int>>();
            }
        }
        return res;
    }
};
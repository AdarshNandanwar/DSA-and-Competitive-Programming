// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

// Method 1 (O(n)):

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), evenSum = 0;
        vector<int> res;
        for(int i=0; i<n; i++){
            if(nums[i]%2 == 0){
                evenSum += nums[i];
            }
        }
        for(auto &query:queries){
            int index = query[1];
            int diff = query[0];
            if(nums[index]%2 == 0){
                evenSum -= nums[index];
            }
            nums[index] += diff;
            if(nums[index]%2 == 0){
                evenSum += nums[index];
            }
            res.push_back(evenSum);
        }
        return res;
    }
};
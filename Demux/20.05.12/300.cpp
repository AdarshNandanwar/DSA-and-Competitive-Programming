// https://leetcode.com/problems/longest-increasing-subsequence/

// Method 1 (O(nlogn)):

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {

        // see discussion for explaination

        int n = nums.size();
        vector<int> tails;
        for(int i=0; i<n; i++){
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            if(it == tails.end())
                tails.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return tails.size();
    }
};

// Method 2 (O(n2)):

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int maxLIS = 1, n = nums.size();
        if(n == 0) return 0;
        // LIS ending at i
        vector<int> LIS(n, 1);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j]){
                    LIS[i] = max(LIS[i], 1+LIS[j]);
                }
            }
            maxLIS = max(maxLIS, LIS[i]);
        }
        return maxLIS;
    }
};
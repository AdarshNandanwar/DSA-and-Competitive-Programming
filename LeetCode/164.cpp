// https://leetcode.com/problems/maximum-gap/

// Method 1 (Bucket Sort):

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int min_ele = INT_MAX, max_ele = INT_MIN, n = nums.size();
        if(n<2){
            return 0;
        }
        for(auto i:nums){
            max_ele = max(max_ele, i);
            min_ele = min(min_ele, i);
        }
        int bucket_size = max(1, (max_ele-min_ele)/(n-1));
        int bucket_count = (max_ele-min_ele)/bucket_size +1;
        vector<int> maxV(bucket_count, INT_MIN), minV(bucket_count, INT_MAX);
        for(int i:nums){
            int bucket = (i-min_ele)/bucket_size;
            minV[bucket] = min(minV[bucket], i);
            maxV[bucket] = max(maxV[bucket], i);
        }
        int prev_max = -1, ans = 0;
        for(int i = 0; i<bucket_count; i++){
            if(maxV[i] == INT_MIN && minV[i] == INT_MAX){
                continue;
            }
            if(prev_max == -1){
                prev_max = maxV[i];
            } else {
                ans = max(ans, minV[i]-prev_max);
                prev_max = maxV[i];
            }
        }
        return ans;
    }
};

// Method 2 (Brute Force):

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-1; i++){
            res = max(res, nums[i+1]-nums[i]);
        }
        return res;
    }
};
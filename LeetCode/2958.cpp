// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

// Method 1 (2 Pointer, Sliding Window, O(n) time, O(1) space):

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int exceeded = 0;
        int p1 = 0, p2 = 0;
        int res = 0;
        // subarray [p1, p2)
        while(p2<n){
            freq[nums[p2]]++;
            if(freq[nums[p2]] == k+1){
                exceeded++;
            }
            p2++;
            while(exceeded){
                freq[nums[p1]]--;
                if(freq[nums[p1]] == k){
                    exceeded--;
                }
                p1++;
            }
            res = max(res, p2-p1);
        }
        return res;
    }
};
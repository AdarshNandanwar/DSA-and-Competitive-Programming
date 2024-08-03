// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

// Method 1 (Ordered Map, O(nlogn) time, O(n) space):

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int, queue<int>> freq;
        // [p1, p2)
        int p1 = 0, p2 = 0, len = 0;
        while(p2<n){
            freq[nums[p2]].push(p2);
            p2++;
            int range = prev(freq.end())->first - freq.begin()->first;
            while(p1<p2 and range>limit){
                freq[nums[p1]].pop();
                if(freq[nums[p1]].size() == 0){
                    freq.erase(nums[p1]);
                    range = prev(freq.end())->first - freq.begin()->first;
                }
                p1++;
            }
            len = max(len, p2-p1);
        }
        return len;
    }
};

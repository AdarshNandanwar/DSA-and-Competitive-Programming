// https://leetcode.com/problems/subarrays-with-k-different-integers/

// Method 1 (2 Pointers, O(n)):

class Solution {
    int subarraysWithAtmostKDistinct(const vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> freq;
        int distinct = 0;
        int p1 = 0, p2 = 0;
        int count = 0;
        while(p2<n){
            freq[nums[p2]]++;
            if(freq[nums[p2]] == 1){
                distinct++;
            }
            p2++;
            while(distinct > k){
                freq[nums[p1]]--;
                if(freq[nums[p1]] == 0){
                    distinct--;
                }
                p1++;
            }
            // add number of subarrays ending at p2-1 with number of distinct <= k
            count += (p2-p1);
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums, k-1);
    }
};
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

// Method 1 (2 Pointers, O(n) time, O(1) space):

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());
        long long numberOfSubarraysLess = 0;
        int p1 = 0, p2 = 0;
        int maxElementFreq = 0;
        // Count number of subarrays ending at p2 with max element freq < k
        while(p2<n){
            if(nums[p2] == maxElement){
                maxElementFreq++;
            }
            p2++;
            while(maxElementFreq >= k){
                if(nums[p1] == maxElement){
                    maxElementFreq--;
                }
                p1++;
            }
            numberOfSubarraysLess += (p2-p1);
        }
        long long numberOfSubarrays = (n*(n+1))/2;
        return numberOfSubarrays - numberOfSubarraysLess;
    }
};
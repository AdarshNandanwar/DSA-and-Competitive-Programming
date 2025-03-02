// https://leetcode.com/problems/count-number-of-bad-pairs/

// Method 1 (Hash Map, O(n) time, O(n) space):

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        // trackFreq[i] = number of elements till now in the track i.
        // Track i is the sequence of consecutive numbers that
        // start at index 0 with the number i.
        unordered_map<int, long long> trackFreq;

        long long badPairs = 0;
        for(int i=0; i<n; i++){
            int track = nums[i] - i;
            badPairs += (i - trackFreq[track]);
            trackFreq[track]++;
        }

        return badPairs;
    }
};

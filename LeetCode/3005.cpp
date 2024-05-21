// https://leetcode.com/problems/count-elements-with-maximum-frequency/

// Method 1 (Hash Map, O(n)):

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101);
        int maxFreq = 0;
        int maxFreqElementCount = 0;
        for(const int num:nums){
            freq[num]++;
            if(freq[num] == maxFreq){
                maxFreqElementCount += maxFreq;
            }
            if(freq[num] > maxFreq){
                maxFreq = freq[num];
                maxFreqElementCount = maxFreq;
            }
        }
        return maxFreqElementCount;
    }
};
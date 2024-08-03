// https://leetcode.com/problems/sort-array-by-increasing-frequency/

// Method 1 (Sorting, Lambda, O(nlogn) time, O(1) space):

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> freq(201, 0);
        int n = nums.size();
        for(int i=0; i<n; i++){
            freq[nums[i]+100]++;
        }
        sort(nums.begin(), nums.end(), [&freq](const int a, const int b){
            return freq[a+100] == freq[b+100] ? a > b : freq[a+100] < freq[b+100];
        });
        return nums;
    }
};

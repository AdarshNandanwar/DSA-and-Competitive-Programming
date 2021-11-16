// https://leetcode.com/problems/sort-colors/

// Method 1 (3 pointers, O(n) time, O(1) space):

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, p = 0;
        while(p <= hi){
            if(nums[p] == 0) swap(nums[p++], nums[lo++]);
            else if(nums[p] == 2) swap(nums[p], nums[hi--]);
            else p++;
        }
    }
};

// Method 2:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int * freq = new int[3]();
        for(auto i:nums){
            freq[i]++;
        }
        nums.clear();
        for(int i = 0; i<3; i++){
            while(freq[i]--){
                nums.push_back(i);
            }
        }
    }
};
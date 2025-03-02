// https://leetcode.com/problems/find-if-array-can-be-sorted/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bitCounts(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<32; j++){
                bitCounts[i] += (1&(nums[i]>>j));
            }
        }

        int start = 0;
        for(int i=1; i<n; i++){
            if(bitCounts[i] != bitCounts[i-1]){
                sort(nums.begin()+start, nums.begin()+i);
                start = i;
            }
        }
        sort(nums.begin()+start, nums.end());

        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                return false;
            }
        }

        return true;
    }
};

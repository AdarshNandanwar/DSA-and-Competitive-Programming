// https://leetcode.com/problems/sort-array-by-parity-ii/

// Method 1 (3 pointer, O(n)):

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int p = 0, po = 1, pe = 0, n = nums.size();
        while(p<n){
            if(p%2 == nums[p]%2){
                p++;
            } else {
                if(nums[p]%2){
                    swap(nums[p], nums[po]);
                    po += 2;
                } else {
                    swap(nums[p], nums[pe]);
                    pe += 2;
                }
            }
        }
        return nums;
    }
};
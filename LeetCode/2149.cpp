// https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Method 1 (Pointer, O(n) time, O(n) space):

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int ptr = 0;
        for(int i=0; i<n; i++){
            if(nums[i] >= 0){
                res[ptr] = nums[i];
                ptr += 2;
            }
        }
        ptr = 1;
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                res[ptr] = nums[i];
                ptr += 2;
            }
        }
        return res;
    }
};

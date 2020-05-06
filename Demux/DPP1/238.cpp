// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i<n; i++){
            ans[i] = ans[i-1]*nums[i-1];
        }
        for(int i = n-2; i>=0; i--){
            nums[i] *= nums[i+1];
            ans[i] *= nums[i+1];
        }
        return ans;
    }
};
// https://leetcode.com/problems/subarray-product-less-than-k/

// Method 1 (2 Pointer, Sliding Window, O(n) time, O(1) space):

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int product = 1;
        int p1 = 0, p2 = 0;
        int count = 0;
        // counting all arrays starting at p1 and ending at p1<=i<p2
        while(p1<n){
            while(p2<n and product*nums[p2]<k){
                product *= nums[p2];
                p2++;
            }
            count += (p2-p1);
            if(p1 == p2){
                p1++;
                p2 = p1;
            } else {
                product /= nums[p1];
                p1++;
            }
        }
        return count;
    }
};

// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), p1 = 0, p2 = 0;
        while(p2<n){
            if(nums[p2] != val) swap(nums[p1++], nums[p2++]);
            else p2++;
        }
        return p1;
    }
};
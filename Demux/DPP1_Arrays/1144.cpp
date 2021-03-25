// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, even = 0, left, right;
        
        for(int i = 0; i<n; i++){
            left = right = INT_MAX;
            if(i!=0) left = nums[i-1];
            if(i!=n-1) right = nums[i+1];
            if(nums[i]>=min(left, right)){
                if(i%2) odd += (nums[i]-min(left, right)+1);
                else even += (nums[i]-min(left, right)+1);
            }
        }
        
        return min(odd, even);
    }
};
// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(auto i:nums){
            if(i){
                nums[index] = i;
                index++;
            }
        }
        while(index<nums.size()){
            nums[index] = 0;
            index++;
        }
    }
};
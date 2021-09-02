// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0, i = 0;
        while(i<nums.size()){
            if(i == 0 or nums[i-1] != nums[i]) nums[pos++] = nums[i++];
            else i++;
        }
        return pos;
    }
};
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

// Method 1 (2 Pointers, O(n)):

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return nums.size();
        int p1 = 2, p2 = 2, prevPrev = nums[0], prev = nums[1];
        while(p2<n){
            if(prevPrev != nums[p2]) {
                nums[p1] = nums[p2];
                p1++;
            }
            prevPrev = prev;
            prev = nums[p2];
            p2++;
        }
        for(int i = 0; i<n-p1; i++) nums.pop_back();
        return p1;
    }
};
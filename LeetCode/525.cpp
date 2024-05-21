// https://leetcode.com/problems/contiguous-array/

// Method 1 (Hash Map, O(n)):

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> firstIndexWithBalance;
        firstIndexWithBalance[0] = n;
        int balance = 0;
        int maxArrLen = 0;
        for(int i=n-1; i>=0; i--){
            if(nums[i] == 0){
                balance--;
            } else {
                balance++;
            }

            if(firstIndexWithBalance.count(balance) != 0){
                maxArrLen = max(maxArrLen, firstIndexWithBalance[balance] - i);
            } else {
                firstIndexWithBalance[balance] = i;
            }
        }

        return maxArrLen;
    }
};
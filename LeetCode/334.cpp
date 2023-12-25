// https://leetcode.com/problems/increasing-triplet-subsequence/

// Method 1 (Prefix Min, O(n) time, O(1) space):

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // long is not needed as the conditoin for true is that 
        // the 3 numbers nust be strictly increasing,
        // which is not possible if the iValue or jValue is INT_MAX
        int iValueMin = INT_MAX, jValueMin = INT_MAX;
        for(auto &num:nums){
            if(num > jValueMin){
                return true;
            }
            if(num > iValueMin){
                jValueMin = min(jValueMin, num);
            }
            iValueMin = min(iValueMin, num);
        }
        return false;
    }
};
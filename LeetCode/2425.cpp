// https://leetcode.com/problems/bitwise-xor-of-all-pairings/

// Method 1 (Bit Manipulation, O(n+m)):

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int res = 0;
        if(n1 % 2 == 1){
            for(int i=0; i<n2; i++){
                res ^= nums2[i];
            }
        }
        if(n2 % 2 == 1){
            for(int i=0; i<n1; i++){
                res ^= nums1[i];
            }
        }
        return res;
    }
};

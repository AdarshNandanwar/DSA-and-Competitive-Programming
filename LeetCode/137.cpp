// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<long> bit(32, 0);
        for(auto i:nums){
            for(int j = 0; j<32; j++){
                bit[j] += ((bool)(i&(1<<j)));
            }
        }
        int res = 0;
        for(int i = 0; i<32; i++){
            res += (((bool)(bit[i]%3))<<i);
        }
        return res;
    }
};
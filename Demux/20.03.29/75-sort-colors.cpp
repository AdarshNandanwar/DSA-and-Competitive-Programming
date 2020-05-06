// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int * freq = new int[3]();
        for(auto i:nums){
            freq[i]++;
        }
        nums.clear();
        for(int i = 0; i<3; i++){
            while(freq[i]--){
                nums.push_back(i);
            }
        }
    }
};
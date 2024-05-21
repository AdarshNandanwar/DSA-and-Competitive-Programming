// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/

// Method 1 (Hash Map, O(n)):

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 1:-1, 2:1, 3:1, 4:2, 5:2, 6:2, 7:3, 8:3, 9:3
        unordered_map<int, int> freq;
        for(auto &i:nums){
            freq[i]++;
        }

        int operations = 0;
        for(auto& i:freq){
            if(i.second == 1){
                return -1;
            }
            operations += ((i.second+2)/3);
        }
        return operations;
    }
};
// https://leetcode.com/problems/total-hamming-distance/

// Method 1 (Bit Manipulation, O(32*n)):

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), res = 0, setBit = 0;
        for(int i = 0; i<32; i++){
            int setBit = 0;
            for(auto a:nums) setBit += ((a>>i)&1);
            res += (setBit*(n-setBit));
        }
        return res;
    }
};

// Method 2 (DP, O(32*n)):

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> freq(n+1, vector<int>(32, 0));
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<32; j++){
                freq[i][j] = (((bool)(nums[i]&(1<<j))) + freq[i+1][j]);
            }
        }
        int res = 0;
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<32; j++){
                if(nums[i]&(1<<j)) res += ((n-i-1)-freq[i+1][j]);
                else res += (freq[i+1][j]);
            }
        }
        return res;
    }
};
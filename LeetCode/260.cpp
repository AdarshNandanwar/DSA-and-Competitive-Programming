// https://leetcode.com/problems/single-number-iii/

// Method 1 (O(n) time, O(1) space):

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto i:nums) x ^= i;
        // finding last set bit of the xor
        // not zero as distinct numbers
        int lsbx = x&-x;
        // divide nums on the basis of the lsbx
        int x1 = 0, x2 = 0;
        for(auto i:nums) if(i&lsbx) x1 ^= i; else x2 ^= i;
        return {x1, x2};
    }
};

// Alternate Code:

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int pairXor = 0;
        for(int i=0; i<n; i++){
            pairXor ^= nums[i];
        }

        int differentBitPos = 0;
        while(((pairXor>>differentBitPos)&1) == 0){
            differentBitPos++;
        }

        int num1 = 0, num2 = 0;
        for(int i=0; i<n; i++){
            if(((nums[i]>>differentBitPos)&1) == 0){
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }
        
        return {num1, num2};
    }
};

// Method 2 (O(n) time, O(n) space):

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i:nums){
            if(s.count(i)) s.erase(i);
            else s.insert(i);
        }
        return vector<int>(s.begin(), s.end());
    }
};
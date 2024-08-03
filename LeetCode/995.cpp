// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

// Method 1 (Optimized Method 2/3 by re-using input space, O(n) time, O(1) space):

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        
        int flips = 0;
        int curFlips = 0;
        for(int i=0; i<n-(k-1); i++){

            if(i-k >= 0 and nums[i-k] == 2){
                // There was a flip operation at index i-k
                curFlips--;
            }
            int curValue = (nums[i] + curFlips)%2;

            if(curValue == 1){
                continue;
            }

            // Range Query operation
            nums[i] = 2;
            curFlips++;

            flips++;
        }

        for(int i=n-(k-1); i<n; i++){
            if(i-k >= 0 and nums[i-k] == 2){
                // There was a flip operation at index i-k
                curFlips--;
            }
            int curValue = (nums[i] + curFlips)%2;
            if(curValue == 0){
                return -1;
            }
        }
        return flips;
    }
};

// Method 2 (Range Query Operations, Method 3 with Queue instead of Vector, O(n) time, O(k) space):

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> reduceIndexes; // Prefix sum [0..i] of this vector gives the value that has been added to nums[i]

        int flips = 0;
        int curFlips = 0;
        for(int i=0; i<n-(k-1); i++){
            if(!reduceIndexes.empty() and reduceIndexes.front() == i){
                curFlips--;
                reduceIndexes.pop();
            }
            int curValue = (nums[i] + curFlips)%2;

            if(curValue == 1){
                continue;
            }

            // Range Query operation
            curFlips++;
            reduceIndexes.push(i+k);

            flips++;
        }

        for(int i=n-(k-1); i<n; i++){
            if(!reduceIndexes.empty() and reduceIndexes.front() == i){
                curFlips--;
                reduceIndexes.pop();
            }
            int curValue = (nums[i] + curFlips)%2;
            if(curValue == 0){
                return -1;
            }
        }
        return flips;
    }
};

// Method 3 (Range Query Operations, O(n) time, O(n) space):

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> delta(n+1); // Prefix sum [0..i] of this vector gives the value that has been added to nums[i]

        int flips = 0;
        int curFlips = 0;
        for(int i=0; i<n-(k-1); i++){

            curFlips += delta[i];
            int curValue = (nums[i] + curFlips)%2;

            if(curValue == 1){
                continue;
            }

            // Range Query operation
            delta[i] += 1; // Not required as this is never used again. But leaving for completeness.
            delta[i+k] -= 1;
            curFlips++;

            flips++;
        }

        for(int i=n-(k-1); i<n; i++){
            curFlips += delta[i];
            int curValue = (nums[i] + curFlips)%2;
            if(curValue == 0){
                return -1;
            }
        }
        return flips;
    }
};

// Method 4 (Brute Force, O(n2) time, O(1) space):

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        for(int i=0; i<n-(k-1); i++){
            if(nums[i] == 1){
                continue;
            }
            for(int j=i; j<i+k; j++){
                nums[j] ^= 1;
            }
            flips++;
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                return -1;
            }
        }
        return flips;
    }
};

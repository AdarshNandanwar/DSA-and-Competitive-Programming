// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

// Method 1 (Quick Select Algorithm, O(n) average, o(n2) worst case):

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int moves = 0;
        for(auto &i:nums){
            moves += abs(nums[n/2]-i);
        }
        return moves;
    }
};

// Method 2 (Median, O(nlogn)):

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(auto & i:nums) ans += (abs(i-nums[n/2]));
        return ans;
    }
};

// Method 3 (Meeting Point, O(nlogn)):

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int i = 0, j = nums.size()-1, ans = 0;
        sort(nums.begin(), nums.end());
        while(i<j) ans += (nums[j--]-nums[i++]);
        return ans;
    }
};
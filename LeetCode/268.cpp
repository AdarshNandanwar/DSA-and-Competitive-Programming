// https://leetcode.com/problems/missing-number/

// Method 1 (Bit Manipulation, XOR, O(n) time, O(1) space):

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorResult = n;
        for(int i=0; i<n; i++){
            xorResult ^= nums[i];
            xorResult ^= i;
        }
        return xorResult;
    }
};

// Method 2 (Sum, O(n) time, O(1) space):

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        for(auto &num:nums){
            sum -= num;
        }
        return sum;
    }
};

// Method 3 (Hash Table, O(n) time, O(n) space):

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i=0; i<=n; i++){
            if(s.count(i) == 0){
                return i;
            }
        }
        return -1;
    }
};

// Method 4 (Binary Search, O(nlogn) time, O(1) space):

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // nums[mid] == mid
        // TF First F
        int lo = 0, hi = n-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid] == mid){
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        if(nums[lo] == lo){
            return n;
        } else {
            return lo;
        }
    }
};
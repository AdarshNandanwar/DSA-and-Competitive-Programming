// https://leetcode.com/problems/sort-array-by-parity/

// Method 1 (2 pointers, O(n)):

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int lo=0, hi=n-1;
        while(lo<hi){
            if(nums[lo]%2 == 1){
                swap(nums[lo], nums[hi]);
                hi--;
            } else {
                lo++;
            }
        }
        return nums;
    }
};

// Alternate Code:

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size(), p1 = 0, p2 = n-1;
        while(p1<p2){
            while(p1<n and A[p1]%2 == 0) p1++;
            while(p2>=0 and A[p2]%2 == 1) p2--;
            if(p1<p2) swap(A[p1++], A[p2--]);
        }
        return A;
    }
};
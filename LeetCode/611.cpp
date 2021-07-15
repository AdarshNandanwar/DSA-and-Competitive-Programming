// https://leetcode.com/problems/valid-triangle-number/

// Method 1 (2 Pointers, O(n2)):

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 2; i<nums.size(); i++){
            int p1 = 0, p2 = i-1;
            while(p1<p2){
                if(nums[p1]+nums[p2] > nums[i]){
                    res += (p2-p1);
                    p2--;
                } else {
                    p1++;
                }
            }
        }
        return res;
    }
};

// Method 2 (2 Pointers, Binary Search, O(n*n*logn)):

class Solution {
public:
    int triangleNumber(vector<int>& A) {
        int n = A.size(), i = 0, j = n-1, res = 0;
        sort(A.begin(), A.end());
        for(int i = 1; i<n-1; i++){
            for(int j = 0; j<i; j++){
                res += ((upper_bound(A.begin()+i+1, A.end(), A[j]+A[i]-1)-A.begin())-i-1);
            }
        }
        return res;
    }
};
// https://leetcode.com/problems/squares-of-a-sorted-array/

// Method 1 (2 Pointer, O(n)):

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int index = n-1;
        vector<int> res(n);
        while(index >= 0){
            if(-nums[left] < nums[right]){
                res[index] = nums[right]*nums[right];
                right--;
            } else {
                res[index] = nums[left]*nums[left];
                left++;
            }
            index--;
        }
        return res;
    }
};

// Alternate Code:

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {        
        int n = A.size();
        int lb = lower_bound(A.begin(), A.end(), 0)-A.begin();
        int i = lb-1, j = lb;
        vector<int> res;
        while(i>=0 and j<n){
            if(A[i]*A[i] >= A[j]*A[j]){
                res.push_back(A[j]*A[j]);
                j++;
            } else {
                res.push_back(A[i]*A[i]);
                i--;
            }
        }
        while(i>=0){
            res.push_back(A[i]*A[i]);
            i--;
        }
        while(j<n){
            res.push_back(A[j]*A[j]);
            j++;
        }
        return res;
    }
};

// Method 2 (Sorting, O(nlogn)):

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto & i:A) i = i*i;
        sort(A.begin(), A.end());
        return A;
    }
};
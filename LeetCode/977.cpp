// https://leetcode.com/problems/squares-of-a-sorted-array/

// Method 1 (binary search, O(n+logn)):

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

// Method 2 (sorting, O(nlogn)):

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto & i:A) i = i*i;
        sort(A.begin(), A.end());
        return A;
    }
};
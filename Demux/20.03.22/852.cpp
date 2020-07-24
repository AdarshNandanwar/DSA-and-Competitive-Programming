// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
                // FFFFFTTT
        // p(x): A[i] < A[i-1]
        // Last F
        
        int n = A.size(), lo, hi, mid;
        lo = 1, hi = n-2;
        while(lo < hi){
            mid = lo+(hi-lo+1)/2;
            if(A[mid] < A[mid-1])
                hi = mid-1;
            else 
                lo = mid;
        }
        // if(!(A[lo] < A[lo-1]))
            return lo;
        // else
        //     return lo-1;
    }
};
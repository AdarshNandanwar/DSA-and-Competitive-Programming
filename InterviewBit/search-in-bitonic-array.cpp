// https://www.interviewbit.com/problems/search-in-bitonic-array/

// Method 1 (Binary Search, O(logn)):

int Solution::solve(vector<int> &A, int B) {
    int lo, hi, mid, n = A.size();
    
    // bitonic point
    // FT last F
    lo = 1, hi = n-1;
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(A[mid-1]>=A[mid]){
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    int bp = lo;
    
    // finding in 1st half
    // FT last F
    lo = 0, hi = bp;
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(B<A[mid]){
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    if(A[lo] == B) return lo;
    
    // finding in 2nd half
    // FT last F
    lo = bp+1, hi = n-1;
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(B>A[mid]){
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    if(A[lo] == B) return lo;
    
    return -1;
}

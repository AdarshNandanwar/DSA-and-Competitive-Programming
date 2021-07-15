// https://www.interviewbit.com/problems/search-for-a-range/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // return {lower_bound(A.begin, A.end(), B)-A.begin(), lower_bound(A.begin, A.end(), B)-A.begin()};
    int n = A.size(), lo, hi, mid;
    if(n == 0) return {-1, -1};
    if(n == 1 and A[0] == B) return {0, 0}; 
    
    // FT first T
    lo = 0; hi = n-1;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(B <= A[mid]){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(A[lo] != B) return {-1, -1};
    int st = lo;
    // FT first T
    lo = 0; hi = n-1;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(B < A[mid]){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(B < A[lo]){
        return {st, lo-1};
    } else {
        return {st, n-1};
    }
}

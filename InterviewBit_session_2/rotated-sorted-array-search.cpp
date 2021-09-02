// https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &A, int B) {
    int n = A.size(), pivot = 0;
    if(n <= 0) return -1;
    // FT first T
    int lo = 0, hi = n-1, mid;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(A[mid]<A[0]){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(A[lo] < A[0]){
        pivot = lo;
    }
    
    // FT first T
    lo = 0; hi = n-1;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(B <= A[(mid+pivot)%n]){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(A[(lo+pivot)%n] == B){
        return (lo+pivot)%n;
    } else {
        return -1;
    }
}

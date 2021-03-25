// https://www.interviewbit.com/problems/rotated-sorted-array-search/

// Method 1 (Binary Search, O(logn)):

int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    if(n == 0) return -1;
    if(n == 1) return A[0] == B ? 0 : -1;
    
    // binary search for pivot
    int lo = 0, hi = n-1, mid, pivot;
    while(lo < hi){
        mid = lo+(hi-lo)/2;
        if(A[0] > A[mid]){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(A[0] > A[lo]) pivot = lo;
    else pivot = 0;
    
    // binary search for B
    lo = 0, hi = n-1;
    while(lo < hi){
        mid = lo+(hi-lo)/2;
        if(B <= A[(mid+pivot)%n]){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(B == A[(lo+pivot)%n]) return (lo+pivot)%n;
    else return -1;
}

// Method 2 (O(n)):

int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    for(int i = 0; i<n; i++) if(A[i] == B) return i;
    return -1;
}

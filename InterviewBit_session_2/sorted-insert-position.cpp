// https://www.interviewbit.com/problems/sorted-insert-position/

int Solution::searchInsert(vector<int> &A, int B) {
    return lower_bound(A.begin(), A.end(), B)-A.begin();
}

// Alternate Code

int Solution::searchInsert(vector<int> &A, int B) {
    // FT first T
    int lo = 0, hi = A.size()-1, mid;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(B <= A[mid]){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(B <= A[lo]) return lo;
    return A.size();
}

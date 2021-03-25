// https://www.interviewbit.com/problems/matrix-search/

// Method 1 (Binary Search, O(log(n*m))):

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    if(n == 0) return 0;
    // FT first T
    int m = A[0].size(), lo = 0, hi = n*m-1, mid, r, c;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        r = mid/m;
        c = mid%m;
        if(A[r][c] >= B){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    return A[lo/m][lo%m] == B;
}

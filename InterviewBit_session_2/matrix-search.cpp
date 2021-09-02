// https://www.interviewbit.com/problems/matrix-search/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size(), m = A[0].size();
    // TF last T
    int lo = 0, hi = n-1, mid;
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(A[mid][0] <= B){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    int row = lo;
    // TF last T
    lo = 0; hi = m-1;
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(A[row][mid] <= B){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return A[row][lo] == B;
}

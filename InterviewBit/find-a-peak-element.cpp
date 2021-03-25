// https://www.interviewbit.com/problems/find-a-peak-element/

int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    if(n == 1) return A[0];
    
    int lo = 1, hi = n-1, mid;
    
    // fffttt   last f
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(A[mid-1] > A[mid]){
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    if(!(A[lo-1] > A[lo])) return A[lo];
    else return A[0];
    
}

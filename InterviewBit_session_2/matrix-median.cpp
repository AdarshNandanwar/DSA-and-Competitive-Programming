// https://www.interviewbit.com/problems/matrix-median/

long long count_lower(vector<vector<int> > &A, long long x){
    long long res = 0;
    for(int i = 0; i<A.size(); i++){
        res += (lower_bound(A[i].begin(), A[i].end(), x)-A[i].begin());
    }
    return res;
}

int Solution::findMedian(vector<vector<int> > &A) {
    // TF last T
    long long lo = 1, hi = 1000000000, mid, n = A.size(), m = A[0].size();
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(count_lower(A, mid) <= (n*m)/2){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return lo;
}

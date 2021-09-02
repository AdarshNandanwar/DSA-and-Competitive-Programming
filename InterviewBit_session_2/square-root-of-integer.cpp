// https://www.interviewbit.com/problems/square-root-of-integer/

int Solution::sqrt(int A) {
    // TF last T
    long long hi = A, lo = 0, mid;
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(mid*mid <= A){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return lo;
}

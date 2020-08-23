// https://www.interviewbit.com/problems/square-root-of-integer/

// Method 1 (Binary Search, O(logn)):

typedef long long int ll;

int Solution::sqrt(int A) {
    // TF, first true
    ll lo = 0, hi = A, mid;
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(mid*mid<=A){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return lo;
}

// https://www.interviewbit.com/problems/sorted-insert-position/

// Method 1 (binary search, O(logn)):

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return lower_bound(A.begin(), A.end(), B)-A.begin();
}

// Method 2 (binary search, O(logn)):

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // FT first T, A[mid]>=B
    int lo = 0, hi = A.size()-1, mid;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(A[mid]>=B){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    return A[lo]>=B ? lo : A.size();
}

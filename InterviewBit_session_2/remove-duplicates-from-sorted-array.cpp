// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

// Method 1 (2 Pointers, O(n)):

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size(), p1 = 0, p2 = 1;
    if(n == 0) return 0;
    while(p2<n){
        if(A[p1] == A[p2]) p2++;
        else A[++p1] = A[p2++];
    }
    return p1+1;
}
